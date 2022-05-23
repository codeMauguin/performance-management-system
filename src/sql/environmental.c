//
// Created by 11848 on 2022/5/7.
//
#include <malloc.h>
#include <unistd.h>
#include <stdio.h>
#include <libloaderapi.h>
#include "initialization.h"


char *WORK_LIST;

char *WORK_LIST_STU = "\\data\\student.txt";//Student ���ļ���׺ --ƴ�ӵ�����Ŀ¼��
char *WORK_LIST_SCORE = "\\data\\score.txt";// ͬ �� score����ļ���׺
char *WORK_LIST_CLASS = "\\data\\class.txt";//ͬ �� class����ļ���׺
char *WORK_LIST_DATA = "\\data";//���ݴ�ŵ��ļ�Ŀ¼

char *WORK_DATA_PATH;
char *STU_FILE_PATH;
char *SCORE_FILE_PATH;
char *CLASS_FILE_PATH;

static void access_file(char *name, int mode) {
    if (mode == 1) {
        if (access(name, 0) == -1 && mkdir(name) == 0) {
            printf("data�ļ�������...�Ѵ���\r\n");
        }
    } else {
        if (access(name, 0) == -1 && creat(name, 0777) != -1) {
            printf("�Ѵ���\r\n");
        }
    }
}

void environmentalTest(void) {
    printf("��黷��...\r\n");
    //��ȡ��ǰexe����Ŀ¼
    WORK_LIST = malloc(MAX_PATH * sizeof(char));
    getcwd(WORK_LIST, MAX_PATH * sizeof(char));
    STU_FILE_PATH = malloc((strlen(WORK_LIST) + strlen(WORK_LIST_STU)) * sizeof(char));
    SCORE_FILE_PATH = malloc((strlen(WORK_LIST) + strlen(WORK_LIST_SCORE)) * sizeof(char));
    WORK_DATA_PATH = malloc((strlen(WORK_LIST) + strlen(WORK_LIST_DATA)) * sizeof(char));
    CLASS_FILE_PATH = malloc((strlen(WORK_LIST) + strlen(WORK_LIST_CLASS)) * sizeof(char));
    strcpy(STU_FILE_PATH, WORK_LIST);
    strcpy(WORK_DATA_PATH, WORK_LIST);
    strcpy(SCORE_FILE_PATH, WORK_LIST);
    strcpy(CLASS_FILE_PATH, WORK_LIST);
    strcat(CLASS_FILE_PATH, WORK_LIST_CLASS);
    strcat(STU_FILE_PATH, WORK_LIST_STU);
    strcat(WORK_DATA_PATH, WORK_LIST_DATA);
    strcat(SCORE_FILE_PATH, WORK_LIST_SCORE);
    free(WORK_LIST);
    //���exeĿ¼�µ�data�ļ���
    access_file(WORK_DATA_PATH, 1);
    access_file(STU_FILE_PATH, 0);
    access_file(SCORE_FILE_PATH, 0);
    access_file(CLASS_FILE_PATH, 0);
    printf("����׼�����\r\n");
}
