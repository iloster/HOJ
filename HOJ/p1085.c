//
//  p1085.c
//  HOJ
//
//  Created by cheng on 2019/7/8.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>


int main(int argc, const char * argv[]) {
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c)) {
        if(a == 0 && b == 0 && c == 0) {
            break;
        }
        if(a == 0) {
            printf("1\n");
        } else if(a + b * 2 < 4) {
            printf("%d\n", a + b * 2 + 1);
        } else {
            printf("%d\n", a + b * 2 + c * 5 + 1);
        }
    }
}
