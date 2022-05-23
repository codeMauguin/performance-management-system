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
 * 显示主菜单
 */
void show_main(void);

/**
 * 学生列表菜单
 */

void show_stu_college(void);

/**
 * 打印学生 @code{id}信息
 * @param id
 * @param size
 * @return
 */
Score *print_stu_score(long id, int *size);

/**
 * 修改学生信息
 */
void revise_stu(void);

/**
 * 修改学生成绩信息
 */
void revise_stu_score(void);

/**
 * 添加学生
 */
void insert_stu(void);

/**
 * 添加学生成绩
 */
void insert_stu_score(void);

void insert_class(void);

void insert_class_sub(void);

/**
 * 统计
 * @todo 班级单科通过率
 *
 */
void statistics(void);

void delete_stu(void);

#endif /* _main_h */
