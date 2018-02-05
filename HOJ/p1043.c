//
//  p1043.c
//  HOJ
//
//  Created by dev on 2018/2/5.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
char a[3][3] = {0};
int record[3][3] = {0};
int Size = 0;
struct Node {
    int i;
    int j;
};
struct node Nodes[10];
int isOk() {
    int i = 0;
    for(i = 0; i < 8; i++) {
        printf("%d\n", a[i/3][i%3]);
        if(a[i/3][i%3] != (i + 49)) {
            return 0;
        }
    }
    return 1;
}
void print(int len) {
    int i = 0;
    for(i = 0; i < len; i++) {
        printf("%d ", a[i/3][i%3]);
    }
    printf("\n");
}

void bfs(int col, int row) {
    int i = col;
    int j = row;
    struct Node node;
    node.i = col;
    node.j = row;
    Nodes[Size] = node
    Size++;
    
    while(isOk() && Size != 0) {
        if( i >= 0 && j >= 0 && i < 3 && j <3 && record[i][j] == 0) {
            
        }
    }
}

int main(int argc, const char * argv[]) {
    int i,j;
    int col,row;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf(" %c", &a[i][j]);
            if(a[i][j] == 'x') {
                col = i;
                row = j;
            }
        }
    }
    while(isOk()) {
        
    }
    printf("%d\n",isOk());
    return 0;
}
