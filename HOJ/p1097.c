//
//  p1097.c
//  HOJ
//
//  Created by cheng on 2018/10/9.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b;
    int number[10];
    while(scanf("%d%d", &a, &b) != EOF) {
        a = a%10;
        int dig = a;
        number[0] = dig;
        int len = 1;
        for(int i = 1; i < 10; i++) {
            dig = (a* dig)%10;
            if(dig != a) {
                number[len] = dig;
                len++;
            } else {
                break;
            }
        }
        //每len个数循环

        printf("%d\n", number[(b - 1)%len]);
    }
    return 0;
}
