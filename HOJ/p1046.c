//
//  p1046.c
//  HOJ
//
//  Created by dev on 2018/2/7.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int i;
    int m,n;
    int k;
    while(scanf("%d", &k) != EOF) {
        for(i = 0; i < k; i++) {
            scanf("%d%d", &m,&n);
//            scanf("%d", &n);
             printf("Scenario #%d:\n",i + 1);
            if(n%2 == 0 || m%2 == 0) {
                printf("%d.00\n",m*n);
            } else {
                printf("%d.41\n",m*n);
            }
           
            printf("\n");
        }
      
    }
    return 0;
}
