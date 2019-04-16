//
//  p1068.c
//  HOJ
//
//  Created by cheng on 2019/4/16.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double pi = 3.14159265358979323846;
int n, f;
int radii[11000];
int isOK(double x) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (int) ((radii[i] * radii[i] * pi)/x);
    }
    if(sum >= (f + 1)) {
        return 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int line = 0;
    int maxR = 0;
    while(scanf("%d", &line) != EOF){
        for(int i = 0; i < line; i++) {
            scanf("%d %d", &n, &f);
            for(int j = 0; j < n; j++) {
                scanf("%d", &radii[j]);
                if(radii[j] >= maxR) {
                    maxR = radii[j];
                }
            }
            double left = 0;
            double right = maxR*maxR*pi;
            double mid = 0;
//            printf("right: %.4f\n", right);
            while((right - left) >= 0.0000001) {
                mid = (left + right) / 2;
                if(isOK(mid) == 1) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            printf("%.4f\n", mid);
        }
    }
    return 0;
}
