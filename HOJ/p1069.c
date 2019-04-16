//
//  p1069.c
//  HOJ
//
//  Created by cheng on 2018/10/8.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int dp[200]; // dp[i]以第i个为起点的最高  dp[i+1] = max{dp[i] + block[i+1], dp[i+1]}

struct block {
    int x;
    int y;
    int z;
}blocks[200];


int cmp(const void *p1, const void *p2) {
    struct block block1 = *(struct block *) p1;
    struct block block2 = *(struct block *) p2;
    if(block1.x == block2.x) {
        if(block1.y == block2.y) {
            return block1.z - block2.z;
        }
        return block1.y - block2.y;
    }
    return block1.x - block2.x;
}

int main(int argc, const char * argv[]) {
    int line;
    int a, b, c;
    int n = 0;
    while (scanf("%d", &line) != EOF) {
        if(line == 0) {
            break;
        }
        int k = 0;
        n++;
        for(int i = 0; i < line; i++) {
            scanf("%d%d%d", &a, &b, &c);
            blocks[k].x = a; blocks[k].y = b; blocks[k].z = c; k++;
            blocks[k].x = a; blocks[k].z = b; blocks[k].y = c; k++;
            blocks[k].y = a; blocks[k].x = b; blocks[k].z = c; k++;
            blocks[k].y = a; blocks[k].z = b; blocks[k].x = c; k++;
            blocks[k].z = a; blocks[k].x = b; blocks[k].y = c; k++;
            blocks[k].z = a; blocks[k].y = b; blocks[k].x = c; k++;
        }
        // 排序 先x  再y  再z
        qsort(blocks, k, sizeof(struct block), cmp);
        
        // 贪心算法
        int max = 0;
//        int width, height;
        dp[0] = 0;
        for(int i = 0; i < line*6; i++) {
            dp[i] = blocks[i].z;
            for(int j = 0; j < i; j++) {
                if(blocks[i].x > blocks[j].x && blocks[i].y > blocks[j].y
                   && dp[i] < (dp[j] + blocks[i].z)) {
                    dp[i] = dp[j] + blocks[i].z;
//                    printf("i = %d  j= %d\n" ,i, j);
                    if(max <= dp[i]) {
                        max = dp[i];
                    }
                }
            }
        }
        
        printf("Case %d: maximum height = %d\n", n, max);
        
    }
    return 0;
}
