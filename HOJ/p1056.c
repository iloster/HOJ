//
//  p1056.c
//  HOJ
//
//  Created by cheng on 2019/1/29.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    double a;
    while (scanf("%lf", &a) != EOF) {
        if(a == 0.00) {
            break;
        }
//        printf("%.2f\n", a);
        double sum = 0;
        int n = 1;
        while(sum < a) {
            n++;
            sum += 1.0/n;
        }
        printf("%d card(s)\n", n - 1);
        
    }
    return 0;
}
