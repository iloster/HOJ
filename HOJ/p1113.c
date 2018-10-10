//
//  p1113.c
//  HOJ
//
//  Created by cheng on 2018/10/10.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
#include <string.h>
// 最多100个单词
char words[100][100];

char *sortChar(char *ch) {
    // 每一个字母都能找到
    char tmp;
    char copy1[strlen(ch)];
    strcmp(copy1, ch);
    for(int i = 0; copy1[i] != '\0'; i++) {
        for(int j = i + 1; copy1[j] != '\0'; j++) {
            if(copy1[i] > copy1[j]) {
                tmp = copy1[i];
                copy1[i] = copy1[j];
                copy1[j] = tmp;
            }
        }
    }
    printf("copy1: %s\n",copy1);
    return copy1;
}

int isEqual(char *ch1, char *ch2) {
    if(strcmp(sortChar(ch1), sortChar(ch2)) == 0) {
        return 1;
    } else {
        return 0;
    }
    
}

int main(int argc, const char * argv[]) {
    
    int input = 0;
    int len1 = 0,len2 = 0;
    for(int i = 0; i < 100; i++) {
        scanf("%s", words[i]);
        if(strcmp(words[i], "XXXXXX") == 0) {
            input++;
            if(input%2 == 1 ) {
                len1 = i;
            } else {
                len2 = i;
                // 输出结果
                for(int j = len1 + 1; j < len2; j++) {
                    int flag = 0;
                    for(int k = 0; k < len1; k++) {
                         if(isEqual(words[j], words[k]) == 1){
                             flag = 1;
                             printf("%s\n", words[k]);
                         }
                    }
                    if(flag == 0) {
                        printf("NOT A VALID WORD\n");
                    }
                    printf("******\n");
                }
            }
           
        }
    }
   
    printf("%d\n", input);
    return 0;
}
