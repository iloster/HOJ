//
//  p2546.c
//  HOJ
//
//  Created by dev on 2018/3/3.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n,m,i,j;
    while(scanf("%d", &n)) {
        if(n == 0) {
            break;
        }
        int value[1010] = {0};
        for(i = 0; i < n; i++) {
            scanf("%d", &value[i]);
        }
        scanf("%d", &m);
        int dp[1010];
        for(i = 0; i<=m; i++) {
            dp[i] = m;
        }
        // dp代表卡上余额
        int tmp = m;
        for(i = 0; i < n; i++) {
//            printf("%d\n",value[i]);
            if(value[i] > m) {
                if(m >= 5 && (m - value[i]) < tmp) {
                    tmp = m - value[i];
                }
            } else {
                for(j = value[i]; j <= m; j++) {
//                    printf("%d  %d %d\n",j,dp[j],value[i]);
                    if(dp[j] >= 5) {
                        dp[j] = dp[j] - value[i];
                    }
                }
            }
        }
    
        if (tmp < dp[m]) {
            printf("%d\n",tmp);
        } else {
            printf("%d\n",dp[m]);
        }
    }
}
