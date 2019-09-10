//
//  p1879.c
//  HOJ
//
//  Created by cheng on 2019/9/10.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

int INF = 0x5555;
int n;
int edge[102][102];
int mark[102];
int queue[102];
int total;

void prim() {
    int tail = 1;
    while (tail < n) {
        int current = 0;
        int min = INF;

        for(int i = 0; i < tail; i++) {
            for(int j = 1; j <= n; j++) {
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
}


int main(int argc, const char * argv[]) {
    while (scanf("%d", &n) != EOF) {
        if(n == 0) {
            break;
        }
        
        total = 0;
        memset(edge, 0, sizeof(edge));
        memset(mark, 0, sizeof(mark));
        memset(queue, 0, sizeof(queue));
        
        int a, b, c, d;
        for (int i = 0; i < n*(n-1)/2; i++) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            if(d == 1) {
                c = 0;
            }
            edge[a][b] = c;
            edge[b][a] = c;
        }
        queue[0] = 1;
        mark[1] = 1;
        prim();
        printf("%d\n", total);
    }
    return 0;
}
