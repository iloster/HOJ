//
//  p1035.c
//  HOJ
//
//  Created by dev on 2018/1/31.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

char a[10000][10000];
int record[10000][10000];

int main(int argc, const char * argv[]) {
    int col; // 列数
    int row; // 行数
    int startCol;
    int startRow;
    int i,j;
    while(scanf("%d%d",&row,&col) != EOF) {
        if(col == 0 || row == 0) {
            break;
        }
        scanf("%d", &startCol);
        startRow = 0;
        startCol--;
        for(i = 0; i < row; i++) {
            scanf("%s",a[i]);
            for(j = 0; j < col; j++) {
                record[i][j] = 0;
            }
        }
        int step = 0;
        int loop = 0;
//        printf("starRow = %d,startCol=%d,row=%d,col=%d, record=%d\n",startRow,startCol,row,col,record[startRow][startCol]);
        while(startRow >= 0 && startRow < row && startCol >= 0 && startCol < col && record[startRow][startCol] < 3) {
            if(record[startRow][startCol] == 0) {
                step++;
            }
            record[startRow][startCol]++;
            if(record[startRow][startCol] == 2) {
                loop++;
            }
            if(a[startRow][startCol] == 'N') {
                startRow--;
            } else if(a[startRow][startCol] == 'S') {
                startRow++;
            } else if(a[startRow][startCol] == 'W') {
                startCol--;
            } else if (a[startRow][startCol] == 'E') {
                startCol++;
            }
//            printf("startRow = %d, startCol = %d\n", startRow,startCol);
           
        }
        if(loop == 0) {
             printf("%d step(s) to exit\n",step);
        } else {
            printf("%d step(s) before a loop of %d step(s)\n",step - loop,loop);
        }
       
    }
    return 0;
}
