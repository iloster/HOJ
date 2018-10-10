//
//  p1058.c
//  HOJ
//
//  Created by cheng on 2018/10/8.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
#include <math.h>
long b[6000];
const int maxn = 2000000000;

void quicksort(long *a, int left, int right) {
    if(left >= right) {
        return;
    }
    int i = left;
    int j = right;
    long key = a[i];
    while(i < j) {
        while(i < j && key <= a[j]) {
            j--;
        }
        while ( i<j && key >= a[i]) {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = key;
    quicksort(a, left, i - 1);
    quicksort(a, i + 1, right);
}

int main(int argc, const char * argv[]) {
    int i,j,k,l,m = 0;
    for(i = 0; i <=31 && pow(2,i) <= maxn; i++) {
        for(j = 0; j <= 20 && pow(2,i) * pow(3, j) <= maxn; j++) {
            for(k = 0; j <= 20 &&  pow(2,i) * pow(3, j) * pow(5, k) <= maxn; k++) {
                for(l = 0; l <= 20 && pow(2,i) * pow(3, j) * pow(5, k) * pow(7, l) <= maxn; l++) {
                    b[m] = pow(2,i) * pow(3, j) * pow(5, k) * pow(7, l);
                    m++;
                }
            }
        }
    }
//    printf("m = %d\n", m);
    // 排序
//    quicksort(b, 1,m - 1);
//    quicksort(a, m/2,m - 1);
    long tmp = 0;
    for(i = 0; i <= (m + 1); i++) {
        for(j = i+1; j <= (m ); j++) {
            if(b[i] > b[j]) {
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }
    int t;
    while(~scanf("%d", &t), t)
    {
        printf("The %d", t);
        if(t%10 == 1 && t%100 != 11) printf("st ");
        else if(t%10 == 2 && t%100 != 12) printf("nd ");
        else if(t%10 == 3 && t%100 != 13) printf("rd ");
        else printf("th ");
        printf("humble number is %d.\n", b[t]);
    }
    return 0;
}
