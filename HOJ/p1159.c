//
//  p1159.c
//  HOJ
//
//  Created by dev on 2018/2/28.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    char a[1000],b[1000];
    while(scanf("%s%s", a, b)!=EOF) {
        int m = strlen(a);
        int n = strlen(b);
    //    printf("%d %d\n",m,n);
        int i,j;
        int dp[1000][1000] = {0};
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(a[i] == b[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
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
