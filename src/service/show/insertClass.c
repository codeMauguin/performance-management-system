//
// Created by 11848 on 2022/5/8.
//
#include <stdbool.h>
#include "main.h"
#include "../../pojo/file.h"
#include "reader.h"

extern LinkList *CLASS;
extern int CLASS_LEN;

bool checkForExistence(LinkList *list, char *target) {
    struct data *data = list->data
            ->next;
    while (NULL != data) {
        if (!strcmp(data->data, target)) {
            return true;
        }
        data = data->next;
    }
    return false;
}

bool checkClassExistence(char **res, char *name) {
    for (int i = 0; i < CLASS_LEN; ++i) {
        if (!strcmp(res[i], name)) {
            return true;
        }
    }
    return false;
}

void insert_class(void) {
    char **res = getClass();
    printf("���а༶(%d)\n", CLASS_LEN);
    for (int i = 0; i < CLASS_LEN; ++i) {
        printf("%d.%s\n", i, res[i]);
    }
    char *name = malloc(sizeof(char));
    in:
    input("����༶����:", "%s", name);
    if (checkClassExistence(res, name)) {
        printf("�༶�Ѵ���...\n");
        goto in;
    }
    printf("�༶:%s\n", name);
    int code;
    input("1.ֱ����� \t2.��ӿγ� \t3.�������� \t4.�������˵�\n������:", "%d", &code);
    if (code == 1) {
        writeClass(name);
        refresh_class();
        return;
    } else if (code == 2) {
        char *buffer = malloc(sizeof(char) * 1024);
        input("������γ�(����γ���-�ָ�):", "%s", buffer);
        LinkList *re = spit(buffer, "-");
        struct data *data = re->data;
        re->data = createData(name, 0);
        re->data
                ->next = data;
        writeClasses(*re);
        refresh_class();
        printf("�༶��ӳɹ�,��������������˵�");
        fflush(stdin);//��ֹgetchar �������� ������л�����
        getchar();
        return;
    } else if (code == 3) {
        goto in;
    }
}


void insert_class_sub(void) {
    for (int i = 0; i < CLASS_LEN; ++i) {
        printf("%d.%s\n", i, CLASS[i].data
                ->data);
    }
    int code;
    l:
    input("������:", "%d", &code);
    if (0 > code || code > CLASS_LEN) {
        printf("����������");
        goto l;
    }
    struct data *data = CLASS[code].data
            ->next;
    printf("���пγ�:\n");
    while (NULL != data) {
        printf("%s\n", data->data);
        data = data->next;
    }
    char *name = malloc(sizeof(char) * 20);
    in:
    input("������ӿγ�����:", "%s", name);
    //���γ��Ƿ����
    if (checkForExistence(&CLASS[code], name)) {
        printf("%s�γ��Ѵ��ڣ������ظ����\n", name);
        goto in;
    }
    printf("�γ�:%s \t", name);
    int res;
    input("1.ȷ����� \t2.�������� \t3.�������˵�\n������", "%d", &res);
    if (res == 2) {
        free(name);
        name = malloc(sizeof(char) * 20);
        goto in;
    } else if (res == 3)
        return;
    update_class(code, createData(name, CLASS[code].size));
    //����
    updateClass();
}
