//
// Created by 11848 on 2022/5/8.
//
#include <stdbool.h>
#include "main.h"
#include "../../pojo/file.h"
#include "reader.h"

extern LinkList *CLASS;
extern int CLASS_LEN;

bool checkForExistence(LinkList *list, char *target) {
    struct data *data = list->data
            ->next;
    while (NULL != data) {
        if (!strcmp(data->data, target)) {
            return true;
        }
        data = data->next;
    }
    return false;
}

bool checkClassExistence(char **res, char *name) {
    for (int i = 0; i < CLASS_LEN; ++i) {
        if (!strcmp(res[i], name)) {
            return true;
        }
    }
    return false;
}

void insert_class(void) {
    char **res = getClass();
    printf("已有班级(%d)\n", CLASS_LEN);
    for (int i = 0; i < CLASS_LEN; ++i) {
        printf("%d.%s\n", i, res[i]);
    }
    char *name = malloc(sizeof(char));
    in:
    input("输入班级名称:", "%s", name);
    if (checkClassExistence(res, name)) {
        printf("班级已存在...\n");
        goto in;
    }
    printf("班级:%s\n", name);
    int code;
    input("1.直接添加 \t2.添加课程 \t3.重新输入 \t4.返回主菜单\n操作码:", "%d", &code);
    if (code == 1) {
        writeClass(name);
        refresh_class();
        return;
    } else if (code == 2) {
        char *buffer = malloc(sizeof(char) * 1024);
        input("请输入课程(多个课程以-分隔):", "%s", buffer);
        LinkList *re = spit(buffer, "-");
        struct data *data = re->data;
        re->data = createData(name, 0);
        re->data
                ->next = data;
        writeClasses(*re);
        refresh_class();
        printf("班级添加成功,按任意键返回主菜单");
        fflush(stdin);//防止getchar 不起作用 清空所有缓冲区
        getchar();
        return;
    } else if (code == 3) {
        goto in;
    }
}


void insert_class_sub(void) {
    for (int i = 0; i < CLASS_LEN; ++i) {
        printf("%d.%s\n", i, CLASS[i].data
                ->data);
    }
    int code;
    l:
    input("操作码:", "%d", &code);
    if (0 > code || code > CLASS_LEN) {
        printf("操作码有误");
        goto l;
    }
    struct data *data = CLASS[code].data
            ->next;
    printf("已有课程:\n");
    while (NULL != data) {
        printf("%s\n", data->data);
        data = data->next;
    }
    char *name = malloc(sizeof(char) * 20);
    in:
    input("输入添加课程名称:", "%s", name);
    //检查课程是否存在
    if (checkForExistence(&CLASS[code], name)) {
        printf("%s课程已存在，请勿重复添加\n", name);
        goto in;
    }
    printf("课程:%s \t", name);
    int res;
    input("1.确认添加 \t2.重新输入 \t3.返回主菜单\n操作码", "%d", &res);
    if (res == 2) {
        free(name);
        name = malloc(sizeof(char) * 20);
        goto in;
    } else if (res == 3)
        return;
    update_class(code, createData(name, CLASS[code].size));
    //更新
    updateClass();
}
