//
// Created by Mauguin on 2022/4/27.
//

#ifndef TEST_FILE_H
#define TEST_FILE_H

#include <stdlib.h>

struct data {
    int row;//行数
    char *data;
    struct data *next;
};
typedef struct file {
    struct data *data;
    struct data *current;//当前指针最后一个元素位置
    int size;   //链表长度
} LinkList;

/**
 * 创建链表
 * @return 返回创建好的链表
 */
LinkList *createList(void);

/**
 * 创建链表data内容
 * @return 返回创建的data
 */
struct data *createData(char *content, int row);

/**
 *删除数据
 *@param idx 删除的下标
 *@return 1:成功
 *       -1:删除未找到
 */
int delete_by_idx(LinkList *, int idx);

/**
 * 插入链表
 * @param list 创建的链表的头节点
 * @param insert 待插入的链表节点
 */
void inset_next(LinkList *list, struct data *insert);

/**
 * 销毁链表
 * @param list 销毁链表
 */
void destroy(LinkList *list);

#endif //TEST_FILE_H
