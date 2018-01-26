//
//  p1026.c
//  HOJ
//
//  Created by dev on 2018/1/26.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int a[5][5] = {{1,0,1,1,1},{1,1,1,1,1},{0,0,0,0,1},{0,0,0,0,1},{0,0,0,0,1}};
int b[5][5] = {{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};


int main(int argc, const char * argv[]) {
   /**
    int i = 0;
    int j = 0;
    int k = 0;
    int flag = 1;
    int time = 0;
    while(flag && time <= 4) {
        for(k = 0; k < 4; k++) {
            if(k == 1 && (i+1 < 5)) {
                if(a[i+1][j] == 1 && b[i+1][j] != 1) {
                    i++;
                    printf("i=%d,j=%d\n",i,j);
                    b[i][j] = 1;
                    time = 0;
                } else {
                    time++;
                }
            }
            
            if(k == 2 && (j+1 < 5)) {
                if(a[i][j+1] == 1&& b[i][j+1] != 1) {
                    j++;
                    printf("i=%d,j=%d\n",i,j);
                    b[i][j] = 1;
                    time = 0;
                } else {
                    time++;
                }
            }
            
            if(k == 3 && (i-1 >= 0)) {
                if(a[i-1][j] == 1 && b[i-1][j] != 1) {
                    i--;
                    printf("i=%d,j=%d\n",i,j);
                    b[i][j] = 1;
                    time = 0;
                } else {
                    time++;
                }
            }
          
            if(k == 4 && (j - 1 >= 0)) {
                if(a[i][j-1] == 1 && b[i][j-1] != 1) {
                    j--;
                    printf("i=%d,j=%d\n",i,j);
                    b[i][j] = 1;
                    time = 0;
                } else {
                    time++;
                }
            }
            if (i== 5 && j == 5) {
                flag = 0;
            }
        }
    }
    if(time>4) {
        printf("failed\n");
    } else {
        printf("success\n");
    }
    **/
    return 0;
}
