//
//  p1023.c
//  HOJ
//
//  Created by cheng on 2018/1/24.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int a[105][105];
int b[105];
void catalan() {
    int i, j, len, carry, temp;
    a[1][0] = b[1] = 1;
    len = 1;
    for (i = 2; i <= 100; i++) {
        for (j = 0; j < len; j++) {
            a[i][j] = a[i-1][j]*(4*i - 2);
        }
        carry = 0;
        for (j = 0; j < len; j++) {
            temp = a[i][j] + carry;
            a[i][j] = temp%10;
            carry = temp/10;
        }
        // 进位处理
        while(carry > 0) {
            // 如果有进位
            a[i][len++] = carry%10;
            carry/=10;
        }
        carry = 0;
        for(j = len -1; j>=0;j--) {
            temp = carry*10 + a[i][j];
            a[i][j] = temp/(i+1);
            carry = temp%(i+1);
        }
        while(!a[i][len-1]) {
            len --;
        }
        b[i] = len;
    }
}

int main(int argc, const char * argv[]) {
    int len = 0;
    int i = 0;
    catalan();
    while(scanf("%d",&len) != EOF) {
        //
//        printf("%d\n",f(len));
        for(i = b[len]-1; i>=0; i--)
        {
            printf("%d", a[len][i]);
        }
        printf("\n");
    }
    return 0;
}
