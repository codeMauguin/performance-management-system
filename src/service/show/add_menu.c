//
// Created by Mauguin on 2022/5/6.
//
#include <stdbool.h>
#include "main.h"

extern int CLASS_LEN;

void insert_stu(void) {
    long id;
    int code;
    s:
    input("输入学生ID:", "%ld", &id);
    //校验学生id是否已经存在
    Student *stu = find_by_id(id, NULL);
    if (NULL != stu) {
        printf("学号:%ld %s同学已经存在!\r\n1.重新输入 \t2.返回主菜单\r\n操作码:", id, stu->name);
        input("", "%d", &code);
        if (code == 1) {
            goto s;
        }
        return;
    }
    Student student;
    st:
    student.id = id;
    student.name = malloc(20 * sizeof(char));
    input("姓名:", "%s", student.name);
    input("性别(1.男 \t2.女):", "%d", &code);
    if (code == 1) {
        student.sex = "男";
    } else {
        student.sex = "女";
    }
    if (CLASS_LEN == 0) {
        printf("没有班级可加入...");
        system("pause");
        return;
    }
    char **classes = getClass();
    for (int i = 0; i < CLASS_LEN; ++i) {
        printf("%d.%s\n", i, classes[i]);
    }
    i:
    input("班级(操作码):", "%d", &code);
    if (code < 0 || code >= CLASS_LEN)goto i;
    student.class_name = classes[code];
    printf("学号:%ld\t姓名:%s\t性别:%s\t班级:%s\r\n", id, student.name, student.sex, student.class_name);
    input("1.确认添加 \t2.重新输入 \t3.返回主菜单\r\n操作码:", "%d", &code);
    if (code == 1) {
        writeStu(student);
        refresh_stu();
        input("1.继续添加 \t2.返回主菜单 \t3.退出程序\r\n操作码:", "%d", &code);
        if (code == 2)return;
        else if (code == 1) {
            goto s;
        } else exit(0);

    } else if (code == 2) {
        goto st;
    }
}

bool checkSubjectExists(char *dest, Score *score, int size) {
    for (int i = 0; i < size; ++i) {
        if (!strcmp(dest, score[i].sub_name))return true;
    }
    return false;
}

void insert_stu_score(void) {
    long id;
    int code;
    s:
    if (!input("学号:", "%ld", &id)) {
        goto s;
    }
    Student *stu = find_by_id(id, NULL);
    if (NULL == stu) {
        input("学生不存在\r\n1.重新输入 \t2.返回主菜单 \t3.退出程序\r\n操作码:", "%d", &code);
        if (code == 1) {
            goto s;
        } else if (code == 2)return;
        else exit(0);
    }
    int size;
    Score *sc;
    re:
    system("cls");
    sc = getScore_by_id(id, &size);
    //Todo 学科需要在学科表内
    if (size > 0)printf("\n");
    Score score;
    score.stu_id = id;
    score.sub_name = malloc(10 * sizeof(char));
    score.class_name = malloc(10 * sizeof(char));
    int len;
    char **res = getSubject(stu->class_name, &len);
    if (size == len) {
        printf("没有可以添加的课程...\n");
        system("pause");
        free(res);
        return;
    }
    char *cln;
    for (int i = 0; i < len; ++i) {
        cln = res[i];
        printf("%d.%s", i, cln);
        if (checkSubjectExists(cln, sc, size)) {
            printf("×\n");
        } else {
            printf("√\n");
        }
    }
    o:
    input("操作码:", "%d", &code);
    if (code > len || code < 0 || checkSubjectExists(res[code], sc, size))goto o;
    score.sub_name = res[code];
    in :
    input("分数:", "%d", &score.score);
    if (score.score < 0) {
        printf("分数不能为负!!!");
        goto in;
    }
    printf("学科:%s \t分数:%d\r\n", score.sub_name, score.score);
    input("1.确认添加 \t2.取消添加(重新输入) \t3.返回主菜单)\r\n操作码:", "%d", &code);
    if (code == 2) {
        free(res);
        goto re;
    } else if (code == 3) {
        free(res);
        return;
    }
    score.class_name = stu->class_name;
    writeScore(score);
    refresh_score();
    free(res);
    input("1.继续添加 \t2.返回主菜单 \t3.退出程序\r\n操作码:", "%d", &code);
    if (code == 1) {
        goto re;
    } else if (code == 3)exit(0);
}
