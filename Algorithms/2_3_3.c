//
//  2_3_3.c
//  HOJ
//
//  Created by dev on 2018/2/28.
//  Copyright © 2018年 dev. All rights reserved.
//
// 最长公共子序列问题
#include <stdio.h>

int main(int argc, const char * argv[]) {
    char a[100];
    char b[100];
    int m,n;
    scanf("%d%d",&m,&n);
    scanf("%s%s", a,b);
//    printf(")
    int i,j;
    int dp[100][100] = {0};
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
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
    printf("%d\n", dp[m][n]);
    return 0;
}
