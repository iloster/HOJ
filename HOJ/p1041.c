//
//  p1041.c
//  HOJ
//
//  Created by dev on 2018/2/2.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int O[1010][100];
int Z[1010][100];
int main(int argc, const char * argv[]) {
    int i,j;
    O[0][0] = O[1][0] = 1;
    for(i = 2; i< 1001; i++) {
        for(j = 0; j < 100; j++) {
            O[i][j] += O[i-1][j] + O[i-1][j];
            Z[i][j] += O[i-2][j] + Z[i-2][j];
            O[i][j+1] += O[i][j]/10000;
            O[i][j] %= 10000;
            Z[i][j+1] += Z[i][j]/10000;
            Z[i][j] %= 10000;
        }
    }
    int step;
    while(scanf("%d",&step) != EOF) {
        int end = 99;
        while ( end > 0 && !Z[step][end] ) -- end;
        printf("%d",Z[step][end --]);
        while ( end >= 0 )
            printf("%04d",Z[step][end --]);
        printf("\n");
    }
    return 0;
}
