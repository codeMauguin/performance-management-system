//
//  scanf.c
//  student
//
//  Created by Mauguin on 2022/5/1.
//
#include "scanf.h"

int input(char *info, char *format, ...) {
    printf("%s", info);
    va_list args;
    va_start(args, format);
    int res = vscanf(format, args);
    va_end(args);
    if (!res) {
        printf("Input error!!!\r\n");
        fflush(stdin);
        //while ((res = getchar()) != '\n' && res != EOF);
        return 0;
    }
    return 1;
}
