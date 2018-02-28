//
//  test.c
//  HOJ
//
//  Created by cheng on 2018/1/25.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
#include <string.h>
char *left_str = "(";
char *right_str = ")";
//char init[100] = "";
void gen(int left, int right, char *str) {
    if(left >= right) {
        if(left == 0 && right == 0) {
            printf("%s\n",str);
        } else {
            if(left > 0) {
                gen(left - 1,right,strcat(str ,"("));
            }
            if(right > 0) {
                gen(left, right - 1, strcat(str , ")"));
            }
        }
    }
    
    
}

void quicksort(int left, int right, int *a) {
    if (left >= right) {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[i];
    while(i < j) {
        while(i < j && a[j] > key) {
            j--;
        }
        while(i < j && a[i] < key) {
            i++;
        }
        int tmp;
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
//    a[i] = key;
    quicksort(left, i - 1, a);
    quicksort(i + 1, right, a);
}

int n = 6;
int a[6] = {5, 10, 9 ,8, 7,11};
int total = 7;
int dfs(int sum, int i) {
    if(i == n) {
        printf("sum = %d\n",sum);
        return sum == total? 1: 0;
    }
    if(dfs(sum , i + 1)) {
        return 1;
    }
    if(dfs(sum + a[i], i + 1)) {
        return 1;
    }
    return 0;
}



int main(int argc, const char * argv[]) {
//    char init[100] = "";
//    gen(3,3,init);
//    printf("%s\n",strcat(init, left_str));
    
//    quicksort(0,5,a);
//    int i = 0;
//    for(i = 0; i < 6; i++) {
//        printf("%d ",a[i]);
//    }
    printf("%d\n",dfs(0,0));
//    printf("\n");
    return 0;
}
