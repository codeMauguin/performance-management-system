//
//  initialization.h
//  student
//
//  Created by Mauguin on 2022/4/29.
//

#ifndef initialization_h
#define initialization_h

#include "../pojo/student.h"
#include "../pojo/score.h"
#include "../pojo/file.h"

void update_class(int index, struct data *data);

/**
 * ����ѧ����Ϣ
 * @param index
 * @param student
 */
void update_stu_data(int index, Student student);

/**
 * ����ѧ���ɼ�
 * @param score_num
 * @param score
 */

void update_stu_score(int score_num, Score score);

/**
 * ˢ���ڴ�ѧ����Ϣ
 */

void refresh_stu(void);

/**
 * ˢ���ڴ�ѧ���ɼ�
 */
void refresh_score(void);

void refresh_class(void);

/**
 * ��ʼ��������Ϣ
 */
void initialization(void);

/**
 * �������ļ��ļ�� ����ʼ��Ҫ��ȡ�����ļ�����������Ҫȥ����
 */
void environmentalTest(void);

#endif /* initialization_h */
