//
//  2_3_4.c
//  HOJ
//
//  Created by dev on 2018/2/28.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n,i,j,k;
    int a[1000] = {0};
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("n = %d\n",n);
    int dp[1000] = {0};
    for(i = 0; i < n; i++) {
        for(j = i + 1;j < n; j++) {
            if(a[j] > a[i] && dp[j] < (dp[i] + 1)) {
                dp[j] = dp[i] + 1;
            }
        }
    }
    int max = dp[0];
    for(i = 1; i < n; i++) {
        if (max < dp[i]) {
            max = dp[i];
        }
    }
    printf("%d\n",max + 1);
    return 0;
}
