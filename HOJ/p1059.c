//
//  p1059.c
//  HOJ
//
//  Created by cheng on 2019/7/11.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

int value[20005];
int sumValue = 0;
int total = 0;
int used[20005];

int dfs(int v) {
    if(v == sumValue/2) {
        return 1;
    }
    
    if (v > sumValue/2) {
        return 0;
    }
    
    for(int i = 0; i < total; i++) {
        if(i > 0 &&  (value[i - 1] + v) > sumValue/2 && value[i - 1] == value[i]) {
            continue;
        }
        
        if(i > 0 && !used[i - 1] && value[i - 1] == value[i]) {
            continue;
        }
        
        if(!used[i] && (value[i] + v) <= sumValue/2) {
            used[i] = 1;
            if(dfs(value[i] + v)) {
                return 1;
            }
            used[i] = 0;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int a, b, c, d, e, f;
    int k = 0;
    while(scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f)!= EOF) {
        if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
            break;
        }
        k++;
//        memset(value, 0, sizeof(value));
        for (int i = 0; i < (a + b + c + d + e +f); i++) {
            if (i < a) {
                value[i] = 1;
            } else if (i < (a + b)) {
                value[i] = 2;
            } else if (i < (a + b + c)) {
                value[i] = 3;
            } else if (i < (a + b + c + d)) {
                value[i] = 4;
            } else if (i < (a + b + c + d + e)) {
                value[i] = 5;
            } else {
                value[i] = 6;
            }
            used[i] = 0;
        }
        total = a + b + c + d + e + f;
        sumValue = a + 2 * b + 3 * c + 4 * d + 5 * e + 6 * f;
        printf("Collection #%d:\n", k);
        if(sumValue%2 == 1) {
            printf("Can't be divided.");
        } else {
            if(dfs(0)) {
                printf("Can be divided.\n");
            } else {
                printf("Can't be divided.\n");
            }
        }
        
    }
    
    return 0;
}
