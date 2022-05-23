//
//  main.c
//  student
//
//  Created by Mauguin on 2022/4/28.
//
#include <windows.h>
#include "pojo/student.h"

#include "sql/initialization.h"

#include "service/show/main.h"

#include "sql/reader.h"

extern int STU_LEN;
extern Student *STU;

/*
//测试qsort
struct child {
    int id;
    char *name;
};
struct test {
    int id;
    char *name;
    struct child *child;
};


int com(const void *a, const void *b) {
    return (*(struct test *) a).id - (*(struct test *) b).id;
}

struct test *init() {
    struct test *all = malloc(10 * sizeof(struct test));
    int count = 0;
    for (int i = 9; i >= 0; --i) {
        struct child child;
        struct test test;
        test.id = 10 - count--;
        child.id = test.id;
        child.name = malloc(sizeof(char) * 10);
        child.name = "ds";
        test.name = malloc(sizeof(char) * 10);
        test.name = "ds";
        test.child = malloc(sizeof(struct child));
        test.child = &child;
        all[i] = test;
    }
    return all;
}
 struct test *all = init();
    for (int i = 0; i < 10; ++i) {
        printf("%d\t", all[i].id);
    }
    printf("\n");
    qsort(all, 10, sizeof(struct test), com);
    for (int i = 0; i < 10; ++i) {
        printf("%d\t", all[i].id);
    }
    system("pause");


 */


/**
 * 程序主入口
 * 显示成绩管理系统的窗口
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    SetConsoleTitle("成绩查询系统");
    environmentalTest();
    initialization();
    printf("数据加载完毕...");
    show_main();
    system("pause");
    return -1;
}
