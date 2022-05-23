//
//  writer.c
//  student
//
//  Created by Mauguin on 2022/4/29.
//

#include <string.h>
#include "writer.h"
#include "file.h"

extern char *STU_FILE_PATH;
extern char *CLASS_FILE_PATH;
extern char *SCORE_FILE_PATH;

extern LinkList *CLASS;
extern int CLASS_LEN;

extern Student *STU;
extern int STU_LEN;

extern Score *SCORE;
extern int SCORE_LEN;

void writeStu(Student stu) {
    FILE *fp;
    fp = fopen(STU_FILE_PATH, "a+");
    if (NULL == fp) {
        printf("文件不存在");
        return;
    }
    fprintf(fp, "%ld\t%s\t%s\t%s\n", stu.id, stu.name, stu.sex, stu.class_name);
    fflush(fp);
    fclose(fp);
    fp = NULL;
}

void writeScore(Score score) {
    FILE *fp;
    fp = fopen(SCORE_FILE_PATH, "a+");
    if (NULL == fp) {
        printf("文件不存在");
        return;
    }
    fprintf(fp, "%ld\t%d\t%s\t%s\n", score.stu_id, score.score, score.sub_name, score.class_name);
    fflush(fp);
    fclose(fp);
    fp = NULL;
}

void writeClasses(LinkList list) {
    FILE *fp;
    fp = fopen(CLASS_FILE_PATH, "a+");
    if (NULL == fp) {
        printf("文件不存在");
        return;
    }
    fputs(join(list), fp);
    fflush(fp);
    fclose(fp);
    fp = NULL;
}

void writeClass(char *name) {
    FILE *fp;
    fp = fopen(CLASS_FILE_PATH, "a+");
    if (NULL == fp) {
        printf("文件不存在");
        return;
    }
    fputs(name, fp);
    fputs("\n", fp);
    fflush(fp);
    fclose(fp);
    fp = NULL;

}

char *join(LinkList list) {
    char *res = malloc(sizeof(char) * 1024);
    res[0] = '\0';
    struct data *data = list.data;
    while (NULL != data) {
        strcat(res, data->data);
        if (data->next == NULL)break;
        strcat(res, "\t");
        data = data->next;
    }
    strcat(res, "\n");
    return res;
}

void updateClass(void) {
    FILE *fp;
    fp = fopen(CLASS_FILE_PATH, "w+");
    if (NULL == fp) {
        printf("文件创建失败");
        return;
    }
    char *res;
    for (int i = 0; i < CLASS_LEN; ++i) {
        LinkList list = CLASS[i];
        res = join(list);
        fputs(res, fp);
    }
    fflush(fp);
    fclose(fp);
    fp = NULL;
    refresh_class();
}

void updateStu(void) {
    FILE *fp;
    fp = fopen(STU_FILE_PATH, "w+");
    if (NULL == fp) {
        printf("文件创建失败");
        return;
    }
    Student stu;
    for (int i = 0; i < STU_LEN; ++i) {
        stu = STU[i];
        fprintf(fp, "%ld\t%s\t%s\t%s\n", stu.id, stu.name, stu.sex, stu.class_name);
    }
    fflush(fp);
    fclose(fp);
    fp = NULL;
    refresh_stu();
}

void updateScore(void) {
    FILE *fp;
    fp = fopen(SCORE_FILE_PATH, "w+");
    if (NULL == fp) {
        printf("文件创建失败");
        system("pause");
        return;
    }
    Score score;
    for (int i = 0; i < SCORE_LEN; ++i) {
        score = SCORE[i];
        fprintf(fp, "%ld\t%d\t%s\t%s\n", score.stu_id, score.score, score.sub_name,
                score.class_name);
    }
    fflush(fp);
    fclose(fp);
    fp = NULL;
    refresh_score();
}

static
void delete_stu_score(long id) {
    FILE *fp;
    fp = fopen(SCORE_FILE_PATH, "w+");
    if (NULL == fp) {
        printf("文件创建失败");
        return;
    }
    Score score;
    for (int i = 0; i < SCORE_LEN; ++i) {
        score = SCORE[i];
        if (score.stu_id == id)continue;
        fprintf(fp, "%ld\t%d\t%s\t%s\n", score.stu_id, score.score, score.sub_name,
                score.class_name);
    }
    fflush(fp);
    fclose(fp);
    fp = NULL;
    refresh_score();
}


void deleteStu(int index, long id) {
    FILE *fp;
    fp = fopen(STU_FILE_PATH, "w+");
    if (NULL == fp) {
        printf("文件创建失败");
        return;
    }
    Student stu;
    for (int i = 0; i < STU_LEN; ++i) {
        if (i == index)continue;
        stu = STU[i];
        fprintf(fp, "%ld\t%s\t%s\t%s\n", stu.id, stu.name, stu.sex, stu.class_name);
    }
    fflush(fp);
    fclose(fp);
    fp = NULL;
    refresh_stu();
    delete_stu_score(id);
}
