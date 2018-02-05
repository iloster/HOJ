//
//  p1042.c
//  HOJ
//
//  Created by dev on 2018/2/3.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
/**
const int MAXN=40000;//如果是10000的阶乘，改为40000就够了
int f[40000] = {0};
int main(int argc, const char * argv[]) {
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        f[0]=1;
        for(i=2;i<=n;i++)
        {
            int c=0;
            for(j=0;j<MAXN;j++)
            {
                int s=f[j]*i+c;
                f[j]=s%10;
                c=s/10;
            }
        }
        for(j=MAXN-1;j>=0;j--)
            if(f[j]) break;//忽略前导0
        for(i=j;i>=0;i--)  printf("%d",f[i]);
        printf("\n");
    }
}**/

/**
int MAX_SIZE = 40000;
int a[40000][40000] = {0};
void print(int index ,int n) {
    int i = 0;
    for( i = 0; i<=n; i++) {
        printf("%d",a[index][i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    int n;
    int i,j;
    a[1][0] = 1;
    a[1][1] = 1;
    int len = 1;
    for(i = 2; i <= 10000; i++) {
        int tmp = 0;
        for(j = 1; j <= len; j++) {
            tmp += a[i-1][j]*i;
            a[i][j] = tmp%10;
            tmp = tmp/10;
        }
        while(tmp != 0) {
            len++;
            a[i][len] = tmp%10;
            tmp = tmp/10;
        }
        a[i][0] = len;
    }
   
    while(scanf("%d", &n) != EOF) {
        if(n == 0) {
            printf("0\n");
        } else {
            for(i = a[n][0]; i > 0; i--) {
                printf("%d",a[n][i]);
            }
            printf("\n");
        }
    }
}**/
