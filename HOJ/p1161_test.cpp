#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define INF 0x7ffffff
struct point
{
    double x,y;
};
point p[105];
int n;
double ans;
double mpt[105][105];
void prim()
{
    double lowcost[105],min;
    int i,j,k;
    lowcost[1]=0;
    for(j=2;j<=n;j++)
        lowcost[j]=mpt[1][j];
    for(i=2;i<=n;i++)//找到N-1条边。
    {
        min=INF;
        for(j=1;j<=n;j++)
            if(lowcost[j]<min && lowcost[j])
            {
                min=lowcost[j];
                k=j;
            }
        ans+=min;
        lowcost[k]=0;
        for(j=1;j<=n;j++)
            if(mpt[k][j]<lowcost[j] && lowcost[j]) lowcost[j]=mpt[k][j];
    }
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(i==j) mpt[i][j]=INF;
                else mpt[i][j]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
            }
        prim();
        printf("%.2f\n",ans);
    }
    return 0;
}
