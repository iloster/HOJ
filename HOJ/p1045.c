//
//  p1045.c
//  HOJ
//
//  Created by cheng on 2019/5/9.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

int n;
char map[5][5];
int visit[5][5];
int maxDepth;

int isLegel(int x, int y) {
    int a1 = -1;
    int a2 = -1;
    for(int i = 0; i < n; i++) {
        if(visit[x][i] && i != y) {
            a1 = i;
        }
        
        if(visit[i][y] && i != x) {
            a2 = i;
        }
    }
    
    if(a1 == -1 && a2 == -1) {
        return 1;
    }
    
    int minY = a1;
    int maxY = y;
    if(a1 > y) {
        maxY = a1;
        minY = y;
    }
    int flagY = 0;
    if(a1 == -1) {
        flagY = 1;
    }
    for(int i = minY; i < maxY; i++) {
        if(map[x][i] == 'X') {
            flagY = 1;
            break;
        }
    }
    
    int minX = a2;
    int maxX = x;
    if(a2 > x) {
        maxY = a2;
        minY = x;
    }
    int flagX = 0;
    if(a2 == -1) {
        flagX = 1;
    }
    for(int i = minX; i < maxX; i++) {
        if(map[i][y] == 'X') {
            flagX = 1;
            break;
        }
    }
    
    return flagX && flagY;
}

void dfs(int x, int y, int depth) {
    if(depth > maxDepth) {
        maxDepth = depth;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visit[i][j] && map[i][j] == '.' && isLegel(i, j)) {
                visit[i][j] = 1;
                dfs(i, j, depth + 1);
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
        for(int i = 0; i < n; i++) {
            getchar();
            for(int j = 0; j < n; j++) {
                scanf("%c", &map[i][j]);
                visit[i][j] = 0;
            }
        }
        maxDepth = 0;
        dfs(0, 0, 0);
        printf("%d\n", maxDepth);
    }
    return 0;
}
