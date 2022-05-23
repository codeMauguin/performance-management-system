//
// Created by 11848 on 2022/5/9.
//
#include "main.h"


void delete_stu(void) {
    long id;
    int code;
    go:
    input("请输入待删除学生学号:", "%ld", &id);
    int index;
    Student *stu = find_by_id(id, &index);
    if (stu == NULL) {
        printf("没有找到该学生...\n");
        input("1.重新输入 \t2.返回主菜单", "%d", &code);
        if (code == 2)return;
        goto go;
    }
    input("1.确认删除 \t2.重新输入学号 \t3.返回主菜单\n操作码:", "%d", &code);
    if (code == 1) {
        deleteStu(index, id);
        printf("删除成功");
        input("1.继续删除 \t2.返回主菜单\n操作码:", "%d", &code);
        if (code == 1)goto go;
    } else if (code == 2)goto go;
}