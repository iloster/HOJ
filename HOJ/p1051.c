//
//  p1051.c
//  HOJ
//
//  Created by dev on 2018/2/27.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int a[5000] = {0};
int b[5000] = {0};
void sort(int n) {
    // 排序
}

int main(int argc, const char * argv[]) {
    int m,n;
    int i,j;
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &n);
        for(j = 0; j < n; j++) {
            scanf("%d%d", &a[j],&b[j]);
        }
        sort(n);
        int k = 0;
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                
            }
        }
    }
    return 0;
}
