//
//  p1022.c
//  HOJ
//
//  Created by cheng on 2018/1/22.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char a[9],b[9],c[9];
    int len;
    while(scanf("%d%s%s", &len, a, b) != EOF) {
        int i = 0;
        int j = 0;
        int k = 1;
        c[k] = a[0];
        int f[9];
        int x = 0;
        while((i < len) && (j < len)) {
            if (c[k] == b[j]) {
                // 出栈
                k--;
                j++;
                f[x] = 0;
            } else {
                i++;
                k++;
                c[k] = a[i];
                f[x] = 1;
            }
            x++;
        }
//        printf("%d\n",x);
        if (k == 0) {
            printf("Yes.\n");
            int i = 0;
            printf("in\n");
            for(i = 0; i < x; i++) {
                if (f[i] == 1) {
                    printf("in\n");
                } else {
                    printf("out\n");
                }
            }
        } else {
            printf("No.\n");
        }
        printf("FINISH\n");
    }
    return 1;
}
