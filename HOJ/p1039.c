//
//  p1039.c
//  HOJ
//
//  Created by dev on 2018/2/2.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

int isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return 1;
    }
    return 0;
}

// 必须包含一个元音
int isRule1(char *ch) {
    int i = 0;
    for(i = 0; ch[i] != '\0'; i++) {
        if(isVowel(ch[i]) == 1) {
            return 1;
        }
    }
    return 0;
}

// 不能包含三个连续的元音或者三个连续的辅音
int isRule2(char *ch) {
    int i;
    int num1 = 0;
    int num2 = 0;
    for(i = 0; ch[i] != '\0'; i++) {
        if(isVowel(ch[i])) {
            num1++;
            num2 = 0;
        } else {
            num1 = 0;
            num2++;
        }
        if(num1 >= 3 || num2 >=3) {
            break;
        }
    }
     if(num1 >= 3 || num2 >=3) {
         return 0;
     }
    return 1;
}

int isRule3(char *ch) {
    int i;
    int flag = 1;
    for(i = 1; ch[i] != '\0'; i++) {
        if(ch[i] != 'e' && ch[i] != 'o') {
//            printf("%c %c\n",ch[i],ch[i+1]);
            if (ch[i-1] == ch[i]){
                flag = 0;
                break;
            }
        }
    }
    
    return flag;
}

int main(int argc, const char * argv[]) {
    char ch[30];
    while(scanf("%s",ch) != EOF) {
        if(strcmp(ch,"end") == 0){
            break;
        }
        if(isRule1(ch) && isRule2(ch) && isRule3(ch)) {
            printf("<%s> is acceptable.\n",ch);
        } else {
            printf("<%s> is not acceptable.\n",ch);
        }
    }
}
