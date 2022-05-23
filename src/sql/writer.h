//
//  writer.h
//  student
//
//  Created by Mauguin on 2022/4/29.
//

#ifndef writer_h
#define writer_h

#include <stdio.h>
#include "../pojo/student.h"
#include "initialization.h"

void writeStu(Student stu);

void writeScore(Score score);

void writeClass(char *name);

char *join(LinkList list);

void writeClasses(LinkList list);

void updateStu(void);

void updateClass(void);

void updateScore(void);

void deleteStu(int, long);

#endif /* writer_h */
