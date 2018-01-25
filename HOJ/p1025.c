//
//  p1025.c
//  HOJ
//
//  Created by cheng on 2018/1/25.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
int a[500010];
int b[500010];
int search(int num, int low, int hight) {
    int mid;
    while(low <= hight) {
        mid =(low + hight)/2;
        if(b[mid] <= num) {
            low = mid + 1;
        } else {
            hight = mid -1;
        }
    }
    return low;
}

int main(int argc, const char * argv[]) {
    int n = 0;
    int iCase = 0;
    while(scanf("%d",&n) != EOF) {

        iCase++;
        int i,x,y;
        for(i = 0; i < n; i++) {
            scanf("%d%d",&x,&y);
            a[x] = y;
        }
        b[1] = a[1];
        int len= 1;
        
        for(i = 2; i <= n; i++) {
            if(a[i] >= b[len]) {
                len++;
                b[len] = a[i];
            } else {
                int pos = search(a[i], 1, len);
                b[pos] = a[i];
            }
        }
        printf("Case %d:\n",iCase);
        if(len == 1) {
            printf("My king, at most 1 road can be built.\n\n");
        } else {
            printf("My king, at most %d roads can be built.\n\n",len);
        }
    }
}

/**
int main(int argc, const char * argv[]) {
    int len = 0;
    int iCase = 0;
    while(scanf("%d", &len)) {
        int a[500100];
        int b[500100] = {1,1};
        iCase++;
        int i,j,x,y;
        for(i = 0; i< len; i++) {
            scanf("%d%d",&x,&y);
            a[x] = y;
        }
        for(i = 1; i <= len; i++) {
            for(j = 1; j< i; j++ ) {
                if(a[i] > a[j] && b[i] < (b[j] + 1)) {
                    b[i] = b[j] + 1;
                }
            }
        }
        int max = b[1];
        for(i = 1; i <= len; i++) {
            if(max < b[i]) {
                max = b[i];
            }
        }
        printf("Case %d:\n",iCase);
        if(max == 1) {
            printf("My king, at most 1 road can be built\n");
        } else {
            printf("My king, at most %d roads can be built\n\n",max);
        }
    }
    return 0;
}
**/
