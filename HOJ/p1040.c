//
//  p1040.c
//  HOJ
//
//  Created by dev on 2018/2/2.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

int a[1000][1000] = {0};

void sort(int *a,int _left, int _right) {
        
    int left = _left;
    int right = _right;
    int temp = 0;
    if(left <= right){   //待排序的元素至少有两个的情况
        temp = a[left];  //待排序的第一个元素作为基准元素
        while(left != right){   //从左右两边交替扫描，直到left = right
            
            while(right > left && a[right] >= temp)
                right --;        //从右往左扫描，找到第一个比基准元素小的元素
            a[left] = a[right];  //找到这种元素arr[right]后与arr[left]交换
            
            while(left < right && a[left] <= temp)
                left ++;         //从左往右扫描，找到第一个比基准元素大的元素
            a[right] = a[left];  //找到这种元素arr[left]后，与arr[right]交换
            
        }
        a[right] = temp;    //基准元素归位
        sort(a,_left,left-1);  //对基准元素左边的元素进行递归排序
        sort(a,right+1,_right);  //对基准元素右边的进行递归排序
    }
}

void print(int *a,int n) {
    int i;
    for(i = 1; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n]);
}
int main(int argc, const char * argv[]) {
    int m,n;
    int i;
    int j;
    scanf("%d",&m);
    if(m > 0 ) {
        for(j = 0; j < m; j++) {
            scanf("%d", &a[j][0]);
//            printf("n = %d\n",a[j][0]);
            for(i = 1; i <= a[j][0]; i++) {
                scanf("%d", &a[j][i]);
            }
            // 排序
//            print(n);
            sort(a[j],1,a[j][0]);
            print(a[j],a[j][0]);
        }
//        for(j = 0; j < m; j++) {
//            print(a[j],a[j][0]);
//        }
    }
    
    return 0;
}
