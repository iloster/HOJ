//
//  p1076.c
//  HOJ
//
//  Created by dev on 2018/2/9.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

int isLeap(int year) {
    if((year%4 == 0 && year%100 != 0) || year%400 == 0) {
        return 1;
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    int n;
    int i;
    int start;
    int len;
    while(scanf("%d", &n) != EOF) {
        for(i = 0; i < n; i++) {
            scanf("%d%d", &start, &len);
            int j = 0;
            int k = 0;
            while(j < len) {
                if(isLeap(start + k)) {
                    j++;
                }
                k++;
            }
            printf("%d\n",start+k-1);
        }

    }
    return 0;
}
