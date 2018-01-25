//
//  p1024.c
//  HOJ
//
//  Created by cheng on 2018/1/24.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int a[1000005];

int max(int a, int b) {
    return a > b? a: b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int m = 0;
    int n = 0;
    while(scanf("%d%d",&m,&n) != EOF) {
        int dp[1000005] = {0};
        int i = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int k = 0;
        int j = 0;
        for(i = 1; i<=m; i++) {
            int tmp = 0;//dp[i][j]表示以a[j]结尾的，i个字段的最大和
            for(k = 1; k<=i; ++k) {
                tmp += a[k];
            }
            dp[n] = tmp;
            
            for(j = i + 1; j <= n; ++j) {
                tmp = max(dp[j - 1],tmp) + a[j];
                dp[j-1] = dp[n];
                dp[n] = max(dp[n], tmp);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
