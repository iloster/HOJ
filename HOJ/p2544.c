//
//  p2544.c
//  HOJ
//
//  Created by cheng on 2019/7/4.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

int map[1005][1005];
int dis[1005];
int visited[1005];
const int INF = 0x3f3f3f3f;

int main(int argc, const char * argv[]) {
    int n, m;
    while(scanf("%d %d", &n, &m)) {
        if(n == 0 && m == 0) {
            break;
        }
       
        for(int i = 1; i <= n; i++) {
            dis[i] = 0;
            for(int j = 1; j <= n; j++) {
                if(i == j) {
                    map[i][j] = 0;
                } else {
                    map[i][j] = INF;
                }
            }
        }
        
        int a, b, c;
        for(int i = 1; i <= m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            map[a][b] = c;
            map[b][a] = c;
        }
        for(int i = 1; i <= n; i++) {
            dis[i] = map[1][i];
            visited[i] = 0;
        }
        visited[1] = 1;
        int u = 0;
//        int v = n;
        for(int i = 1; i <= n - 1; i++) {
            int min = INF;
            for(int j = 1; j <= n; j++) {
                if(!visited[j] && dis[j] < min) {
                    min = dis[j];
                    u = j;
                }
            }
            visited[u] = 1;
            if(min < INF) {
                for(int v = 1; v <= n; v++) {
                    if(map[u][v] < INF) {
                        if(dis[v] > (dis[u] + map[u][v])) {
                            dis[v] = dis[u] + map[u][v];
                        }
                    }
                }
            }
        }
        
        printf("%d\n", dis[n]);
        
    }
}
