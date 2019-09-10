//
//  p1162.c
//  HOJ
//
//  Created by cheng on 2018/10/10.
//  Copyright © 2018年 dev. All rights reserved.
//


#include <stdio.h>
#include <math.h>
double x[105];
double y[105];
double edge[105][105];
int mark[105];
int queue[105];
double distance = 0;
int n;
double INF = 100000000;

void prim() {
    int tail = 1;
    while (tail < n) {
        int current = 0;
        double min = INF;
        for (int i = 0; i < tail; i++) {
            for (int j = 0; j < n; j++) {
                if(!mark[j] && edge[queue[i]][j] < min) {
                    min = edge[queue[i]][j];
                    current = j;
                }
            }
        }
        queue[tail] = current;
        mark[current] = 1;
        tail++;
        distance += min;
       
    }
}

int main(int argc, const char * argv[]) {
    while(scanf("%d", &n) != EOF) {
        distance = 0;
        memset(edge, 0, sizeof(edge));
        memset(queue, 0, sizeof(queue));
        memset(mark, 0, sizeof(mark));
        
        for(int i = 0; i < n; i++) {
            scanf("%lf%lf", &x[i], &y[i]);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                double dis = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
                edge[i][j] = dis;
                edge[j][i] = dis;
            }
        }
        queue[0] = 0;
        mark[0] = 1;
        prim();
        printf("%.2f\n",  distance);
    }
    return 0;
}


