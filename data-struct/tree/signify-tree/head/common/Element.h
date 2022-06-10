/**
 * Created by Rui on 2022/6/10.
 */

#ifndef SIGNIFY_TREE_ELEMENT_H
#define SIGNIFY_TREE_ELEMENT_H

#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 255
#define MAX_SIZE 1024

typedef struct ElementType{
    int id;
    char name[NAME_SIZE];
}ElementType;

#endif //SIGNIFY_TREE_ELEMENT_H
