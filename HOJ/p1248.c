//
//  p1248.c
//  HOJ
//
//  Created by dev on 2018/2/28.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int t,n;
    scanf("%d",&t);
    while(t--) {
        int dp[10000] = {0};
        scanf("%d", &n);
        int w[3] = {150,200,350};
        int v[3] = {150,200,350};
        int i,j;
        for(i = 0; i < 3; i++) {
            for(j = w[i]; j <= n; j++) {
                if(dp[j] < (dp[j - w[i]] + v[i])) {
                    dp[j] = dp[j - w[i]] + v[i];
                }
            }
        }
        printf("%d\n", n - dp[n]);
    }
}
