//
//  p1584.c
//  HOJ
//
//  Created by cheng on 2019/5/13.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>
int n;
int a[15];
int b[15];
int min = 0;
int visit[15];


void dfs(int depth, int distance) {
    if(depth == 9) {
        if(min == 0) {
            min = distance;
        } else {
            if(min > distance) {
                min = distance;
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        if(!visit[i]) {
            if(i >= 1 && a[i] < b[depth]) {
                continue;
            }
            visit[i] = 1;
            b[depth] = a[i];
            distance += abs(i - depth);
            dfs(depth + 1, distance);
            visit[i] = 0;
        }
    }
}

int main(int argc, char * argv[]) {
    while(scanf("%d", &n) != EOF) {
        if(n == 0) {
            break;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 10; j++) {
                scanf("%d", &a[j]);
                visit[i] = 0;
            }
            min = 0;
            dfs(0, 0);
            printf("%d\n", min);
        }
    }
    
    return 0;
}
