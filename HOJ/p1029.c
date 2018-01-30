//
//  p1029.c
//  HOJ
//
//  Created by cheng on 2018/1/28.
//  Copyright © 2018年 dev. All rights reserved.
//

#include<stdio.h>
int a[1000000] = {0};
int b[1000000] = {0};
void quicksort(int *a, int left, int right) {
    if(left >= right) {
        return;
    }
    int i = left;
    int j = right;
    int key = a[i];
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
    int len;

    while(scanf("%d",&len) != EOF) {
        int i = 0;
        int j = 0;
        int t = 0;
        for(i = 0; i < len; i++) {
            scanf("%d", &t);
            a[t]++;
            if(a[t] >= (len+1)/2){
                j = t;
            }
        }
        printf("%d\n", j);
        /**
        int c = 0;
        for(i = 0; i < len; i++) {
            for (j = i + 1; j < len; j++) {
                if (a[i] > a[j]) {
                    c = a[j];
                    a[j] = a[i];
                    a[i] = c;
                }
            }
        }**/
    }
    return 0;
}
