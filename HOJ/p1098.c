//
//  p1098.c
//  HOJ
//
//  Created by dev on 2018/2/24.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int k;
    while(scanf("%d", &k) != EOF) {
        int a = 0;
        int flag = 0;
        for(a = 0; a <= 65; a++) {
            if(a*k % 65 == 47) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            printf("%d\n", a);
        } else {
            printf("no\n");
        }
    }
    return 0;
}
