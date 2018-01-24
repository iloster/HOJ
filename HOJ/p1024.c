//
//  p1024.c
//  HOJ
//
//  Created by cheng on 2018/1/24.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

// i < j
void dp(int left, int right, int a[]) {
    int sum = 0;
    int i = 0;
    for (i = left; i < right; i++) {
        sum = sum + a[i];
    }
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int len = 6;
//    scanf("%d",&len);
    int i = 0;
    int a[6] = {5,3,4,8,6,7};
    int b[6] = {0,0,0,0,0,0};
    int j = 0;
    for(i = 0; i < len; i++) {
        int max = a[i];
        for(j = i; j < len; j++) {
            if (a[j] >= max) {
                max = a[j];
                b[i]++;
            }
        }
    }
    int max = b[0];
    for(i = 1;i < 6; i++) {
        if(b[i] > max) {
            max = b[i];
        }
    }
    printf("max=%d\n",max);
    
    
}
