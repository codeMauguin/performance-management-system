//
// Created by Mauguin on 2022/4/27.
//
#ifndef TEST_SORT_H
#define TEST_SORT_H

/**
 *
 * 数据小于10 则使用插排进行优化
 * 如果不需要插入排序需要注释掉的代码释放并且
 * @code sort_quick(array, element_size, left, j, compare);
 * @code sort_quick(array, element_size, left, j-1, compare);
 * 任意数组类型排序
 * @param array 待排序数组头指针
 * @param element_size 数组单个元素大小
 * @param len 数组长度 输入部分长度可以排序部分的长度
 * @param compare 比较函数，可以实现一个数组使用不同字段排序只需要传递比较函数
 */
void sort_list(void *array, int element_size, int len, int (*compare)(const void *, const void *));

#endif //TEST_SORT_H

//   3 12 13 7 23 =>3 7 12 13 23
