//
//  p1091.c
//  HOJ
//
//  Created by dev on 2018/2/26.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int a,b;
    while(scanf("%d%d",&a, &b) != EOF) {
        if(a == 0 && b == 0) {
            break;
        }
        printf("%d\n", a + b);
    }
    
    return 0;
}
