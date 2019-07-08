//
//  p1052.c
//  HOJ
//
//  Created by cheng on 2019/7/5.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

int a[1005];
int b[1005];

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
        while ( i < j && key >= a[i]) {
            i++;
        }
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    a[left] = a[i];
    a[i] = key;
    quicksort(a, left, i - 1);
    quicksort(a, i + 1, right);
}



int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n)) {
        if(n == 0) {
            break;
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        quicksort(a, 0, n - 1);
        quicksort(b, 0, n - 1);
        
        int sum = 0;
        int aslow = 0, afast = n - 1;
        int bslow = 0, bfast = n - 1;
        for(int i = 0; i < n; i++) {
            if(a[aslow] > b[bslow]) {
                sum += 200;
                aslow++;
                bslow++;
            } else if(a[aslow] < b[bslow]) {
                sum -= 200;
                aslow++;
                bfast--;
            } else {
                if(a[afast] > b[bfast]) {
                    sum += 200;
                    afast--;
                    bfast--;
                } else if(a[aslow] < b[bfast]) {
                    sum -= 200;
                    aslow++;
                    bfast--;
                }
            }
        }
        printf("%d\n", sum);
     
    }
    return 0;
}
