//
//  p1031.c
//  HOJ
//
//  Created by dev on 2018/1/29.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

float a[1000];
float b[1000];
float c[1000];
int d[1000];
int visit[1000];

void quicksort(float *a, int left, int right) {
    if(left >= right) {
        return;
    }
    int i = left;
    int j = right;
    float key = a[i];
    while(i < j) {
        while(i < j && key <= a[j]) {
            j--;
        }
        while ( i < j && key >= a[i]) {
            i++;
        }
        float tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    a[left] = a[i];
    a[i] = key;
    quicksort(a, left, i - 1);
    quicksort(a, i + 1, right);
}

void quicksort1(int *a, int left, int right) {
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
    int N,M,K = 0;
    while(scanf("%d %d %d",&N,&M,&K) != EOF) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        memset(visit, 0, sizeof(visit));
        float tmp;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                scanf("%f", &tmp);
                a[j] += tmp;
                b[j] += tmp;
            }
        }
        
        // 快速排序
        quicksort(a, 0, M - 1);

        for (int i = M - 1 - K; i < M; i++) {
            c[M - 1 - i] = a[i];
        }
        int j = 0;
        while(j < K) {
            for(int i = 0; i < M; i++) {
                if(!visit[i] && c[j] == b[i]) {
                    d[j] = i;
                    j++;
                    visit[i] = 1;
                }
            }
        }
        quicksort1(d, 0, K - 1);
        for(int i = 0; i < K; i++) {
            if((K - 1 - i) == 0) {
                printf("%d", d[K - 1 - i] + 1);
            } else {
                printf("%d ", d[K - 1 - i] + 1);
            }
            
        }
        
        printf("\n");
    }
    
}
