//
//  p1062.c
//  HOJ
//
//  Created by cheng on 2019/1/18.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>
#include <string.h>


int main(int argc, const char * argv[]) {
    int i;
    char words[1005];
    scanf("%d", &i);
    getchar();
    while(i--) {
        gets(words);
        int len = strlen(words);

        for(int j = 0; j < len; j++) {
            for(int k = j; k < len; k++) {
                if(words[k] == ' ' || k == (len - 1)) {
                    for(int m = (k == (len - 1))? k : k - 1; m >= j; m --) {
                        putchar(words[m]);
                    }
                    if(words[k] == ' ' && k != (len - 1)) {
                        putchar(' ');
                    }
                    j = k + 1;
                }
            }
            printf("\n");
        }

    }
    return 0;
    
}
