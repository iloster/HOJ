//
//  p1006.c
//  HOJ
//
//  Created by dev on 2018/2/10.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main(int argc, const char * argv[]) {
    int d;
    float h = 1.000/120;
    float m = 1.000/10;
    float s = 6.000;
    int i = 0;
//    int j = -1;
//    int k = -1;
    while(scanf("%d", &d) != EOF) {
        if(d == -1) {
            break;
        }
        int sum = 0;
        for(i = 0; i < 43200; i++) {
            float d1 = fmod(11/120.0*i,360);
            float d2 = fmod(5.9*i,360);
            float d3 = fmod(719/120.0*i,360);
            
            if(d1 >= d && (360 - d1) >= d && d2 >= d && (360 - d2) >= d && d3 >= d && (360 - d3) >= d) {
                sum++;
            }
        }
        printf("%.3f\n", (sum*2*1.000)/(432));
    }
    return 0;
}
