//
//  p1232.c
//  HOJ
//
//  Created by cheng on 2019/9/11.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>
int MAXN = 1005;
int pre[1005];
int cnt;

void init() {
    for (int i = 0; i <= MAXN; i++) {
        pre[i] = i;
        cnt = 0;
    }
}

int find(int a) {
    if(a == pre[a]) return a;
    return find(pre[a]);
}

void unit(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return ;
    if(a < b) {
        pre[b] = a;
    } else {
        pre[a] = b;
    }
}

int main(int argc, const char * argv[]) {
    int N, M;
    while(scanf("%d", &N) != EOF) {
        if(N == 0) {
            break;
        }
        scanf("%d", &M);
        init();
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            unit(a, b);
        }
        for(int i = 1; i <= N; i++) {
            if(i == pre[i]) {
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    
    return 0;
}
