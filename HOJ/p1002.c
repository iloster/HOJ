//
//  p1002.c
//  HOJ
//
//  Created by dev on 2018/2/9.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
char a[1005];
char b[1005];
int c[1005];

void revstr(char *str) {
    int i = 0;
    char ch;
    unsigned long len = strlen(str);
    for(i = 0; i < len/2; i++) {
        ch = str[i];
        str[i] = str[len - i - 1];
        str[len -i - 1] = ch;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    int i,j,l;
    while(scanf("%d", &n) != EOF) {
        for(i = 0; i < n; i++) {
            scanf("%s%s", a, b);
            printf("Case %d:\n", i + 1);
            printf("%s + %s = ", a,b);
            // 首先是对齐
            revstr(a);
            revstr(b);
            unsigned long len = strlen(a) > strlen(b) ? strlen(b) : strlen(a);
            int jin = 0;
            for(j = 0; j < len; j++) {
                c[j] = (a[j] - 48 + b[j] - 48 + jin)%10;
                jin = (a[j] - 48 + b[j] - 48 + jin)/10;
            }
            int k = len;
            if (strlen(a) == strlen(b)) {
                while(jin != 0) {
                    c[k] = jin%10;
                    jin = jin/10;
                    k++;
                }
            }else if(strlen(a) > strlen(b)) {
                while(a[k] != '\0') {
                    c[k] = (a[k] - 48 + jin)%10;
                    jin = jin/10;
                    k++;
                }
            } else {
                while(b[k] != '\0') {
                    c[k] = (b[k] - 48 + jin)%10;
                    jin = jin/10;
                    k++;
                }

            }
            for(l = k - 1; l >= 0; l--) {
                printf("%d", c[l]);
            }
            printf("\n");
            if(i != (n-1)) {
                printf("\n");
            }
        }
    }
    return 0;
}
