//
//  p1161.c
//  HOJ
//
//  Created by cheng on 2018/10/10.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
char a[1000];
int main(int argc, const char * argv[]) {
    while (gets(a)) {
//        printf("%s", a);
        for(int i = 0; a[i] != '\0'; i++) {
            if(a[i] >= 65 && a[i] <= 90) {
               putchar(a[i] + 32);
            } else {
               putchar(a[i]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
