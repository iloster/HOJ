//
//  p1010.c
//  HOJ
//  深搜
//  Created by cheng on 2019/5/8.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>
#include<math.h>

char maze[10][10];
int visit[10][10];
int startX = 0, startY = 0, endX = 0, endY = 0;
int n, m, step;


int dfs(int depth, int x, int y) {
//    printf("depth: %d x: %d y: %d\n", depth,block.x, block.y);
    if(depth == step) {
        if(x == endX && y == endY) {
            return 1;
        }
    } else if(depth < step) {
        if(maze[x][y] == 'D') {
            return 0;
        }
        
        if(x - 1 >= 0 && !visit[x - 1][y] && maze[x - 1][y] != 'X') {
            visit[x - 1][y] = 1;
            if(!dfs(depth + 1, x - 1, y)) {
                 visit[x - 1][y] = 0;
            } else {
                return 1;
            }
        }
        
        if(x + 1 < n && !visit[x + 1][y] && maze[x + 1][y] != 'X') {
            visit[x + 1][y] = 1;
            if(!dfs(depth + 1, x + 1, y)) {
                visit[x][y] = 0;
            } else {
                return 1;
            }
        }
        
        if( y - 1 >= 0 && !visit[x][y - 1] && maze[x][y - 1] != 'X') {
            visit[x][y - 1] = 1;
            if(!dfs(depth + 1, x, y - 1)) {
                visit[x][y - 1] = 0;
            } else {
                return 1;
            }
        }
        
        if(y + 1 < m && !visit[x][y + 1] && maze[x][y + 1] != 'X') {
            visit[x][y + 1] = 1;
            if(!dfs(depth + 1, x, y + 1)) {
                visit[x][y + 1] = 0;
            } else {
                return 1;
            }
        }
        
    }
    return 0;
}


int main(int argc, const char * argv[]) {

    while(scanf("%d%d%d", &n, &m, &step)) {
        if(n == 0 || m == 0 || step == 0) {
            break;
        }
        for(int i = 0; i < n; i++) {
            scanf("%s", maze[i]);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; i < m; j++) {
                visit[i][j] = 0;
                if(maze[i][j] == 'S') {
                    startX = i;
                    startY = j;
                }
                if(maze[i][j] == 'D') {
                    endX = i;
                    endY = j;
                }
            }
        }
        
        // 寻找最短路径
//        printf("%d", abs(startX - endX) + abs(startY - endY));
        if((abs(startX - endX) + abs(startY - endY)) %2 == step % 2) {
            visit[startX][startY] = 1;
            if(dfs(0, startX, startY)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            printf("NO\n");
        }
 
    }
    return 0;
}
