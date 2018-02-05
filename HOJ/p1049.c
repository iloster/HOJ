//
//  p1049.c
//  HOJ
//
//  Created by cheng on 2018/2/5.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n,u,d;
    while(scanf("%d%d%d", &n, &u, &d) != EOF) {
        if(n == 0) {
            break;
        }
        int i = 1;
        int s = 0;
        while(s < n) {
            s = s + u;
            if(s >= n) {
                break;
            }
            i++;
            s = s - d;
            i++;
        }
        printf("%d\n",i);
    }
    return 0;
}
