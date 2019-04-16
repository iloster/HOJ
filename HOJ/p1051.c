//
//  p1051.c
//  HOJ
//
//  Created by dev on 2018/2/27.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Obj {
    int length;
    int width;
};

int cmp(const void *p1, const void *p2) {
    struct Obj a = *(struct Obj *) p1;
    struct Obj b = *(struct Obj *) p2;
    if(a.length > b.length) {
        return -1;
    } else if(a.length == b.length) {
        if(a.width > b.width) {
            return -1;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    int m, n;
    struct Obj a[5005];
    int length, width;
    int b[5005];
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &n);
        for(int j = 0; j < n; j++) {
            scanf("%d %d", &a[j].length, &a[j].width);
            b[j] = 0;
        }
        qsort(a, n, sizeof(struct Obj), cmp);
        // 求子序列的个数 设置第i个需要的时间dp[i]
        // qenue[i][j]
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(b[j] == 0) {
                // 设置起点
                length = a[j].length;
                width = a[j].width;
                b[j] = 1;
                for(int k = j + 1; k < n; k++) {
                    if(a[k].length <= length && a[k].width <= width && b[k] == 0) {
                        length = a[k].length;
                        width = a[k].width;
                        b[k] = 1;
                    }
                }
                sum++;
            }
        }
        printf("%d\n", sum);
        
    }
    return 0;
}
