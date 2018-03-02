//
//  p1114.c
//  HOJ
//
//  Created by dev on 2018/3/2.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
#define INF 0x7fffffff
int main(int argc, const char * argv[]) {
    int t,e,f,n,i,j;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d",&e,&f);
        scanf("%d", &n);
        int weight[505] = {0};
        int value[505] = {0};
        int dp[10005] = {0};
        for(i = 0; i < n; i++) {
            scanf("%d%d", &value[i], &weight[i]);
        }
        for(i = 0; i <= (f-e); i++) {
            dp[i] = INF;
        }
        dp[0] = 0;
        for(i = 0; i < n; i++) {
            for(j = weight[i]; j <= (f-e); j++) {
                if(dp[j - weight[i]] != INF && dp[j] > (dp[j - weight[i]] + value[i])) {
                    dp[j] = dp[j - weight[i]] + value[i];
                }
            }
        }
        if(dp[f-e] != INF) {
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[f-e]);
        } else {
//            printf("%d\n", dp[f-e]);
            printf("This is impossible.\n");
        }
    }
}
