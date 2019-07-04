//
//  p1044.c
//  HOJ
//
//  Created by cheng on 2019/5/30.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>
int n ;
int W, H, L, M;
int value[15] = {0};
char map[55][55];
int dis[15][15];
int flag[15];
int mov[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int max = -1;
int maxValue = 0;
struct Node {
    int x;
    int y;
};

void bfs(int x, int y, int index) {
    
    int head = 0;
    int tail = 1;
    struct Node nodes[100];
    struct Node node = {x, y};
    nodes[0] = node;
    int visited[55][55] = {0};
    int step[55][55];
    visited[x][y] = 1;
    step[x][y] = 0;
    while (head != tail) {
        struct Node cur = nodes[head];
        
        for(int i = 0; i < 4; i++) {
            int xx = cur.x + mov[i][0];
            int yy = cur.y + mov[i][1];
            if(xx < 0 || xx >= H || yy < 0 || yy >= W) continue;
            if(map[xx][yy] == '*' || visited[xx][yy]) continue;
            
            visited[xx][yy] = 1;
            step[xx][yy] = step[cur.x][cur.y] + 1;
            
            if(map[xx][yy] == '@') {
                dis[index][0] = step[xx][yy];
            } else if(map[xx][yy] == '<') {
                dis[index][M + 1] = step[xx][yy];
            } else if(map[xx][yy]>='A' && map[xx][yy]<='J') {
                dis[index][map[xx][yy] - 'A' + 1] = step[xx][yy];
            }
           
            
            struct Node n = {xx, yy};
            nodes[tail] = n;
            tail++;
            
        }
        head++;
    }
}

void dfs(int s, int val, int time) {
    if(time > L || val == maxValue) {
        return;
    }
    if(s == M + 1) {
        if(max < val) {
            max = val;
        }
        return;
    }
    for(int i = 0; i <= M + 1; i++) {
        if(dis[s][i] == 0 || flag[i]) {
            continue;
        }
        flag[i] = 1;
        dfs(i, value[i] + val, time + dis[s][i]);
        flag[i] = 0;
    }
    
}

int main(int argc, const char *argv[]) {
    scanf("%d", &n);
    int iCase = 0;
    while(n--) {
        iCase++;
        max = -1;
        maxValue = 0;
        memset(dis, 0, sizeof(dis));
        memset(flag, 0, sizeof(flag));
        memset(map, 0, sizeof(map));
        memset(value, 0, sizeof(value));
        
        scanf("%d %d %d %d", &W, &H, &L, &M);
        for(int i = 1; i < M; i++) {
            scanf("%d", &value[i]);
            maxValue += value[i];
        }
        value[0] = value[M + 1] = 0;
        for(int i = 0; i < H; i++) {
            getchar();
            for(int j = 0; j < W; j++) {
                scanf("%c", &map[i][j]);
            }
        }
        
        
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(map[i][j] == '@') {
                    // 起点
                    bfs(i, j, 0);
                } else if (map[i][j] == '<') {
                    // 终点
                    bfs(i, j, M + 1);
                } else {
                    if(map[i][j] != '*' && map[i][j] != '.') {
                        bfs(i, j, map[i][j] - 'A' + 1);
                    }
                }
            }
        }
        
        flag[0] = 1;
        dfs(0, 0, 0);
   
        printf("Case %d:\n", iCase);
        if(max == -1) {
            printf("Impossible\n");
        } else {
            printf("The best score is %d.\n", max);
        }
        if(n > 0) {
            printf("\n");
        }
        
    }
    
    return 0;
}
