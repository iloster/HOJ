//
//  main.c
//  HOJ
//
//  Created by cheng on 2019/5/13.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

int n;
int visit[15][15];
int num ;
// x, y 为当前位置

int check(int x, int y) {
    //水平线
    for(int i = 0; i < n; i++) {
        if(visit[i][y] && x != i) {
            return 0;
        }
    }
    for(int i = 0; i < n; i++) {
        if(visit[x][i] && y != i) {
            return 0;
        }
    }
    // 斜线
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != x && j != y && abs(i - x) == abs(j - y) && visit[i][j]) {
                return 0;
            }
        }
    }
    
    return 1;
}


void dfs(int depth) {
    if(depth == n) {
        num++;
        return;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visit[i][j] && check(i, j)) {
                visit[i][j] = 1;
                dfs(depth + 1);
                visit[i][j] = 0;
            }
        }
    }
}

int main(int argc, char * argv[]) {
    while(scanf("%d", &n)) {
        if(n == 0) {
            break;
        }
        dfs(0);
        printf("%d\n", num);
    }
    
    return 0;
}
