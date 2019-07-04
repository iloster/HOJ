//
//  p1455.c
//  HOJ
//
//  Created by cheng on 2019/5/8.
//  Copyright © 2019 dev. All rights reserved.
//

#include <stdio.h>

int n;
int a[80];
int visit[80];
int L;
int lastStickNo;

void quicksort(int a[],int low,int high)
{
    int i = low;
    int j = high;
    int temp = a[i];
    
    if( low > high) {
        return ;
    }
    
    while(i < j) {
        while((a[j] >= temp) && (i < j)) {
            j--;
        }
        while((a[i] <= temp) && (i < j)) {
            i++;
        }
        int x;
        x = a[i];
        a[i] = a[j];
        a[j] = x;
    }
    quicksort(a, low, i - 1);
    quicksort(a, i + 1, high);
}
// sum 剩下的木棍数
// l 剩下的长度
int dfs(int sum, int l) {
    if(sum == 0 && l == 0) {
        return 1;
    }
    if(l == 0) {
        l = L;
    }
    int startNo = 0;
    if(l != L) {
        startNo = lastStickNo + 1;
    }
    for(int i = startNo; i < n; i++) {
        if(!visit[i] && a[i] <= l) {
            if(i > 0) {
                if(!visit[i - 1] && a[i - 1] == a[i]) {
                    continue;
                }
            }
            visit[i] = 1;
            lastStickNo = i;
            if(dfs(sum - 1, l - a[i])) {
                return 1;
            } else {
                visit[i] = 0;
                if(l == L || a[i] == l) {
                    return 0;
                }
            }
        }
        
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    while(scanf("%d", &n)) {
        if(n == 0) {
            break;
        }
        int sum = 0;
        lastStickNo = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            visit[i] = 0;
        }
        // 先排序
        quicksort(a, 0, n - 1);
        for(L = a[0]; L <= sum; L++) {
            if(sum%L) continue;
            if(dfs(n, L)) {
                printf("%d\n", L);
                break;
            }
        }
        
    }
    return 0;

}
