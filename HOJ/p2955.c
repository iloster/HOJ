//
//  p2955.c
//  HOJ
//
//  Created by dev on 2018/3/3.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int t,n,i,j;
    float w;
    float p;
    float weight[150] = {0};
    int value[150] = {0};
    scanf("%d", &t);
    while(t--) {
        float dp[10005] = {0};
        // dp[i] 表示不被抓的概率
        scanf("%f%d", &p, &n);
        int sum = 0;
        for(i = 0; i < n; i++) {
            scanf("%d%f", &value[i], &weight[i]);
            sum += value[i];
        }
        dp[0] = 1.0;
        for(i = 0; i < n; i++) {
            for(j = sum; j >= value[i] ; j--) {
                if(dp[j] < dp[j - value[i]]*(1.0 - weight[i])) {
                    dp[j] = dp[j - value[i]]*(1.0 - weight[i]);
                }
            }
        }
//        for(i = 0; i <= sum; i++) {
//            printf("%f",dp[i]);
//        }
        for (i=sum; 1 - dp[i] >= p; i--);
        printf("%d\n", i);
    }
}
