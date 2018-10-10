//
//  p1243.c
//  HOJ
//
//  Created by dev on 2018/2/28.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(int argc, const char * argv[]) {
    int t,m,n;
    while(scanf("%d", &t) != EOF) {
        char a[50];
        char b[2007];
        char c[2007];
        int gold[2007] = {0};
        int dp[2007][2007] = {0};
        int i,j;
        scanf("%s", a);
        for(i = 0; i < t; i++) {
            scanf("%d", &gold[a[i] - 'a']);
        }
        scanf("%s%s",b,c);
        m = strlen(b);
        n = strlen(c);
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(b[i] == c[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + gold[b[i] - 'a'];
                } else {
                    if(dp[i+1][j] > dp[i][j+1]) {
                        dp[i+1][j+1] = dp[i+1][j];
                    } else {
                        dp[i+1][j+1] = dp[i][j+1];
                    }
                }
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
