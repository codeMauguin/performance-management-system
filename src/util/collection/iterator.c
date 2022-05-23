//
//  iterator.c
//  student
//
//  Created by Mauguin on 2022/4/29.
//

#include "iterator.h"

Iterator *createIterator(void *data, unsigned int element_size, unsigned int len) {
    Iterator *it = malloc(sizeof(Iterator));
    it->data = data;
    it->idx = 0;
    it->element_size = element_size;
    it->hasNext = (len >= element_size) ? 1 : 0;
    it->len = len;
    return it;
}

void *iteratorNext(Iterator *it) {
    if (it->hasNext == 0)return NULL;
    void *data = (char *) it->data + it->element_size * it->idx;
    ++it->idx;
    it->hasNext = (it->len >= it->element_size * it->idx) ? 1 : 0;
    return data;
}

void iteratorReset(Iterator *it) {
    it->idx = 0;
    it->hasNext = (it->len >= it->element_size) ? 1 : 0;
}
