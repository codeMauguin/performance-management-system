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
        printf("ѧ���ɼ���ѯϵͳ\n\n");
        if (!input("1.��ѯѧ�� \t\t"
                   "2.�޸�ѧ����Ϣ\t\t3.�޸�ѧ���ɼ� \n\n"
                   "4.���ѧ�� \t\t5.���ѧ���ɼ� \t\t"
                   "6.��Ӱ༶\n\n7.��ӿγ� \t\t"
                   "8.ɾ�� \t\t\t"
                   "9.ͳ��\n\n10.�˳�����\n�����������1-6:", "%d", &code))
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
                printf("�������������,����������1-5:\r\n");
        }
    }
}
