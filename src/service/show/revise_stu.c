//
//  revise_stu.c
//  student
//
//  Created by Mauguin on 2022/5/4.
//
#include "main.h"

extern Student *STU;
extern int CLASS_LEN;

void revise_stu(void) {
    long code;
    start:
    if (!input("请输入学生ID:", "%ld", &code)) {
        goto start;
    }
    Student *student;
    int index;
    if ((student = find_by_id(code, &index)) != NULL) {
        s:
        printf("id:%ld \t1.姓名:%s \t2.性别:%s \t3.班级:%s\t4.修改完毕\t5.取消修改(返回主菜单)\r\n",
               student->id, student->name, student->sex, student->class_name);
        int res;
        input("操作码:", "%d", &res);
        char *name = malloc(sizeof(char));
        char **classes;
        switch (res) {
            case 1:
                input("请输入姓名:", "%s", name);
                student->name = name;
                goto s;
            case 2:
                printf("1.男\t2.女\r\n");
                input("操作码:", "%d", &res);
                student->sex = res == 1 ? "男" : "女";
                goto s;
            case 3:
                //TODO 显示班级
                classes = getClass();
                if (CLASS_LEN == 0) {
                    printf("没有班级提供,请先添加班级...");
                    system("pause");
                    return;
                }
                for (int i = 0; i < CLASS_LEN; ++i) {
                    printf("%d.%s\n", i, classes[i]);
                }
            i:
                input("请输入班级:", "%d", &res);
                if (res < 0 || res >= CLASS_LEN)goto i;
                strcpy(student->class_name, classes[res]);
                free(classes);
                goto s;
            default:
                printf("操作码错误!\r\n");
            case 5:
                name = NULL;
                return;
            case 4:
                update_stu_data(index, *student);
                updateStu();
                student = NULL;
                break;
        }
        name = NULL;
    } else {
        printf("没有找到该学生信息!\r\n");
    }
}

void revise_stu_score(void) {
    long id;
    int code;
    s:
    if (!input("请输入修改学生id:", "%ld", &id)) {
        goto s;
    }
    // 校验学生存在
    Student *student = find_by_id(id, NULL);
    if (NULL == student) {
        printf("学生不存在\r\n");
        input("1.重新输入 \t2.返回主菜单\r\n操作码:", "%d", &code);
        if (code == 1) {
            goto s;
        }
        return;
    }
    int size;
    Score *sc;
    re:
    sc = getScore_by_id(id, &size);
    if (size == 0) {
        printf("%s学生没有成绩信息", student->name);
        system("pause");
        return;
    }
    system("cls");
    for (int i = 0; i < size; ++i) {
        printf("%d.学科:%s \t成绩:%d\r\n", i, sc[i].sub_name, sc[i].score);
    }
    printf("%d.返回主菜单\r\n", size);
    p:
    if (!input("操作码:", "%d", &code)) {
        goto p;
    }
    if (code == size)
        return;
    if (code < 0 || code > size)
        goto p;
    int score;
    score:
    if (!input("成绩:", "%d", &score)) {
        goto score;
    }
    update_stu_score(score, sc[code]);
    updateScore();
    free(sc);
    sc = NULL;
    input("1.继续修改 \t2.返回主菜单 \t3.退出程序\n操作码:", "%d", &code);
    if (code == 1)
        goto re;
    else if (code == 3)
        exit(0);
}
