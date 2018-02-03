//
//  p1042.c
//  HOJ
//
//  Created by dev on 2018/2/3.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int size = 10000;
int a[100000];
int main(int argc, const char * argv[]) {

    int n;
    int i;
    while(scanf("%d", &n) != EOF) {
        if(n == 0) {
            printf("0\n");
        } else {
            int m = 1;
            for(i = 1; i <= n; i++) {
                m *= i;
            }
            printf("%d\n",m);
        }
    }
}
