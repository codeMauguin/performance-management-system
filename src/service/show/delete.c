//
// Created by 11848 on 2022/5/9.
//
#include "main.h"


void delete_stu(void) {
    long id;
    int code;
    go:
    input("�������ɾ��ѧ��ѧ��:", "%ld", &id);
    int index;
    Student *stu = find_by_id(id, &index);
    if (stu == NULL) {
        printf("û���ҵ���ѧ��...\n");
        input("1.�������� \t2.�������˵�", "%d", &code);
        if (code == 2)return;
        goto go;
    }
    input("1.ȷ��ɾ�� \t2.��������ѧ�� \t3.�������˵�\n������:", "%d", &code);
    if (code == 1) {
        deleteStu(index, id);
        printf("ɾ���ɹ�");
        input("1.����ɾ�� \t2.�������˵�\n������:", "%d", &code);
        if (code == 1)goto go;
    } else if (code == 2)goto go;
}