//
//  p1258.c
//  HOJ
//
//  Created by cheng on 2019/5/9.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

int sum;
int n;
int a[105];
int visit[105];
int b[105];
int flag;

void dfs(int x, int l, int depth, int start) {
    if(l == 0) {
        for(int i = 0; i < depth - 1; i++) {
            printf("%d+", b[i]);
        }
        printf("%d\n",b[depth - 1]);
        flag = 1;
        return ;
    }
    
    for(int i = start; i < n; i++) {
        if(!visit[i] && a[i] <= l) {
            visit[i] = 1;
            b[depth] = a[i];
            dfs(i, l - a[i], depth + 1, i + 1);
            visit[i] = 0;
            while(i + 1 < n && a[i] == a[i + 1]) {
                i++;
            }
        }
    }
    return;
    
}

int main(int argc, char * argv[]) {
    while(scanf("%d%d", &sum, &n)) {
        if(sum == 0 && n == 0) {
            break;
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            visit[i] = 0;
        }
        flag = 0;
        printf("Sums of %d:\n", sum);
        dfs(0, sum, 0, 0);
        if(!flag) {
            printf("NONE\n");
        }

    }
    
    return 0;
}
