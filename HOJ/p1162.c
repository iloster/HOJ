//
//  p1162.c
//  HOJ
//
//  Created by cheng on 2018/10/10.
//  Copyright © 2018年 dev. All rights reserved.
//


#include <stdio.h>
#include <math.h>

double x[105];
double y[105];
double map[105][105];

double dfs(int i, int len, int dp[], double distance) {
    double min = -1;
    int index = -1;
    for(int j = 0; j < len; j++) {
        // 找到最短的点, 每次都是找最短的点
        if(dp[j] == 0 && i != j) {
            if(min == -1) {
                min = map[i][j];
                index = j;
            } else {
                if(map[i][j] < min) {
                    min = map[i][j];
                    index = j;
                }
            }
        }
    }
    if(index != -1) {
        dp[index] = 1;
        distance += min;
        return dfs(index, len, dp, distance);
    } else {
        return distance;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%lf%lf", &x[i], &y[i]);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                map[i][j] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
            }
        }
        
        int dp[105] = {0};
        dp[0] = 1;
        
        printf("%.2lf\n", dfs(0, n, dp, 0));

    }
    return 0;
}


