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
 * 根据学号查找学生
 * @param id 学号
 * @param index 返回下标
 * @return Student->学生信息\n
 *         NULL->学生不存在
 */
Student *find_by_id(long id, int *index);

/**
 * 根据学号查找分数
 * @param id 学号
 * @return Score->学生所有成绩表
 */

Score *getScore_by_id(long id, int *);

char **getClass();

char **getSubject(char *, int *);

#endif /* search_h */
