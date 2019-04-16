//
//  p2199.c
//  HOJ
//
//  Created by cheng on 2019/4/16.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>
#include <math.h>
double EPS = 1e-8;
int f(double x, double y) {
//    if(8*pow(x, 4) + 7*pow(x, 3)+ 2*pow(x, 2) + 3*x + 6 - y) {
//        return 1;
//    } else {
//        return 0;
//    }
    double r = 8*x*x*x*x + 7*x*x*x + 2*x*x + 3*x + 6;
    if(r - y > 0) {
        return 1;
    }
    return 0;
}


int main(int argc, const char * argv[]) {
    int line = 0;
    double y = 0;
    scanf("%d", &line);
    for(int i = 0; i < line; i++) {
        scanf("%lf", &y);
        double left = 0;
        double right = 100;
        double mid = 0;
        if(y < 6 || y >807020306) {
            printf("No solution!\n");
            continue;
        }
       
        while((right - left) > EPS) {
            mid = (left + right)/2.0;
            if(f(mid, y)) {
                right = mid;
            } else {
                left = mid;
            }
        }
 
        printf("%.4lf\n", mid);

    }
    
    return 0;
}
