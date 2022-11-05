#include<stdio.h>
#include <string.h>
#include <string.h>
#define INF 0x3f3f3f3f

int minValue(int x,int y) { 
    return x>y?y:x; 
}

int Rec(int MAX_N,int R[][1<<MAX_N],int d[][MAX_N],int v,int S){
    int t=0,ans=INF;
    if(R[v][S]>=0){
        return R[v][S];
    }
    for(int i=0;i<MAX_N;i++){
        if(!(S>>i&1)){
            t=Rec(MAX_N,R,d,i,S|(1<<i));
            ans=minValue(ans,d[v][i]+t);
        }
    }
    return R[v][S]=ans;
}

void solve()
{
    int MAX_N;
    scanf("%d",&MAX_N);
    getchar();
    int v=0,S=(0|1<<v);
    int R[MAX_N][1<<MAX_N];
    int d[MAX_N][MAX_N];
    for(int i=0;i<MAX_N;i++)
    {
        for(int j=0;j<MAX_N;j++)
        {
            scanf("%d",&d[i][j]);
        }
    }
    memset(R,-1,sizeof(R));
    for(int i=0;i<MAX_N;i++) {
        R[i][(1<<MAX_N)-1]=d[i][0];
    }
    printf("%d %d\n",v,S);
    printf("%d\n",Rec(MAX_N,R,d,v,S));
}

int main(){
    solve();
    return 0;
}