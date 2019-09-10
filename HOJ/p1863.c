//
//  p1863.c
//  HOJ
//
//  Created by cheng on 2019/9/10.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

int INF = 0x3f3f3f3f;
int n, m;
int edge[105][105];
int mark[105];
int queue[105];
int total;

void prime() {
    int tail = 1;
    while (tail < m) {
        int current = 0;
        int min = INF;
        for(int i = 0; i < tail; i++) {
            for(int j = 1; j <= m; j++) {
                if(!mark[j] && edge[queue[i]][j] >= 0 && edge[queue[i]][j] < min) {
                    min = edge[queue[i]][j];
                    current = j;
                }
            }
        }
        if(current == 0) {
            total = INF;
            break;
        }
        queue[tail] = current;
        mark[current] = 1;
        total += min;
        tail++;
    }
}

int main(int argc, const char * argv[]) {
    while(scanf("%d %d", &n, &m) != EOF) {
        if(n == 0) {
            break;
        }
        total = 0;
        memset(edge, -1, sizeof(edge));
        memset(mark, 0, sizeof(mark));
        memset(queue, 0, sizeof(queue));
        
        
        int a, b, c;
        for (int i = 0 ; i < n; i++) {
            scanf("%d %d %d", &a, &b, &c);
            edge[a][b] = c;
            edge[b][a] = c;
        }
        
        queue[0] = 1;
        mark[1] = 1;
        
        prime();
        if(total == INF) {
            printf("?\n");
        } else {
            printf("%d\n", total);
        }
    }
    return 0;
}
