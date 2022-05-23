//
//  main.h
//  student
//
//  Created by Mauguin on 2022/4/30.
//

#ifndef _main_h
#define _main_h

#include <stdio.h>
#include <string.h>
#include "../../pojo/student.h"
#include "../../util/scanf/scanf.h"
#include "../../util/collection/sort.h"
#include "../search.h"
#include "../../sql/writer.h"
#include <stdlib.h>

/**
 * ��ʾ���˵�
 */
void show_main(void);

/**
 * ѧ���б�˵�
 */

void show_stu_college(void);

/**
 * ��ӡѧ�� @code{id}��Ϣ
 * @param id
 * @param size
 * @return
 */
Score *print_stu_score(long id, int *size);

/**
 * �޸�ѧ����Ϣ
 */
void revise_stu(void);

/**
 * �޸�ѧ���ɼ���Ϣ
 */
void revise_stu_score(void);

/**
 * ���ѧ��
 */
void insert_stu(void);

/**
 * ���ѧ���ɼ�
 */
void insert_stu_score(void);

void insert_class(void);

void insert_class_sub(void);

/**
 * ͳ��
 * @todo �༶����ͨ����
 *
 */
void statistics(void);

void delete_stu(void);

#endif /* _main_h */
