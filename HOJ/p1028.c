//
//  p1028.c
//  HOJ
//
//  Created by dev on 2018/1/27.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>


int main(int argc, const char * argv[]) {
    int n = 0;
    int a[130] = {0};
    int b[130] = {0};
    int i = 0;
    int j = 0;
    int k = 0;
    while(scanf("%d",&n)!=EOF) {
        for(i = 0; i <= n; i++ ) {
            a[i] = 1;
            b[i] = 0;
        }
        for(i = 2; i <= n; i++) {
            for(j = 0; j <= n; j++) {
                for(k = 0; k+j <= n; k+=i) {
                    b[k+j] += a[j];
                }
            }
            for(j = 0; j <= n; j++) {
                a[j] = b[j];
                b[j] = 0;
            }
        }
        printf("%d\n",a[n]);
    }
    return 0;
}
