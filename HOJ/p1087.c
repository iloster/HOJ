//
//  p1087.c
//  HOJ
//
//  Created by cheng on 2019/7/8.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

int N;
int Value[1005];
int dp[1005];

int max(int a, int b) {
    return a > b? a: b;
}

int main(int argc, const char * argv[]) {
    while(scanf("%d", &N)) {
        if(N == 0) {
            break;
        }
        
        for(int i = 0; i < N; i++) {
            scanf("%d", &Value[i]);
            dp[i] = Value[i];
        }
        
        int sum = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < i; j++) {
                if(Value[i] > Value[j]) {
                    dp[i] = max(dp[i], dp[j] + Value[i]);
                }
            }
        }
        int max = 0;
        for(int i = 0; i < N; i++) {
            if(dp[i] >= max) {
                max = dp[i];
            }
        }
        printf("%d\n", max);
        
    }
    
}
