//
//  search.h
//  student
//
//  Created by Mauguin on 2022/4/29.
//

#ifndef search_h
#define search_h

#include <stdlib.h>

#include "../pojo/student.h"
#include "../sql/initialization.h"

/**
 * ����ѧ�Ų���ѧ��
 * @param id ѧ��
 * @param index �����±�
 * @return Student->ѧ����Ϣ\n
 *         NULL->ѧ��������
 */
Student *find_by_id(long id, int *index);

/**
 * ����ѧ�Ų��ҷ���
 * @param id ѧ��
 * @return Score->ѧ�����гɼ���
 */

Score *getScore_by_id(long id, int *);

char **getClass();

char **getSubject(char *, int *);

#endif /* search_h */
