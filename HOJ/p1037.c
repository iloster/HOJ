//
//  p1037.c
//  HOJ
//
//  Created by dev on 2018/2/1.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int a[3] = {0};
int main(int argc, const char * argv[]) {
    int i = 0;
    for(i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
    }
    int flag = 0;
    for(i = 0; i < 3; i++) {
        if(a[i] <= 168) {
            printf("CRASH %d\n", a[i]);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("NO CRASH\n");
    }
    return 0;
}
