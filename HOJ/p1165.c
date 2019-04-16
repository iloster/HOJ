//
//  p1165.c
//  HOJ
//
//  Created by cheng on 2018/10/11.
//  Copyright © 2018 dev. All rights reserved.
//

#include <stdio.h>

int f(int m, int n) {
    if(m == 0) {
        return n + 1;
    }
    
    if(n == 0) {
        return f(m - 1, 1);
    }
    
    return f(m-1, f(m, n-1));
}

int main(int argc, const char * argv[]) {
    int m,n;
    while(scanf("%d%d", &m, &n) != EOF) {
        printf("%d\n", f(m,n));
    }
    return 0;
}
