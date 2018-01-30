//
//  p1032.c
//  HOJ
//
//  Created by dev on 2018/1/30.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

int f(int n) {
    int i = 1;
    while(n > 1) {
        if(n%2 == 1) {
            n = 3*n + 1;
        } else {
            n = n/2;
        }
        i++;
    }
    return i;
}

int main(int argc, const char * argv[]) {
    int m,n;
    int i;
    while(scanf("%d%d", &m,&n) != EOF) {
        printf("%d %d ",m,n);
        int temp;
        if(m > n) {
            temp = m;
            m = n;
            n = temp;
        }
        int max = f(m);
//        printf("max=%d\n",max);
        for(i = m + 1; i <= n; i++) {
            if(f(i) > max) {
                max = f(i);
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
