//
//  p1048.c
//  HOJ
//
//  Created by dev on 2018/2/6.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

char f(char ch) {
    if(ch >=65 && ch <= 90) {
        if((ch + 21) > 90) {
            return ch + 21 - 26;
        }
        return ch + 21;
    }
    return ch;
}

int main(int argc, const char * argv[]) {
    char str[2000];
    while (gets(str) != NULL && strcmp(str, "ENDOFINPUT"))
    {
        if (!strcmp(str, "START") || !strcmp(str, "END"))
            continue;
        
        
        int i = 0;
        for(i = 0; str[i] != '\0'; i++) {
            printf("%c", f(str[i]));
        }
        printf("\n");
        
    }

    return 0;
}
