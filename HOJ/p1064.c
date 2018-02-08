//
//  p1064.c
//  HOJ
//
//  Created by dev on 2018/2/8.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {

    float a[12];
    int i;
    float sum = 0;
    for(i = 0; i < 12; i++) {
        scanf("%f", &a[i]);
        sum += a[i];
    }
    
    printf("$%.2f\n", sum/12);
}
