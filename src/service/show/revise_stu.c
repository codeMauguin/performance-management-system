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
    if (!input("������ѧ��ID:", "%ld", &code)) {
        goto start;
    }
    Student *student;
    int index;
    if ((student = find_by_id(code, &index)) != NULL) {
        s:
        printf("id:%ld \t1.����:%s \t2.�Ա�:%s \t3.�༶:%s\t4.�޸����\t5.ȡ���޸�(�������˵�)\r\n",
               student->id, student->name, student->sex, student->class_name);
        int res;
        input("������:", "%d", &res);
        char *name = malloc(sizeof(char));
        char **classes;
        switch (res) {
            case 1:
                input("����������:", "%s", name);
                student->name = name;
                goto s;
            case 2:
                printf("1.��\t2.Ů\r\n");
                input("������:", "%d", &res);
                student->sex = res == 1 ? "��" : "Ů";
                goto s;
            case 3:
                //TODO ��ʾ�༶
                classes = getClass();
                if (CLASS_LEN == 0) {
                    printf("û�а༶�ṩ,������Ӱ༶...");
                    system("pause");
                    return;
                }
                for (int i = 0; i < CLASS_LEN; ++i) {
                    printf("%d.%s\n", i, classes[i]);
                }
            i:
                input("������༶:", "%d", &res);
                if (res < 0 || res >= CLASS_LEN)goto i;
                strcpy(student->class_name, classes[res]);
                free(classes);
                goto s;
            default:
                printf("���������!\r\n");
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
        printf("û���ҵ���ѧ����Ϣ!\r\n");
    }
}

void revise_stu_score(void) {
    long id;
    int code;
    s:
    if (!input("�������޸�ѧ��id:", "%ld", &id)) {
        goto s;
    }
    // У��ѧ������
    Student *student = find_by_id(id, NULL);
    if (NULL == student) {
        printf("ѧ��������\r\n");
        input("1.�������� \t2.�������˵�\r\n������:", "%d", &code);
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
        printf("%sѧ��û�гɼ���Ϣ", student->name);
        system("pause");
        return;
    }
    system("cls");
    for (int i = 0; i < size; ++i) {
        printf("%d.ѧ��:%s \t�ɼ�:%d\r\n", i, sc[i].sub_name, sc[i].score);
    }
    printf("%d.�������˵�\r\n", size);
    p:
    if (!input("������:", "%d", &code)) {
        goto p;
    }
    if (code == size)
        return;
    if (code < 0 || code > size)
        goto p;
    int score;
    score:
    if (!input("�ɼ�:", "%d", &score)) {
        goto score;
    }
    update_stu_score(score, sc[code]);
    updateScore();
    free(sc);
    sc = NULL;
    input("1.�����޸� \t2.�������˵� \t3.�˳�����\n������:", "%d", &code);
    if (code == 1)
        goto re;
    else if (code == 3)
        exit(0);
}
