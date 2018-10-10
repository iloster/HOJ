//
//  2_3_2.c
//  HOJ
//
//  Created by dev on 2018/2/28.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int weight[1010] = {0};
int v[1010] = {0};


void solve(int n, int w) {
    int dp[1010] = {0};
    int i,j;
    for(i = 0; i < n; i++) {
        for(j = w; j >= weight[i]; j--) {
            if((dp[j - weight[i]] + v[i]) > dp[j]) {
                dp[j] = dp[j - weight[i]] + v[i];
            }
        }
    }
    printf("%d\n", dp[w]);
}

void solve1(int n, int w) {
    int dp[1010] = {0};
    int i,j;
    for(i = 0; i < n; i++) {
        for(j = weight[i]; j <= w; j++) {
            if((dp[j - weight[i]] + v[i]) > dp[j]) {
                dp[j] = dp[j - weight[i]] + v[i];
            }
        }
    }
    printf("%d\n", dp[w]);
}

int main(int argc, const char * argv[]) {
    int i,j;
    int n,w,t;
    scanf("%d", &t);
    for(i = 0; i < t; i++) {
        scanf("%d%d", &n, &w);
        for(j = 0; j < n; j++) {
            scanf("%d", &v[j]);
        }
        for(j = 0; j < n; j++) {
            scanf("%d", &weight[j]);
        }
        solve1(n, w);
    }
    return 0;
}
