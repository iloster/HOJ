//
//  main.c
//  ZOJ
//
//  Created by dev on 2018/1/19.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

//int gcd(int a, int b) {
//    int c = 0;
//    if (a < b) {
//        c = a;
//        a = b;
//        b = c;
//    }
//    if (a%b != 0) {
//        return gcd(b, a%b);
//    } else {
//        return b;
//    }
//}

int main(int argc, const char * argv[]) {
    // insert code here...
//    int T;
//    int n,b,i;
//    int ret;
//    scanf("%d",&T);
//    while(T--) {
//        scanf("%d", &n);
//        ret = 1;
//        for(i = 1; i <= n; i++) {
//            scanf("%d", &b);
////            printf("b=%d\n",b);
//            ret = b/gcd(b,ret)*ret;
//        }
//        printf("%d\n",ret);
//    }
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", a+b);
    }
    return 0;
}

