//
//  search.c
//  student
//
//  Created by Mauguin on 2022/4/29.
//

#include <string.h>
#include <stdio.h>
#include "search.h"

extern int STU_LEN;
extern int SCORE_LEN;

extern Student *STU;
extern Score *SCORE;

extern LinkList *CLASS;
extern int CLASS_LEN;

Student *find_by_id(long id, int *index) {
    Student *student = NULL;
    for (int i = 0; i < STU_LEN; ++i) {
        if (STU[i].id == id) {
            student = &STU[i];
            if (index != NULL)
                *index = i;
            break;
        }
    }
    return student;
}

Score *getScore_by_id(long id, int *size) {
    Score *sc = malloc(10 * sizeof(Score));
    int index = 0;
    for (int i = 0; i < SCORE_LEN; ++i) {
        if (id == SCORE[i].stu_id) {
            sc[index++] = SCORE[i];
        }
    }
    *size = index;
    return sc;
}


char **getClass() {
    char **res = malloc(CLASS_LEN * sizeof(char *));
    for (int i = 0; i < CLASS_LEN; ++i) {
        res[i] = CLASS[i].data
                ->data;
    }
    return res;
}

char **getSubject(char *name, int *size) {
    for (int i = 0; i < CLASS_LEN; ++i) {
        if (!strcmp(CLASS[i].data
                            ->data, name)) {
            struct data *data = CLASS[i].data
                    ->next;
            char **res = malloc((CLASS[i].size - 1) * sizeof(char *));
            int count = 0;
            while (NULL != data) {
                res[count++] = data->data;
                data = data->next;
            }
            *size = count;
            return res;
        }
    }
    return NULL;
}
