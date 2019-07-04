//
//  p1539.c
//  HOJ
//
//  Created by cheng on 2019/5/9.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>
int sum;
char str[15];
int L;
int num;

void dfs(int depth, int curSum, int nextNum, int op) {
    if(depth == L) {
        if((curSum + nextNum*op) == sum) {
            num++;
        }
        return;
    }
    dfs(depth + 1, curSum, nextNum*10 + str[depth] - '0', op);
    dfs(depth + 1, curSum + nextNum * op, str[depth] - '0', 1);
    dfs(depth + 1, curSum + nextNum * op, str[depth] - '0', -1);
}

int main(int argc, char * argv[]) {
    while(scanf("%s%d", str, &sum) != EOF) {
        L = strlen(str);
        num = 0;
        dfs(1, 0, str[0] - '0', 1);
        printf("%d\n", num);
    }

    return 0;
}
