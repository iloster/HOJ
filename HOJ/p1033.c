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
        printf("300 420 moveto\n");
        printf("310 420 lineto\n");
        int x = 300;
        int y = 420;
        
        int x1 = 310;
        int y1 = 420;
        int i = 0;
        for(i = 0; a[i] != '\0'; i++) {
            if(a[i] == 'A') {
                // 顺时针
                if(x == x1) {
                    // 竖直
                    if( y1 > y) {
                        x = x1;
                        y = y1;
                        x1 = x1 + 10;
                    } else {
                        x = x1;
                        y = y1;
                        x1 = x1 - 10;
                    }
                } else {
                    // 水平
                    if(x1 > x) {
                        x = x1;
                        y = y1;
                        y1 = y1 - 10;
                    } else {
                        x = x1;
                        y = y1;
                        y1 = y1 + 10;
                    }
                }
                printf("%d %d lineto\n",x1,y1);
            } else if (a[i] == 'V') {
                if(x == x1) {
                    if (y1 > y) {
                        x = x1;
                        y = y1;
                        x1 = x1 - 10;
                    } else {
                        x = x1;
                        y = y1;
                        x1 = x1 + 10;
                    }
                } else {
                   
                    if(x1 > x) {
                        x = x1;
                        y = y1;
                        y1 = y1 + 10;
                    } else {
                        x = x1;
                        y = y1;
                        y1 = y1 - 10;
                    }
                }
                printf("%d %d lineto\n",x1,y1);
            }
            
        }
        printf("stroke\n");
        printf("showpage\n");
    }
    return 0;
}
