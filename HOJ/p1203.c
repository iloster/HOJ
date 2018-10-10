//
//  p1203.c
//  HOJ
//
//  Created by cheng on 2018/3/1.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {

    int m,n,i,j;
    while(scanf("%d%d",&n,&m)){
        if(n == 0 && m ==0){
            break;
        }
        int weight[100010] = {0};
        float value[100010] = {0};
        float dp[100010] = {0};
        for(i = 0; i < m; i++) {
            
            scanf("%d%f", &weight[i],&value[i]);
//            printf("w = %d v = %f\n",weight[i],value[i]);
        }
        for(i = 0; i <= n; i++) {
            dp[i] = 1;
        }
        for(i = 0; i < m; i++) {
            for(j = n; j >= weight[i]; j--) {
                if(dp[j] > dp[j - weight[i]] * (1 - value[i])) {
                    dp[j] = dp[j - weight[i]] * (1- value[i]);
                }
            }
        }
        printf("%0.1f%%\n",(1 - dp[n])*100);
        
    }
    
}
