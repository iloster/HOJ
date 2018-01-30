//
//  p1033.c
//  HOJ
//
//  Created by dev on 2018/1/30.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    char a[210];
    while(scanf("%s", a) != EOF) {
//        printf("%s",a);
        int i = 0;
        printf("300 420 moveto\n");
        printf("310 420 lineto\n");
        int x = 310;
        int y = 420;

        for(i = 0; a[i] != '\0'; i++) {
            if (a[i] == 'A') {
                y = y - 10;
            } else if(a[i] == 'V') {
                y = y + 10;
            }
            printf("%d %d lineto\n",x,y);
        }
        printf("stroke\n");
        printf("showpage\n");
    }
    return 0;
}
