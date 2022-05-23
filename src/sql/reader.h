//
// Created by Mauguin on 2022/4/27.
//

#ifndef TEST_READER_H
#define TEST_READER_H

#include "file.h"

typedef struct {
    char *key;
    char *value;
} map;


/**
 * 读取数据
 * 一行不要超过1024个字节，否则读取错误
 */
LinkList *readerFile(char *);

/**
 * 切割函数
 * @param src 待切割的数据
 * @param separator 切割符号
 * @return
 */
LinkList *spit(char *src, char *separator);

#endif //TEST_READER_H
