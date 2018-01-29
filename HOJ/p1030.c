//
//  p1030.c
//  HOJ
//
//  Created by dev on 2018/1/29.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int getX(int m) {
    int h = sqrt(m);
    if(h*h < m) {
        h = h + 1;
    }
    return h;
}

int getY(int m, int h) {
    return (m - (h-1)*(h-1) + 1)/2;
}

int getZ(int m, int h) {
    return (h*h - m)/2 + 1;
}
int main(int argc, const char * argv[]) {
    int m,n;
    while(scanf("%d%d", &m, &n) != EOF) {
        int tmp = 0;
        if (m > n) {
            tmp = m;
            m = n;
            n = tmp;
        }
        int x1 = getX(m);
        int y1 = getY(m,x1);
        int z1 = getZ(m,x1);
        
        int x2 = getX(n);
        int y2 = getY(n,x2);
        int z2 = getZ(n,x2);
//        printf("x1=%d,y1=%d,z1=%d\n",x1,y1,z1);
        printf("%d\n",abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2));
        
    }
    return 0;
}
