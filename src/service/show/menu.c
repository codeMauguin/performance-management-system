//
//  menu.c
//  student
//
//  Created by Mauguin on 2022/4/30.
//

#include "main.h"

void show_main(void) {
    while (1) {
        int code;
        i:
        system("cls");
        printf("学生成绩查询系统\n\n");
        if (!input("1.查询学生 \t\t"
                   "2.修改学生信息\t\t3.修改学生成绩 \n\n"
                   "4.添加学生 \t\t5.添加学生成绩 \t\t"
                   "6.添加班级\n\n7.添加课程 \t\t"
                   "8.删除 \t\t\t"
                   "9.统计\n\n10.退出程序\n请输入操作码1-6:", "%d", &code))
            goto i;
        switch (code) {
            case 1:
                show_stu_college();
                break;
            case 2:
                revise_stu();
                break;
            case 3:
                revise_stu_score();
                break;
            case 4:
                insert_stu();
                break;
            case 5:
                insert_stu_score();
                break;
            case 6:
                insert_class();
                break;
            case 7:
                insert_class_sub();
                break;
            case 8:
                delete_stu();
                break;
            case 9:
                statistics();
                break;
            case 10:
                exit(0);
            default:
                printf("输入操作码有误,请重新输入1-5:\r\n");
        }
    }
}
