//
//  p1016.c
//  HOJ
//  深搜
//  Created by cheng on 2019/5/9.
//  Copyright © 2019 dev. All rights reserved.
//


#include <stdio.h>

int a[25];
int n;
int b[25];
int visit[25];

int su(int x) {
    int i;
    for(i = 2; i*i < x+1; i++)
        if(!(x%i)) return 0;
    return 1;
}

void dfs(int depth) {
    if(depth == n - 1 && su(b[depth] + 1)) {
        for(int i = 0; i < depth; i++) {
            printf("%d ", b[i]);
        }
        printf("%d", b[depth]);
        printf("\n");
        return ;
    }
    
    for(int i = 1; i < n; i++) {
        if(!visit[i] && su(i + 1 + b[depth])) {
            visit[i] = 1;
            b[depth + 1] = i + 1;
            dfs(depth + 1);
            visit[i] = 0;
            
        }
    }
    return ;
    
    
}


int main(int argc, const char * argv[]) {
    int num = 0;
    while(scanf("%d", &n) != EOF) {
        num++;
        for(int i = 0; i < n; i++) {
            a[i] = i + 1;
            visit[i] = 0;
        }
//        memset(visit, 0, sizeof(visit));
        b[0] = 1;
        visit[0] = 1;
        printf("Case %d:\n", num);
        dfs(0);
        printf("\n");
        
    }
    return 0;
}


