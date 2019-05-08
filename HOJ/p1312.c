//
//  p1312.c
//  HOJ
//
//  Created by cheng on 2019/4/17.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>


struct Object {
    int x;
    int y;
};


int main(int argc, const char * argv[]) {
    
    int m,n;
    struct Object quene[10000];
    while(scanf("%d%d", &m, &n) != EOF) {
        if(m == 0 && n == 0) {
            break;
        }
        char map[1000][1000];
        int startX = 0, startY = 0;
        for(int i = 0; i < n; i++) {
            getchar();
            for(int j = 0; j < m; j++) {
                scanf("%c", &map[i][j]);
                if(map[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
            }
        }
        int mark[1000][1000] = {0};
        
        struct Object obj = {startX, startY};
        quene[0] = obj;
        mark[startX][startY] = 1;
        
        int head = 0;
        int tail = 1;
        while(head != tail) {
            struct Object obj = quene[head];
            
            // 向上走
            int topX = obj.x - 1;
            int topY = obj.y;
            if(topX < n && topY < m && topX >= 0 && topY >= 0 && !mark[topX][topY] && map[topX][topY] == '.') {
                mark[topX][topY] = 1;
                struct Object tmp = {topX, topY};
                quene[tail] = tmp;
                tail++;
            }
            
            int leftX = obj.x;
            int leftY = obj.y - 1;
            if(leftX < n && leftY < m && leftX >= 0 && leftY >= 0 && !mark[leftX][leftY] && map[leftX][leftY] == '.') {
                mark[leftX][leftY] = 1;
                struct Object tmp = {leftX, leftY};
                quene[tail] = tmp;
                tail++;
            }
            
            int bottomX = obj.x + 1;
            int bottomY = obj.y;
            if(bottomX < n && bottomY < m && bottomX >= 0 && bottomY >= 0 && !mark[bottomX][bottomY] && map[bottomX][bottomY] == '.') {
                mark[bottomX][bottomY] = 1;
                struct Object tmp = {bottomX, bottomY};
                quene[tail] = tmp;
                tail++;
            }
            
            int rightX = obj.x;
            int rightY = obj.y + 1;
            if(rightX < n && rightY < m && rightX >= 0 && rightY >= 0 && !mark[rightX][rightY] && map[rightX][rightY] == '.') {
                mark[rightX][rightY] = 1;
                struct Object tmp = {rightX, rightY};
                quene[tail] = tmp;
                tail++;
            }
            head++;
        }
        printf("%d\n", head);
    }

    
    return 0;
}
