//
// Created by Mauguin on 2022/4/27.
//
#include "reader.h"
#include <stdio.h>
#include "string.h"


LinkList *readerFile(char *file_name) {
    LinkList *myFile = createList();
    FILE *read;
    read = fopen(file_name, "r");
    if (NULL == read) {
        printf("File is not found!");
        return NULL;
    } else {
        int row = 0;
        char buffer[BUFSIZ];//一次读取最大缓冲1024;
        char *content;
        while (!feof(read) && NULL != fgets(buffer, BUFSIZ, read)) {
            content = malloc(sizeof(char) * strlen(buffer) + 1);
            strcpy(content, buffer);
            struct data *data = createData(content, row++);
            inset_next(myFile, data);
        }
    }
    return myFile;
}

LinkList *spit(char *src, char *separator) {
    if (src == NULL || strlen(src) == 0 || separator == NULL || strlen(separator) == 0)return NULL;
    char *next;
    next = strtok(src, separator);
    LinkList *list = createList();
    int index = 0;
    while (NULL != next) {
        struct data *data = createData(next, index++);
        inset_next(list, data);
        next = strtok(NULL, separator);
    }
    return list;
}


