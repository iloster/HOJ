#include<stdio.h>
const int MAXN=500010;
int a[MAXN],b[MAXN];


//用二分查找的方法找到一个位置，使得num>b[i-1] 并且num<b[i],并用num代替b[i]
int Search(int num,int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num>=b[mid])  low=mid+1;
        else   high=mid-1;
    }
    return low;
}
int DP(int n)
{
    int i,len,pos;
    b[1]=a[1];
    len=1;
    for(i=2;i<=n;i++)
    {
        if(a[i]>=b[len])//如果a[i]比b[]数组中最大还大直接插入到后面即可
        {
            len=len+1;
            b[len]=a[i];
        }
        else//用二分的方法在b[]数组中找出第一个比a[i]大的位置并且让a[i]替代这个位置
        {
            pos=Search(a[i],1,len);
            b[pos]=a[i];
        }
    }
    return len;
}
int main()
{
    
    int n;
    int iCase=0;
    int i,j;
    int x,y;
    while(scanf("%d",&n)!=EOF)
    {
        iCase++;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            a[x]=y;
        }
        int res=DP(n);
        printf("Case %d:\n",iCase);
        if(res==1)
        {
            printf("My king, at most 1 road can be built.\n\n");
        }
        else
            printf("My king, at most %d roads can be built.\n\n",res);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
char *left_str = "(";
char *right_str = ")";
//char init[100] = "";
void gen(int left, int right, char *str) {
    if(left >= right) {
        if(left == 0 && right == 0) {
            printf("%s\n",str);
        } else {
            if(left > 0) {
                gen(left - 1,right,strcat(str ,"("));
            }
            if(right > 0) {
                gen(left, right - 1, strcat(str , ")"));
            }
        }
    }
    
    
}

void quicksort(int left, int right, int *a) {
    if (left >= right) {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[i];
    while(i < j) {
        while(i < j && a[j] > key) {
            j--;
        }
        while(i < j && a[i] < key) {
            i++;
        }
        int tmp;
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
//    a[i] = key;
    quicksort(left, i - 1, a);
    quicksort(i + 1, right, a);
}

int n = 6;
int a[6] = {5, 10, 9 ,8, 7,11};
int total = 7;
int dfs(int sum, int i) {
    if(i == n) {
        printf("sum = %d\n",sum);
        return sum == total? 1: 0;
    }
    if(dfs(sum , i + 1)) {
        return 1;
    }
    if(dfs(sum + a[i], i + 1)) {
        return 1;
    }
    return 0;
}



int main(int argc, const char * argv[]) {
//    char init[100] = "";
//    gen(3,3,init);
//    printf("%s\n",strcat(init, left_str));
    
//    quicksort(0,5,a);
//    int i = 0;
//    for(i = 0; i < 6; i++) {
//        printf("%d ",a[i]);
//    }
    printf("%d\n",dfs(0,0));
//    printf("\n");
    return 0;
}

