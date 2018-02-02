//
//  p1041.c
//  HOJ
//
//  Created by dev on 2018/2/2.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int g(int n);
// 0的个数
int f(int n) {
    if (n <= 2) {
        return 1;
    } else if (n == 3) {
        return 2;
    }
    return f(n - 1) + g(n - 1);
}

int f1(int n) {
    if(n  == 1) {
        return 0;
    } else if (n == 2) {
        return 0;
    } else if (n == 3) {
        return 1;
    }
 
    if((n-1)%2 == 1) {
        return 2*f(n - 1) ;
    }
    return 2*f(n - 1) - 1;
    
}

int g(int n) {
    if (n < 3) {
        return 0;
    } else if (n == 3) {
        return 1;
    }
    if(n%2 == 1) {
        return f(n);
    }
    return f(n) - 1;
}

int main(int argc, const char * argv[]) {
    int step = 0;
    while(scanf("%d", &step) != EOF) {
        printf("%d\n",f(step - 1) + g(step - 1));
    }
}
