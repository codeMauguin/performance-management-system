//
// Created by Mauguin on 2022/4/27.
//
#include "file.h"

LinkList *createList(void) {
    LinkList *list = malloc(sizeof(LinkList));
    list->data = NULL;
    list->current = NULL;
    list->size = 0;
    return list;
}

struct data *createData(char *content, int row) {
    struct data *data = malloc(sizeof(struct data));
    data->data = content;
    data->row = row;
    data->next = NULL;
    return data;
}


void inset_next(LinkList *list, struct data *insert) {
    //current当前最后指针为空说明当前链表没有元素
    if (NULL == list->current) {
        list->data = insert;
        ++(list->size);
        list->current = insert;
    } else {
        list->current
                ->next = insert;
        list->current = insert;//保持最后指针是最后一个元素
        ++(list->size);
    }
}

int delete_by_idx(LinkList *list, int idx) {
    if (idx > list->size - 1 || idx < 0) {
        return 0;//理应报错，但是c没有异常机制
    }
    struct data *next;
    if (idx == 0) {
        next = list->data
                ->next;
        free(list->data);//将删除的节点释放
        list->data = next;
        --list->size;
        if (NULL == next)
            list->current = NULL;
        return 1;
    }
    int index = 1;
    struct data *parent = list->data;
    while (index < list->size) {
        if (index == idx) {
            next = parent->next
                    ->next;
            free(parent->next);//释放删除的节点
            parent->next = next;
            --list->size;
            if (NULL == next) {
                list->current = parent;//如果删除的最后元素，保持current的指向
            }
            return 1;
        }
        ++index;
        parent = parent->next;
    };
    return 0;
}

void destroy(LinkList *list) {
    if (NULL == list)return;
    struct data *data = list->data;
    while (NULL != data) {
        list->data = data->next;
        free(data);
        data = list->data;
    }
    free(list);
    list = NULL;
}
