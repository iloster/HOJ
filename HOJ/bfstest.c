//
//  bfstest.c
//  HOJ
//
//  Created by cheng on 2019/4/16.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

struct point {
    int x;
    int y;
    int parent;  // 父节点的索引
    
};


int main(int argc, const char * argv[]) {
    int endX = 4, endY = 4;
    int map[5][5] = {   0, 0, 0, 0, 0,
                        0, 1, 0, 1, 0,
                        0, 1, 0, 0, 0,
                        0, 1, 0, 1, 0,
                        0, 0, 0, 1, 0,  };
    int mark[10][10] = {0};

    struct point quene[100];// 队列
    struct point ret[100];
    struct point first = {0, 0 , -1};
    quene[0] = first;
    mark[0][0] = 1;
    
    int head = 0;
    int tail = 1;
    while(head != tail) {
        struct point p = quene[head];
        if(p.x == endX && p.y == endY) {
            // 出站
            int i = 0;
            while(1) {
                ret[i] = p;
                if(p.parent == -1) {
                    break;
                }
                p = quene[p.parent];
                i++;
            }
            for(int j = 0; j < i; j++) {
                printf("x = %d y = %d \n", ret[j].x, ret[j].y);
            }
            break;
        } else {
            // 入站
            int bottomX = p.x + 1;
            int bottomY = p.y;
            if(!mark[bottomX][bottomY] && !map[bottomX][bottomY]) {
                struct point tmp = { bottomX, bottomY , head};
                quene[tail] = tmp;
                mark[bottomX][bottomY] = 1;
                tail++;
            }
            
            int leftX = p.x;
            int leftY = p.y - 1;
            if(!mark[leftX][leftY] && !map[leftX][leftY]) {
                struct point tmp = { leftX, leftY , head};
                quene[tail] = tmp;
                mark[leftX][leftY] = 1;
                tail++;
            }
            
            int topX = p.x - 1;
            int topY = p.y;
            if(!mark[topX][topY] && !map[topX][topY]) {
                struct point tmp = { topX, topX , head};
                quene[tail] = tmp;
                mark[topX][topY] = 1;
                tail++;
            }
            
            int rightX = p.x;
            int rightY = p.y + 1;
            if(!mark[rightX][rightY] && !map[rightX][rightY]) {
                struct point tmp = { rightX, rightY , head};
                quene[tail] = tmp;
                mark[rightX][rightY] = 1;
                tail++;
            }
            head++;
        }
    }
    return 0;
}
