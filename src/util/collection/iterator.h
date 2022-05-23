//
//  iterator.h
//  student
//
//  Created by Mauguin on 2022/4/29.
//

#ifndef iterator_h
#define iterator_h

#include <stdlib.h>

typedef struct {
    void *data;
    int element_size;
    int idx;
    int hasNext;
    int len;
} Iterator;

/**
 * 创建迭代器
 *
 */
Iterator *createIterator(void *, unsigned int element_size, unsigned int len);

void *iteratorNext(Iterator *it);

void iteratorReset(Iterator *it);

#endif /* iterator_h */
