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
 * 更新学生信息
 * @param index
 * @param student
 */
void update_stu_data(int index, Student student);

/**
 * 更新学生成绩
 * @param score_num
 * @param score
 */

void update_stu_score(int score_num, Score score);

/**
 * 刷新内存学生信息
 */

void refresh_stu(void);

/**
 * 刷新内存学生成绩
 */
void refresh_score(void);

void refresh_class(void);

/**
 * 初始化所有信息
 */
void initialization(void);

/**
 * 对数据文件的检测 程序开始需要读取数据文件，不存在需要去创建
 */
void environmentalTest(void);

#endif /* initialization_h */
