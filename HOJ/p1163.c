//
//  p1163.c
//  HOJ
//
//  Created by cheng on 2018/10/11.
//  Copyright © 2018 dev. All rights reserved.
//

#include <stdio.h>



int main(int argc, const char * argv[]) {
    int n;
    while (scanf("%d", &n) != EOF) {
        if(n == 0) {
            break;
        }
        int m = n;
        for(int i = 1; i < n; i++) {
            m = (m*n)%9;
           
        }
        if(m) {
            printf("%d\n", m);
        } else {
            printf("9\n");
        }
    }
    return 0;
}
