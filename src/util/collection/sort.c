//
// Created by Mauguin on 2022/4/27.
//
#include <memory.h>
#include "sort.h"
#include "stdlib.h"

static void
sort_insert(void *array, int element_size, int left, int right,
            int (*compare)(const void *, const void *)) {
    char *temp = malloc(element_size);
    for (; left <= right; ++left) {
        memcpy(temp, (char *) array + element_size * left, element_size);
        int j;
        for (j = left - 1; j >= 0; --j) {
            char *j_address = (char *) array + element_size * j;
            if (compare(j_address, temp) > 0) {
                memcpy((char *) array + element_size * (j + 1), j_address, element_size);//先后覆盖
            } else
                break;
        }
        if (j != (left - 1)) {
            memcpy((char *) array + element_size * (j + 1), temp, element_size);
        }
    }
    free(temp);
    temp = NULL;
}

static void swap(char *a, char *b, int element_size) {
    char *temp = malloc(element_size * sizeof(char));
    memcpy(temp, a, element_size);
    memcpy(a, b, element_size);
    memcpy(b, temp, element_size);
    free(temp);
}

static void sort_quick(void *array, int element_size, int left, int right,
                       int (*compare)(const void *, const void *)) {
    if (left < right) {
        if ((right - left) <= 10) {
            sort_insert(array, element_size, left, right, compare);
            return;
        }
        int i = left, j = right, pivot = left + ((right - left) >> 1);
        //char *pivot_address = (char *) array + element_size * pivot;
        char *temp = malloc(element_size);
        memcpy(temp, array + element_size * pivot, element_size);
        char *i_address = (char *) array + element_size * i;
        char *j_address = (char *) array + element_size * j;
        while (i < j) {
            while (i < j && compare(j_address, temp) > 0) {
                --j;
                j_address -= element_size;
            }
            while (i < j && compare(i_address, temp) <= 0) {
                ++i;
                i_address += element_size;//移动i指针位置
            }
            if (i < j) {
                /*
                 * 记录 pivot_address 防止变换后找不到这个指针记录下
                 *  if (j_address == pivot_address) {
                 *      pivot_address = i_address;
                 *  } else if (i_address == pivot_address) {
                 *      pivot_address = j_address;
                 *  }
                 */

                swap(i_address, j_address, element_size);
            }
        }
        /*
         * 将基准数放置正确的位置
         */
        //swap(j_address, pivot_address, element_size);
        //free(temp);
        //temp = NULL;
        sort_quick(array, element_size, left, j, compare);
        sort_quick(array, element_size, j + 1, right, compare);
    }

}


void sort_list(void *array, int element_size, int len, int (*compare)(const void *, const void *)) {
    sort_quick(array, element_size, 0, len - 1, compare);
}
