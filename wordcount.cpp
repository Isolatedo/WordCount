#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//ͳ���ļ��ĵ����� 
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

//ͳ���ļ����ַ����� 
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
    if (argc == 3) { //����������������¼��ӦҪͳ�Ƶ����� 
        parameter = argv[1];
        filename = argv[2];
    } else if (argc == 2) { //��ֻ��һ��������Ĭ��ͳ���ַ��� 
        parameter = "-c";
        filename = argv[1];
    } else {
        printf("����������������ĸ���");
        exit(1);
    }
    fp = fopen(filename, "r"); //��ȡ�ļ� 
    if (fp == NULL) {
        printf("�Ҳ������ļ�");
        exit(1);
    }
    if (strcmp(parameter, "-c") == 0) {
        count = countChars(fp);
        printf("�ַ���Ϊ��%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        count = countWords(fp);
        printf("������Ϊ��%d\n", count);
    } else {
        printf("ͳ�����ʹ����������룡");
        exit(1);
    }
    fclose(fp);
    return 0;
}

