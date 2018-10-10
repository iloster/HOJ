//
//  p1108.c
//  HOJ
//
//  Created by cheng on 2018/10/10.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
        int min,max;
        if(a > b) {
            min = a;
        } else {
            min = b;
        }
        max = a*b;
        for(int i = min; i <= max; i++) {
            if(i%a == 0 && i%b==0) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
