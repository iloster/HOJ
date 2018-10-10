//
//  p1050.c
//  HOJ
//
//  Created by dev on 2018/2/27.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int m,n;
    int i,j,k;
    int a,b;
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        int room[210] = {0};
        scanf("%d", &n);
//        printf("%d\n",n);
        for(j = 0; j < n; j++) {
            scanf("%d%d", &a, &b);
            int tmp;
            if(a > b) {
                tmp = a;
                a = b;
                b = tmp;
            }
           
            for(k = (a + 1)/2; k <= (b+1)/2; k++) {
                room[k] += 10;
            }
        
        }
        int max = room[1];
        for(k = 2; k < 210; k++) {
            if(room[k] > max) {
                max = room[k];
            }
        }
        printf("%d\n", max);
        
    }
    
    return 0;
}
