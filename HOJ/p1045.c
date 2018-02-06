//
//  p1045.c
//  HOJ
//
//  Created by dev on 2018/2/6.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
char ch[10][10];
int maxCount = 0;
int isLegal(int i, int j, int n) {
    int k;
    for(k = i+1; k < n; k++) {
        if(ch[k][j] == 'X') {
            break;
        }
        
        if (ch[k][j] == 'a') {
            return 0;
        }
    }
    
    for(k = i-1; k >= 0; k--) {
        if(ch[k][j] == 'X') {
            break;
        }
        if (ch[k][j] == 'a') {
            return 0;
        }
    }
    
    for(k = j+1; k < n; k++) {
        if(ch[i][k] == 'X') {
            break;
        }
        
        if (ch[i][k] == 'a') {
            return 0;
        }
    }
    
    for(k = j-1; k >= 0; k--) {
        if(ch[i][k] == 'X') {
            break;
        }
        if (ch[i][k] == 'a') {
            return 0;
        }
    }
    
    return 1;
}

void search(int n, int k, int curCount) {
    int x,y;
    if(k == n*n) {
        if(curCount > maxCount) {
            maxCount = curCount;
        }
        return;
    } else {
        x = k/n;
        y = k%n;
        if(ch[x][y] == '.' && isLegal(x, y, n)) {
            ch[x][y] = 'a';
            search(n, k + 1, curCount + 1);
            ch[x][y] = '.';
        }
        search(n, k + 1, curCount);
    }
    
}

int main(int argc, const char * argv[]) {

    int n;
    int i;
    while(scanf("%d", &n) != EOF) {
        if(n == 0) {
            break;
        }
        for(i = 0; i < n; i++) {
            scanf("%s", ch[i]);
        }

        maxCount = 0;
        search(n, 0, 0);
        
        printf("%d\n",maxCount);
        
    }
    return 0;
}
