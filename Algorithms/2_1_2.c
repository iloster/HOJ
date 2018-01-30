//
//  2_1_2.c
//  HOJ
//
//  Created by dev on 2018/1/30.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
#include <time.h>
// 选择排序
// 排序参数 n + n-1 + n-2 + ... + 2 + 1 = (n-1)*n/2
void choose_sort(int *a, int len){
    int i = 0;
    int j = 0;
    int tmp = 0;
    for(i = 0; i < len; i++) {
        int less = a[i];
        int index = i;
        for(j = i; j < len; j++) {
            if(a[j] < less) {
                less = a[j];
                index = j;
            }
        }
        if (i != index) {
            tmp = a[i];
            a[i] = a[index];
            a[index] = tmp;
        }
    }
}

//插入排序
//
void insert_sort(int *a, int len) {
    int i = 0;
    int j = 0;
    int temp = 0;
    for(i = 1; i < len; i++) {
        for(j = i; j > 0; j--) {
            if(a[j-1] > a[j]) {
                temp = a[j-1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void print(int *a, int len) {
    int i = 0;
    for(i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    long start=clock();
    int a[14] = {1,2,5,10,7,6,3,20,25,4,5,12,31,234};
    choose_sort(a,7);
//    insert_sort(a, 13);
    double totaltime = (double)(clock() - start)/CLOCKS_PER_SEC;
    printf("total time:%f\n",totaltime);
    print(a, 14);
    return 0;
}
