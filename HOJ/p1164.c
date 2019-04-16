//
//  p1164.c
//  HOJ
//
//  Created by cheng on 2018/10/11.
//  Copyright © 2018 dev. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define MAX 70000
int prime[MAX + 1];
int a[MAX + 1];
int len = 0;
void setPrime() {
    int k = 0;
    prime[k] = 2;
    for(int i = 3; i <= MAX; i+=2) {
        a[i] = 0;
    }
    for(int i = 3; i <= sqrt(MAX + 0.5); i+=2) {
        if(a[i] == 0) {
            for(int j=i*i;j<=MAX;j+=i*2)
                a[j]=1;
        }
    }
    for(int i=3;i<=MAX;i+=2)
        if(a[i]==0)
            prime[++k]=i;

    len = k;
}

int main(int argc, const char * argv[]) {
    setPrime();
    int n;
    while(scanf("%d", &n) != EOF) {
        int m = n;
        int i = 0;
        int ret[60000] = {0};
        int j = 0;
        while(i < len) {
            if(n%prime[i] == 0) {
                n = n/prime[i];
                ret[j] = prime[i];
                j++;
                i = 0;
            } else {
                i++;
            }
        }
        if(n == 1) {
            for(int i = 0; i < j; i++) {
                if(i == (j-1)) {
                     printf("%d", ret[i]);
                } else {
                     printf("%d*", ret[i]);
                }
            }
            printf("\n");
        } else {
            printf("%d\n", m);
        }
        
    }
    return 0;
}

