//
//  p1038.c
//  HOJ
//
//  Created by dev on 2018/2/1.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
float PI = 3.1415927;
int main(int argc, const char * argv[]) {
    float d; // 直径
    int r; // 圈数
    float t; // 时间
    float s,mph;
    int index = 0;
    while(scanf("%f%d%f",&d,&r,&t) != EOF) {
        if(r == 0) {
            break;
        }
        index++;
        s = PI*d*r/(12*5280); // 路程
        mph = s*3600/t;
        printf("Trip #%d: %0.2f %0.2f\n",index,s,mph);
    }
    return 0;
}
