//
//  p1241.c
//  HOJ
//
//  Created by cheng on 2019/5/8.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

char map[105][105];
int m, n;

void dfs(int x, int y) {
    if(map[x][y] == '@') {
        map[x][y] = '*';
        if(x - 1 >= 0) {
            dfs(x - 1, y);
        }
        
        if(x + 1 < m) {
            dfs(x + 1, y);
        }
        
        if(y - 1 >= 0) {
            dfs(x, y - 1);
        }
        
        if(y + 1 < n) {
            dfs(x, y + 1);
        }
        
        if(x - 1 >= 0 && y - 1 >= 0) {
            dfs(x - 1, y - 1);
        }
        
        if(x - 1 >= 0 && y + 1 < n) {
            dfs(x - 1, y + 1);
        }
        
        if(x + 1 < m && y - 1 >= 0) {
            dfs(x + 1, y - 1);
        }
        
        if(x + 1 < m && y + 1 < n) {
            dfs(x + 1, y + 1);
        }
    }
}

int main(int argc, const char * argv[]) {
    while(scanf("%d%d", &m, &n)) {
        if(m == 0 || n == 0) {
            break;
        }
        for(int i = 0; i < m; i++) {
            getchar();
            for(int j = 0; j < n; j++) {
                scanf("%c", &map[i][j]);
            }
        }
        
        int num = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(map[i][j] == '@') {
                    dfs(i, j);
                    num++;
                }
            }
        }
        printf("%d\n", num);
        
    }
    
    return 0;
}
