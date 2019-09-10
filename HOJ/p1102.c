//
//  p1102.c
//  HOJ
//
//  Created by cheng on 2019/9/10.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>


int main(int argc, const char * argv[]) {
    int N, M;
    int edge[105][105];
    while(scanf("%d", &N)!= EOF) {
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &edge[i][j]);
            }
        }
        
        scanf("%d", &M);
        for(int i = 0; i < M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            edge[a][b] = 0;
            edge[b][a] = 0;
        }
        
        int mark[105] = {0};
        int queue[105] = {0};
        
        queue[0] = 1;
        mark[1] = 1;
        
        int tail = 1;
        int total = 0;
        while (tail < N) {
            int current = 0;
            int min = 0x9fffff;
            for(int i = 0; i < tail; i++) {
                for (int j = 1; j <= N; j++) {
                    if(!mark[j] && edge[queue[i]][j] < min) {
                        min = edge[queue[i]][j];
                        current = j;
                    }
                }
            }
            queue[tail] = current;
            mark[current] = 1;
            tail++;
            total += min;
        }
        
        printf("%d\n", total);
    }
}
