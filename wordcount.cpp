#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//统计文件的单词数 
int countWords(FILE *fp) {
    int count = 0;
    int in_word = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c) || c == ',' || c == '.') {
            if (in_word) {
                count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) {
        count++;
    }
    return count;
}

//统计文件的字符个数 
int countChars(FILE *fp) {
    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        count++;
    }
    return count;
}


int main(int argc, char *argv[]) {
    char *filename;
    char *parameter;
    FILE *fp;
    int count;
    if (argc == 3) { //若有两个参数，记录对应要统计的类型 
        parameter = argv[1];
        filename = argv[2];
    } else if (argc == 2) { //若只有一个参数，默认统计字符数 
        parameter = "-c";
        filename = argv[1];
    } else {
        printf("参数错误，请检查参数的个数");
        exit(1);
    }
    fp = fopen(filename, "r"); //读取文件 
    if (fp == NULL) {
        printf("找不到此文件");
        exit(1);
    }
    if (strcmp(parameter, "-c") == 0) {
        count = countChars(fp);
        printf("字符数为：%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        count = countWords(fp);
        printf("单词数为：%d\n", count);
    } else {
        printf("统计类型错误，请检查输入！");
        exit(1);
    }
    fclose(fp);
    return 0;
}

