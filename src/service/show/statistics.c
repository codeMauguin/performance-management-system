//
// Created by 11848 on 2022/5/7.
//
#include "main.h"

extern Student *STU;
extern Score *SCORE;

extern int STU_LEN;
extern int SCORE_LEN;

/**
 * 获取班级名称
 * @return
 */
extern int CLASS_LEN;
extern LinkList *CLASS;


int descendingComparison(const void *a, const void *b) {
    return (*(Score *) a).score - (*(Score *) b).score;
}

int ascending(const void *a, const void *b) {
    return (*(Score *) b).score - (*(Score *) a).score;
}


float queryTheFailureRate(char *subjectName, char *className) {
    float count = 0;
    float failed = 0;
    for (int i = 0; i < SCORE_LEN; ++i) {
        if (!strcmp(SCORE[i].sub_name, subjectName) && !strcmp(SCORE[i].class_name, className)) {
            count++;
            if (SCORE[i].score < 60) {
                failed++;
            }
        }
    }
    if (count == 0)return 0;
    return failed / count;
}

float querySubjectAverageScore(char *subjectName, char *className) {
    float count = 0;
    float total = 0;
    for (int i = 0; i < SCORE_LEN; ++i) {
        if (!strcmp(SCORE[i].sub_name, subjectName) && !strcmp(SCORE[i].class_name, className)) {
            count++;
            total += SCORE[i].score;
        }
    }
    if (count == 0)return 0;
    return total / count;
}

void printStudentGrades(const Score *score, int index) {
    for (int i = 0; i < index; ++i) {
        Student *student = find_by_id(score[i].stu_id, NULL);
        printf("姓名:%s\t成绩:%d\n", student->name, score[i].score);
    }
}

void displayAllGradesOfStudentsInAClass(char *subjectName, char *className) {
    Score *score = malloc(sizeof(Score) * SCORE_LEN);
    int index = 0;
    for (int i = 0; i < SCORE_LEN; ++i) {
        if (!strcmp(SCORE[i].sub_name, subjectName) && !strcmp(SCORE[i].class_name, className)) {
            score[index++] = SCORE[i];
        }
    }
    printf("班级:%s\t科目:%s所有学生成绩如下\n", className, subjectName);
    printStudentGrades(score, index);
    int code;
    flag:
    input("1.降序\t2.升序\t3.返回主菜单:", "%d", &code);
    if (code == 1) {
        sort_list(score, sizeof(Score), index, descendingComparison);
        printStudentGrades(score, index);
        goto flag;
    } else if (code == 2) {
        sort_list(score, sizeof(Score), index, ascending);
        printStudentGrades(score, index);
        goto flag;
    }
}

void statistics(void) {
    s:
    for (int i = 0; i < CLASS_LEN; ++i) {
        printf("%d.%s\n", i, CLASS[i].data
                ->data);
    }
    int code;
    in:
    input("操作码:", "%d", &code);
    LinkList list = CLASS[code];
    if (list.size == 1) {
        printf("学科没有课程...\n");
        goto in;
    }
    struct data *data = list.data
            ->next;
    int count;
    isn:
    count = 1;
    while (NULL != data) {
        printf("%d.%s\n", count++, data->data);
        data = data->next;
    }
    printf("%d.返回主菜单\n", count);
    l:
    input("操作码:", "%d", &code);
    if (code == count)return;
    else if (code >= list.size || code < 0)goto l;
    data = list.data
            ->next;
    while (NULL != data) {
        if ((data->row) == code) {
            break;
        }
        data = data->next;
    }
    ins:
    printf("0.查询所有学生成绩\t1.查询科目挂科率 \t2.查询科目平均分 \t3.返回主菜单\n");
    input("操作码:", "%d", &code);
    //选择班级-科目-显示挂科率
    if (code == 0) {
        displayAllGradesOfStudentsInAClass(data->data, list.data
                ->data);
        system("cls");
        goto isn;
    } else if (code == 1) {
        float failure = queryTheFailureRate(data->data, list.data
                ->data);
        printf("%s挂科率为:%.0f%%\n", data->data, failure * 100);
    } else if (code == 2) {
        float average = querySubjectAverageScore(data->data, list.data
                ->data);
        printf("%s平均分为:%.2f\n", data->data, average);
    } else if (code == 3)return;
    else {
        printf("输入有误\n");
        goto ins;
    }
    input("1.继续查询 \t2.返回主菜单\n操作码:", "%d", &code);
    if (code == 1) {
        system("cls");
        goto s;
    }
}
