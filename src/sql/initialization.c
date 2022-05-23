#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
//  initialization.c
//  student
//
//  Created by Mauguin on 2022/4/29.
//

#include "initialization.h"
#include "reader.h"
#include <stdio.h>
#include <string.h>

extern char *STU_FILE_PATH;
extern char *SCORE_FILE_PATH;
extern char *CLASS_FILE_PATH;
Student *STU = NULL;
int STU_LEN = 0;
Score *SCORE = NULL;
int SCORE_LEN = 0;

LinkList *CLASS = NULL;
int CLASS_LEN = 0;

void update_stu_data(int index, Student student) {
    if (0 > index || index > STU_LEN)return;
    STU[index] = student;
}

void update_class(int index, struct data *data) {
    inset_next(&CLASS[index], data);
}

void update_stu_score(int score_num, Score score) {
    if (0 > SCORE_LEN)return;
    for (int i = 0; i < SCORE_LEN; ++i) {
        if (SCORE[i].stu_id == score.stu_id && !strcmp(SCORE[i].sub_name, score.sub_name)) {
            SCORE[i].score = score_num;
        }
    }
}

static void desScore() {
    for (int i = 0; i < SCORE_LEN; ++i) {
        free(SCORE[i].sub_name);
    }
    free(SCORE);
    SCORE = NULL;
}

static void desClass() {
    destroy(CLASS);
    CLASS = NULL;
}


void refresh_class(void) {
    LinkList *list = readerFile(CLASS_FILE_PATH);
    if (CLASS != NULL)desClass();
    CLASS = malloc(list->size * sizeof(LinkList));
    struct data *data = list->data;
    char *temp;
    while (NULL != data) {
        temp = strstr(data->data, "\n");
        if (temp != NULL)
            *temp = '\0';
        CLASS[data->row] = *spit(data->data, "\t");
        data = data->next;
    }
    CLASS_LEN = list->size;
    destroy(list);
}

void refresh_score(void) {
    LinkList *list = readerFile(SCORE_FILE_PATH);
    struct data *data = list->data;
    if (NULL != SCORE)desScore();
    SCORE = malloc(list->size * sizeof(Score));
    while (NULL != data) {
        Score *sc = malloc(sizeof(Score));
        sc->sub_name = malloc(20 * sizeof(char));
        sc->class_name = malloc(20 * sizeof(char));
        sscanf(data->data, "%ld\t%d\t%s\t%s\n", &sc->stu_id, &sc->score, sc->sub_name,
               sc->class_name);
        SCORE[data->row] = *sc;
        data = data->next;
    }
    SCORE_LEN = list->size;
    destroy(list);
    list = NULL;
}

static void desStu() {
    for (int i = 0; i < STU_LEN; ++i) {
        free(STU[i].name);
        free(STU[i].class_name);
    }
    free(STU);
    STU = NULL;
}


void refresh_stu(void) {
    LinkList *list = readerFile(STU_FILE_PATH);
    struct data *data = list->data;
    if (NULL != STU)desStu();
    STU = malloc(list->size * sizeof(Student));
    while (NULL != data) {
        Student *stu = malloc(sizeof(Student));
        stu->name = malloc(20 * sizeof(char));
        stu->sex = malloc(5 * sizeof(char));
        stu->class_name = malloc(20 * sizeof(char));
        sscanf(data->data, "%ld\t%s\t%s\t%s\n", &stu->id, stu->name, stu->sex, stu->class_name);
        STU[data->row] = *stu;
        data = data->next;
    }
    STU_LEN = list->size;
    destroy(list);
    list = NULL;
}


void initialization(void) {
    refresh_class();
    refresh_stu();
    refresh_score();
}

#pragma clang diagnostic pop
