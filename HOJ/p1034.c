//
//  p1034.c
//  HOJ
//
//  Created by dev on 2018/1/31.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int a[1000000] = {0};
int b[1000000] = {0};
void f(int *a, int n) {
    int i = 0;
    for(i = 0; i < n; i++) {
        if(a[i]%2 == 0) {
            b[i] = a[i]/2;
        } else {
            b[i] = (a[i]+1)/2;
        }
    }
}

int isEqual(int *a, int n) {
    int i = 0;
    int x = a[0];
    for(i = 0; i < n; i++) {
        if (a[i] != x) {
            return 0;
        }
    }
    return 1;
}
void print(int *a, int len, char str) {
    int i = 0;
    printf("%c", str);
    for(i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    int n = 0;
    int i = 0;
    while(scanf("%d",&n) != EOF) {
        if(n > 0) {
            for(i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }
            int len = 0;
            while (isEqual(a, n) == 0) {
                f(a,n);
                for(i = 1; i < n; i++) {
                    a[i] -= b[i];
                    a[i] += b[i - 1];
                    if(a[i]%2 == 1) {
                        a[i]++;
                    }
                }
                a[0] -= b[0];
                a[0] += b[n - 1];
                if(a[0]%2 == 1) {
                    a[0]++;
                }
                len++;
//                print(b,n,'b');
//                print(a, n,'a');
            }
            printf("%d %d\n",len,a[0]);
        } else {
            break;
        }
    }
    return 0;
}
