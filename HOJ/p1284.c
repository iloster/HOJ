//
//  p1284.c
//  HOJ
//
//  Created by dev on 2018/3/2.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n,i,j,k;
    while(scanf("%d", &n) != EOF) {
        int weight[3] = {1,2,3};
        int dp[32769] = {0};
        dp[0] = 1;
        for(i = 0; i < 3; i++) {
            for(j = weight[i]; j <= n; j++) {
                dp[j] += dp[j - weight[i]];
            }
        }
        printf("%d\n",dp[n]);
    }
}
