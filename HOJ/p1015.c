//
//  p1015.c
//  HOJ
//
//  Created by cheng on 2019/5/8.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int num[100];
int judge = 0;
int length = 0;
int visit[100] = {0};
int b[5];
int n;

int check() {
    if(n == b[0] - b[1]*b[1] + b[2]*b[2]*b[2] - b[3]*b[3]*b[3]*b[3] + b[4]*b[4]*b[4]*b[4]*b[4]){
        judge = 1;
        return 1;
    }else return 0;
}

void dfs(int depth) {
    if(judge) return;
    
    if(depth == 5) {
        check();
        return;
    }
    
    for(int i = 0; i < length; i++) {
        if(!visit[i] && !judge) {
            b[depth] = num[i];
            visit[i] = 1;
            dfs(depth+1);
            visit[i] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    char str[100];
    while(scanf("%d%s", &n, str)) {
        length = strlen(str);
        judge = 0;
        
        if(n == 0 && strcmp(str,"END") == 0) {
            break;
        }
        int temp[26] ={ 0 };
        for(int i = 0; i < length; i++) {
            temp[str[i] - 'A'] = 1;
            visit[i] = 0;
        }
        int count = 0;
        for(int j = 25; j >= 0; j--) {
            if( temp[j] ) {
                num[count] = j + 1;
                count++;
            }
        }
        dfs(0);
        if(judge) {
            printf("%c%c%c%c%c\n", b[0] + 'A' - 1, b[1] + 'A' - 1, b[2] + 'A' - 1, b[3] + 'A' - 1, b[4] + 'A' - 1);
        } else {
            printf("no solution\n");
        }

    }
   
    return 0;
}
