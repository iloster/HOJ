//
//  p1069.c
//  HOJ
//
//  Created by cheng on 2018/10/8.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int a[180][3];
int main(int argc, const char * argv[]) {
    int line;
    int i, j, k;
    while (scanf("%d", &line) != EOF) {
        k = 0;
        for(i = 0; i < line; i++) {
            for(j = 0; j < 3; j++) {
                scanf("%d", &a[k][j]);
            }
            
            a[k + 1][0] = a[k][0];
            a[k + 1][1] = a[k][2];
            a[k + 1][2] = a[k][1];
            
            a[k + 2][0] = a[k][1];
            a[k + 2][1] = a[k][2];
            a[k + 2][2] = a[k][0];
            
            a[k + 3][0] = a[k][1];
            a[k + 3][1] = a[k][0];
            a[k + 3][2] = a[k][2];
            
            a[k + 4][0] = a[k][2];
            a[k + 4][1] = a[k][1];
            a[k + 4][2] = a[k][0];
            
            a[k + 5][0] = a[k][2];
            a[k + 5][1] = a[k][0];
            a[k + 5][2] = a[k][1];
            
            k += 6;
        }
        int m,n = 0;
        int c, ku, g;
        for(m = 0; m < k; m++) {
            for(n = m + 1; n < (k-1); n++) {
                if(a[m][2] < a[n][2]) {
                    c = a[m][0];
                    a[m][0] = a[n][0];
                    a[n][0] = c;

                    ku = a[m][1];
                    a[m][1] = a[n][1];
                    a[n][1] = ku;

                    g = a[m][2];
                    a[m][2] = a[n][2];
                    a[n][2] = g;
                }
            }
        }

        int dp[180] = {0};
//        int o = 0;
        for(j = 0; j < k; j++) {
            dp[j] = a[j][2];
            for(int o = 1; o < j; o++) {
                if(a[o][0] < a[j][0] && a[o][1] < a[j][1] && dp[j] < (dp[o] + a[o][2])) {
                    dp[j] = dp[o] + a[o][2];
                }
            }
        }
        int max = 0;
        for(j = 0; j < 180; j++) {
            if(dp[j] >= max) {
                max = dp[j];
            }
        }
        printf("Case %d: maximum height = %d\n", line, max);
        
    }
    return 0;
}
