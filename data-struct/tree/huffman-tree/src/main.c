#include "../head/HuffmanTree.h"

/** 保存到二进制文件的无符号字符 */
//char类型占1个字节，8位。默认char类型是有符号的，保存在文件中时符号位会干扰本程序的编码解码
//所以设置实际保存的字符为无符号的字符类型
unsigned char saveChar = 0;
unsigned char tempChar;
int main()
{
    printf("使用赫夫曼树实现文件的压缩：\n");
    FILE * inputFile = fopen("/Users/CWorkSpace/c-learning/data-struct/tree/huffman-tree/src/input.txt", "r");     //待读取的文件
    FILE * zipedFile = fopen("zip.zip", "wb");      //编码压缩后的文件

    int fileLength = 0;                             //文件中的字符个数
    int asciiCount[ASCII_SIZE] = {0};               //存放0-127每个字符出现的次数-权数组
    char readChar;                                  //读取的字符
    //读取待编码的文件
    while((readChar = fgetc(inputFile)) != EOF){
        fileLength++;                               //统计文件中的字符个数
        //每个字符出现的次数+1
        //读取到的readChar作为数组下标
        asciiCount[readChar-0]++; //asciiArray[(int)readChar]++;
    }
    printf("fileLength:%d",fileLength);
    //统计每个ASCII码数组中字符出现的次数作为权值
    int num = 0;                                    //结点数量
    for(int i = 0; i < ASCII_SIZE; i++){
        if(asciiCount[i] != 0){
            nodes[num].data = i;                     //结点数据就是某个ASCII码值
            nodes[num].weight = asciiCount[i];       //asciiCount[i]为字符出现的次数
            num++;
        }
    }
    //创建Haffman树
    createHuffTree(nodes, num);
    ///哈夫曼编码：左子树替换为0，右子树替换为1，使用串的顺序存储
    char haffCode[HALF_MAX];        //用来保存每次从根到叶结点遍历的编码(编码的过渡数组)
    num = 0;                        //计数器清零
    coding(&nodes[0], haffCode, 0);  //进行编码
//    return;
    fseek(inputFile, 0L, 0);        //指针复位到文件起始位置
    int zipLength = 0;              //压缩后的文件长度（字符个数）
    //再次读取inputFile，根据编码逐位保存到文件中
    while((readChar = fgetc(inputFile)) != EOF){//再次逐个字符读取文件
        //遍历读取到的这个字符的编码，如111, 1100等
        for(int i = 0; i < strlen(code[readChar - 0]); i++){
            //将saveChar与编码中的每一位进行或操作，用字符'1'-'0'就可以得到0000 0001
            //'1'-'0'就可以得到0000 0001, '0'-'0'可以得到  0000 0000
            //当编码为'1',通过或操作将其添加到字节的最低位
            saveChar |= code[readChar - 0][i] - '0';
            num++;
            if(num == 8){           //每8位写入一次文件
                fwrite(&saveChar, sizeof(unsigned char), 1, zipedFile);
                zipLength++;
                saveChar = 0;       //保存字符置零
                num = 0;
            }else{
                saveChar = saveChar << 1;   //每做完一步，向左移一位
            }
        }
    }
    //如果最后剩余的编码不足8位，将其移到最左端
    if(num < 8){
        saveChar = saveChar << (8 - num);
        fwrite(&saveChar, sizeof(unsigned char), 1, zipedFile);
        zipLength++;
        printf("\n最后剩余的编码不足8位，将其移到最左端\n");
    }
    fclose(inputFile);
    fclose(zipedFile);
    printf("压缩成功！压缩前大小：%d, 压缩后大小：%d\n", fileLength, zipLength);
    //文件压缩后的大小与压缩前的大小之比
    printf("压缩率：%.2lf%%\n", (double)zipLength / fileLength * 100);
    printf("zipLength:%d",zipLength);

    printf("使用赫夫曼树实现文件的解压缩：\n");
    FILE * zipedFile1 = fopen("zip.zip", "rb");         //读取压缩后的文件（二进制读取）
    FILE * resultFile = fopen("result.txt", "w");      //解压后的文件
    //主要思想是根据编码遍历赫夫曼树
    num = 0;
    char op;    //解压缩用到的
    HuffNode * currNode = &nodes[0];
    while(fread(&readChar, sizeof(unsigned char), 1, zipedFile1)){
        //如果解压缩的长度等于原文长度，停止解压缩
        //因为在编码压缩的时候可能出现剩余的编码不足8位的情况
        //不足8位补成8位后，后面的补位可能会造成干扰
        if(fileLength <= num){//最后一个字符在编码解码时存在bug，表现在解压缩文件的最后一位随机字符
            break;
        }
        op = 128;   //1000 0000
        for(int i = 0; i < 8; i++){
            tempChar = readChar & op;
            tempChar = tempChar >> 7;   //取tempChar/readChar的最高位作为unzip的flag
            readChar = readChar << 1;
            currNode = decoding(currNode, tempChar-0);
            if(currNode->left == NULL || currNode->right == NULL){
                fprintf(resultFile, "%c", currNode->data);
                //fwrite(currNode->data, sizeof(unsigned char), 1, resultFile);
                num++;      //每写入一个字符，num+1
                currNode = &nodes[0];        //每找到一个叶结点，便将当前结点指向根结点
            }
        }
    }
    printf("num:%d",num);
    fclose(zipedFile1);
    fclose(resultFile);
    printf("解压缩完成！请查看result.txt\n");
    return 0;

}
