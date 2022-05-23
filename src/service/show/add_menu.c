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
    input("����ѧ��ID:", "%ld", &id);
    //У��ѧ��id�Ƿ��Ѿ�����
    Student *stu = find_by_id(id, NULL);
    if (NULL != stu) {
        printf("ѧ��:%ld %sͬѧ�Ѿ�����!\r\n1.�������� \t2.�������˵�\r\n������:", id, stu->name);
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
    input("����:", "%s", student.name);
    input("�Ա�(1.�� \t2.Ů):", "%d", &code);
    if (code == 1) {
        student.sex = "��";
    } else {
        student.sex = "Ů";
    }
    if (CLASS_LEN == 0) {
        printf("û�а༶�ɼ���...");
        system("pause");
        return;
    }
    char **classes = getClass();
    for (int i = 0; i < CLASS_LEN; ++i) {
        printf("%d.%s\n", i, classes[i]);
    }
    i:
    input("�༶(������):", "%d", &code);
    if (code < 0 || code >= CLASS_LEN)goto i;
    student.class_name = classes[code];
    printf("ѧ��:%ld\t����:%s\t�Ա�:%s\t�༶:%s\r\n", id, student.name, student.sex, student.class_name);
    input("1.ȷ����� \t2.�������� \t3.�������˵�\r\n������:", "%d", &code);
    if (code == 1) {
        writeStu(student);
        refresh_stu();
        input("1.������� \t2.�������˵� \t3.�˳�����\r\n������:", "%d", &code);
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
    if (!input("ѧ��:", "%ld", &id)) {
        goto s;
    }
    Student *stu = find_by_id(id, NULL);
    if (NULL == stu) {
        input("ѧ��������\r\n1.�������� \t2.�������˵� \t3.�˳�����\r\n������:", "%d", &code);
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
    //Todo ѧ����Ҫ��ѧ�Ʊ���
    if (size > 0)printf("\n");
    Score score;
    score.stu_id = id;
    score.sub_name = malloc(10 * sizeof(char));
    score.class_name = malloc(10 * sizeof(char));
    int len;
    char **res = getSubject(stu->class_name, &len);
    if (size == len) {
        printf("û�п�����ӵĿγ�...\n");
        system("pause");
        free(res);
        return;
    }
    char *cln;
    for (int i = 0; i < len; ++i) {
        cln = res[i];
        printf("%d.%s", i, cln);
        if (checkSubjectExists(cln, sc, size)) {
            printf("��\n");
        } else {
            printf("��\n");
        }
    }
    o:
    input("������:", "%d", &code);
    if (code > len || code < 0 || checkSubjectExists(res[code], sc, size))goto o;
    score.sub_name = res[code];
    in :
    input("����:", "%d", &score.score);
    if (score.score < 0) {
        printf("��������Ϊ��!!!");
        goto in;
    }
    printf("ѧ��:%s \t����:%d\r\n", score.sub_name, score.score);
    input("1.ȷ����� \t2.ȡ�����(��������) \t3.�������˵�)\r\n������:", "%d", &code);
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
    input("1.������� \t2.�������˵� \t3.�˳�����\r\n������:", "%d", &code);
    if (code == 1) {
        goto re;
    } else if (code == 3)exit(0);
}
