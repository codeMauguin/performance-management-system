//
//  stu_score_menu.c
//  student
//
//  Created by Mauguin on 2022/4/30.
//

#include "main.h"

extern Student *STU;
extern int STU_LEN;

extern Score *SCORE;
extern int SCORE_LEN;

static int compare_score(const void *a, const void *b) {
    return ((*(Score *) a).score - (*(Score *) b).score);
}

static void show_stu(void);

static void show_stu_all(void);

static void show_all_score(Score *sc, int len) {
    for (int i = 0; i < len; ++i) {
        printf("学科:%s \t成绩:%d\r\n", sc[i].sub_name, sc[i].score);
    }
    int code;
    r:
    if (!input("1.排序 \t2.返回主菜单 \t3.退出程序\r\n操作码:", "%d", &code)) {
        goto r;
    }
    if (code == 1) {
        sort_list(sc, sizeof(Score), len, compare_score);
        show_all_score(sc, len);
    } else if (code == 3) {
        exit(0);
    }
}

static int compare_by_id(const void *a, const void *b) {
    return (int) ((*(Student *) a).id - (*(Student *) b).id);
}

Score *print_stu_score(long id, int *size) {
    Score *sc = getScore_by_id(id, size);
    for (int i = 0; i < *size; ++i) {
        printf("%d.学科:%s\r\n", i, sc[i].sub_name);
    }
    return sc;
}


static void show_student(Student *student, int state) {
    int res;
    printf("学号:%ld \t姓名:%s \t性别:%s \t班级:%s\r\n", student->id, student->name, student->sex,
           student->class_name);
    int len;
    Score *sc;
    score:
    sc = print_stu_score(student->id, &len);
    if (len == 0) {
        printf("没有学生成绩信息\r\n");
        input("1.查询其他学生 \t2.返回主菜单\r\n操作码:", "%d", &res);
        free(sc);
        if (res == 1) {
            if (state)
                return show_stu();
            else return show_stu_all();
        } else
            return;
    }
    printf("%d.查询所有成绩\r\n", len);
    input("操作码:", "%d", &res);
    if (res < 0) {
        printf("输入错误\r\n");
        goto score;
    }
    if (res == len) {
        return show_all_score(sc, len);
    } else if (res > len) {
        printf("输入有误!\n");
        goto score;
    }
    printf("课程信息\r\n");
    printf("学科:%s \t成绩:%d\r\n", sc[res].sub_name, sc[res].score);
    input("1.继续查询 \t2.返回主菜单 \t3.退出程序\r\n操作码:", "%d", &res);
    if (res == 3) {
        exit(0);
    } else if (res == 1) {
        goto score;
    }
    free(sc);
    sc = NULL;
}


static void show_stu(void) {
    long id;
    int res;
    input:
    res = input("请输入学号:", "%ld", &id);
    if (!res) {
        goto input;
    }
    Student *student;
    if ((student = find_by_id(id, NULL)) != NULL) {
        show_student(student, 1);
    } else {
        printf("没有找到该学生\r\n");
        system("pause");
    }
}

//获取所有学生信息
static void show_stu_all(void) {
    if (STU_LEN == 0) {
        printf("没有学生，请先添加学生再查询!\r\n");
        return;
    }
    main:
    system("cls");//清屏
    for (int idx = 0; idx < STU_LEN; ++idx) {
        printf("%d.学号:%ld \t姓名:%s \t性别:%s \t班级:%s\r\n", idx, STU[idx].id, STU[idx].name,
               STU[idx].sex,
               STU[idx].class_name);
    }
    int code;
    start:
    printf("%d.排序 \t2.选择编号(输入0-%d) \t%d.返回主菜单", STU_LEN, STU_LEN - 1, STU_LEN + 1);
    if (!input("\r\n操作码:", "%d", &code)) {
        goto start;
    }
    if (code == STU_LEN) {
        sort_list(STU, sizeof(Student), STU_LEN, compare_by_id);
        goto main;
    } else if (code == (STU_LEN + 1)) {
        return;
    } else {
        if (code >= 0 && code < STU_LEN)
            show_student(&STU[code], 0);
        else {
            printf("输入错误!\n");
            goto start;
        }
    }
}

//获取学院信息
void show_stu_college(void) {
    int code, res;
    start:
    res = input("1.查询所有学生信息 \t 2.查询个人信息\r\n操作码:", "%d", &code);
    if (!res) {
        goto start;
    }
    if (code == 1) {
        show_stu_all();
    } else {
        show_stu();
    }
}
