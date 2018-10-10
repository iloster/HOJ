//
//  p1423.c
//  HOJ
//
//  Created by cheng on 2018/3/1.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n,m,s,i,j;
    scanf("%d", &n);
    int a[505] = {0};
    int b[505] = {0};
    
    while(n--) {
        int dp[505][505] = {0};
        scanf("%d", &m);
        for(i = 0; i < m; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &s);
        for(i = 0; i < s; i++) {
            scanf("%d", &b[i]);
        }
        for(i = 0; i < m; i++) {
            for(j = 0; j < s; j++) {
                if(a[i] == b[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    if(dp[i][j+1] > dp[i+1][j]) {
                         dp[i+1][j+1] = dp[i][j+1];
                    } else {
                         dp[i+1][j+1] = dp[i+1][j];
                    }
                }
            }
        }
        printf("%d\n",dp[m][s]);
    }
}
