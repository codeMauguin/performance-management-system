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
        printf("ѧ��:%s \t�ɼ�:%d\r\n", sc[i].sub_name, sc[i].score);
    }
    int code;
    r:
    if (!input("1.���� \t2.�������˵� \t3.�˳�����\r\n������:", "%d", &code)) {
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
        printf("%d.ѧ��:%s\r\n", i, sc[i].sub_name);
    }
    return sc;
}


static void show_student(Student *student, int state) {
    int res;
    printf("ѧ��:%ld \t����:%s \t�Ա�:%s \t�༶:%s\r\n", student->id, student->name, student->sex,
           student->class_name);
    int len;
    Score *sc;
    score:
    sc = print_stu_score(student->id, &len);
    if (len == 0) {
        printf("û��ѧ���ɼ���Ϣ\r\n");
        input("1.��ѯ����ѧ�� \t2.�������˵�\r\n������:", "%d", &res);
        free(sc);
        if (res == 1) {
            if (state)
                return show_stu();
            else return show_stu_all();
        } else
            return;
    }
    printf("%d.��ѯ���гɼ�\r\n", len);
    input("������:", "%d", &res);
    if (res < 0) {
        printf("�������\r\n");
        goto score;
    }
    if (res == len) {
        return show_all_score(sc, len);
    } else if (res > len) {
        printf("��������!\n");
        goto score;
    }
    printf("�γ���Ϣ\r\n");
    printf("ѧ��:%s \t�ɼ�:%d\r\n", sc[res].sub_name, sc[res].score);
    input("1.������ѯ \t2.�������˵� \t3.�˳�����\r\n������:", "%d", &res);
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
    res = input("������ѧ��:", "%ld", &id);
    if (!res) {
        goto input;
    }
    Student *student;
    if ((student = find_by_id(id, NULL)) != NULL) {
        show_student(student, 1);
    } else {
        printf("û���ҵ���ѧ��\r\n");
        system("pause");
    }
}

//��ȡ����ѧ����Ϣ
static void show_stu_all(void) {
    if (STU_LEN == 0) {
        printf("û��ѧ�����������ѧ���ٲ�ѯ!\r\n");
        return;
    }
    main:
    system("cls");//����
    for (int idx = 0; idx < STU_LEN; ++idx) {
        printf("%d.ѧ��:%ld \t����:%s \t�Ա�:%s \t�༶:%s\r\n", idx, STU[idx].id, STU[idx].name,
               STU[idx].sex,
               STU[idx].class_name);
    }
    int code;
    start:
    printf("%d.���� \t2.ѡ����(����0-%d) \t%d.�������˵�", STU_LEN, STU_LEN - 1, STU_LEN + 1);
    if (!input("\r\n������:", "%d", &code)) {
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
            printf("�������!\n");
            goto start;
        }
    }
}

//��ȡѧԺ��Ϣ
void show_stu_college(void) {
    int code, res;
    start:
    res = input("1.��ѯ����ѧ����Ϣ \t 2.��ѯ������Ϣ\r\n������:", "%d", &code);
    if (!res) {
        goto start;
    }
    if (code == 1) {
        show_stu_all();
    } else {
        show_stu();
    }
}
