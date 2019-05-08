//
//  p1728.c
//  HOJ
//
//  Created by cheng on 2019/4/17.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

struct Object {
    int x;
    int y;
    int direct;
};


int main(int argc, const char * argv[]) {
    
    int line = 0;
    int m, n = 0; // m: 行  n: 列
    while(scanf("%d", &line) != EOF) {
        while(line--) {
            char map[105][105];
            int mark[105][105] = {0};
            struct Object quene[10000];
            int k, x1, y1, x2, y2;
            scanf("%d%d", &m, &n);
            for(int i = 0; i < m; i++) {
                getchar();
                for(int j = 0; j < n; j++) {
                    scanf("%c", &map[i][j]);
                }
            }
            scanf("%d%d%d%d%d", &k, &y1, &x1, &y2, &x2);
            
            // 广度搜索
            struct Object obj = {x1 - 1, y1 - 1, 0};
            quene[0] = obj;
            mark[x1 - 1][x2 - 1] = 1;
            
            int head = 0;
            int tail = 1;
            while(head != tail) {
                struct Object p = quene[0];
                
                
                
            }
        }
    }

    return 0;
}
