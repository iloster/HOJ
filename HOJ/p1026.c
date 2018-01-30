//
//  p1026.c
//  HOJ
//
//  Created by dev on 2018/1/26.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

struct Node {
    int x;
    int y;
    int num;
}nodes[120][120];
int visit[120][120] = {0};
struct Node Stack[10000];
int Len = 0;
int m,n;

void push(struct Node node) {
    Stack[Len] = node;
    Len++;
}

struct Node pop() {
    //int len = Len;
    Len--;
    return Stack[Len];
}

int bfs(struct Node start) {
    push(start);
    visit[start.x][start.y] = 1;
    while(Len != 0) {
        struct Node node = pop();
        if(node.x == (m-1) && node.y == (n-1)) {
            return 1;
        }
        int i = 0;
        for(i = 1;i < 4; i++) {
            int x = node.x;
            int y = node.y;
            if((x + 1) < m && visit[x+1][y] != 1 && nodes[x+1][y].num != -1){
                visit[x+1][y] = 1;
                push(nodes[x+1][y]);
            }
            if((x - 1) >= 0 && visit[x-1][y] != 1&& nodes[x-1][y].num != -1){
                visit[x-1][y] = 1;
                push(nodes[x-1][y]);
            }
            if((y + 1) < n && visit[x][y+1] != 1&& nodes[x][y-1].num != -1){
                visit[x][y+1] = 1;
                push(nodes[x][y+1]);
            }
            if((y - 1) >= 0 && visit[x][y-1] != 1&& nodes[x][y+1].num != -1){
                visit[x][y-1] = 1;
                push(nodes[x][y-1]);
            }

        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
  
    int i,j;
    char ch;
    while(scanf("%d%d",&m,&n) != EOF) {
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                scanf("%d",&nodes[i][j]);
                nodes[i][j].x = i;
                nodes[i][j].y = j;
            }
        }
        visit[0][0] = 1;
        int ret = bfs(nodes[0][0]);
        if(ret == 1) {
            printf("success\n");
        } else {
            printf("failed\n");
        }
    }
    
   /**
    int i = 0;
    int j = 0;
    int k = 0;
    int flag = 1;
    int time = 0;
    while(flag && time <= 4) {
        for(k = 0; k < 4; k++) {
            if(k == 1 && (i+1 < 5)) {
                if(a[i+1][j] == 1 && b[i+1][j] != 1) {
                    i++;
                    printf("i=%d,j=%d\n",i,j);
                    b[i][j] = 1;
                    time = 0;
                } else {
                    time++;
                }
            }
            
            if(k == 2 && (j+1 < 5)) {
                if(a[i][j+1] == 1&& b[i][j+1] != 1) {
                    j++;
                    printf("i=%d,j=%d\n",i,j);
                    b[i][j] = 1;
                    time = 0;
                } else {
                    time++;
                }
            }
            
            if(k == 3 && (i-1 >= 0)) {
                if(a[i-1][j] == 1 && b[i-1][j] != 1) {
                    i--;
                    printf("i=%d,j=%d\n",i,j);
                    b[i][j] = 1;
                    time = 0;
                } else {
                    time++;
                }
            }
          
            if(k == 4 && (j - 1 >= 0)) {
                if(a[i][j-1] == 1 && b[i][j-1] != 1) {
                    j--;
                    printf("i=%d,j=%d\n",i,j);
                    b[i][j] = 1;
                    time = 0;
                } else {
                    time++;
                }
            }
            if (i== 5 && j == 5) {
                flag = 0;
            }
        }
    }
    if(time>4) {
        printf("failed\n");
    } else {
        printf("success\n");
    }
    **/
    return 0;
}
