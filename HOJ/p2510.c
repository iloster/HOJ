//
//  main.c
//  ZOJ
//
//  Created by dev on 2018/1/19.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

int n;
int num;
int num1; // "+"
int num2; // "-"
int a[30];

int check(int *a, int len) {
    if(len == 1) {
        if(a[0] == '+') {
            num1++;
        }
        if(a[0] == '-') {
            num2++;
        }
        return num1 == num2;
    }
    int b[30];
    for(int i = 0; i < len - 1; i++) {
        if(a[i] == '+') {
            num1++;
        } else {
            num2++;
        }
        if(a[i] == a[i + 1]) {
            b[i] = '+';
        } else {
            b[i] = '-';
        }
    }
    if(a[len - 1] == '+') {
        num1++;
    } else {
        num2++;
    }
    return check(b, len - 1);
}

void dfs(int depth) {
    if(depth == n) {
        num1 = 0;
        num2 = 0;
        if(check(a, n)) {
            num++;
        }

        return;
    }

    a[depth] = '-';
    dfs(depth + 1);
    
    a[depth] = '+';
    dfs(depth + 1);

}

//1:0  2:0  3:4  4:6 5:0   6:0  7:12  8:40 9:0 10:0  11:171  12:410
//13:0  14:0 15:1896   16:5160  17:0  18:0  19:32757  20: 59984  21:0
//22:0   23:431095    24:822229
int main(int argc, const char * argv[]) {
    int map[30] = {0};
    map[3] = 4;
    map[4] = 6;
    map[7] = 12;
    map[8] = 40;
    map[11] = 171;
    map[12] = 410;
    map[15] = 1896;
    map[16] = 5160;
    map[19] = 32757;
    map[20] = 59984;
    map[23] = 431095;
    map[24] = 822229;
    while(scanf("%d", &n)) {
        if(n == 0) {
            break;
        }
        
//        num = 0;
//        int sum = 0;
//        for(int i = 1; i <= n; i++) {
//            sum += i;
//        }
//        if(sum%2 == 0) {
//            dfs(0);
//            printf("%d %d\n", n ,num);
//        } else {
//            printf("%d %d\n", n , 0);
//        }
        printf("%d %d\n", n ,map[n]);
    }
    return 0;
}

