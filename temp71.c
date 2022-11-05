#include <stdio.h>
#include <string.h>

typedef struct machine_s {
    int matchine;
    int hours;
} machine_t;

int check(int *x1) {
    for(int i=0;i<180;i++) {
        if(x1[i]!=0) {
            return 1;
        }
    }
    return 0;
}
void work_sort(machine_t (*work)[180],int *x1,int *x2,int *k1,int *k2) {
    int num1,num2,num3,t1,t2,sum=0;
    for(int i=0;i<180;i++) {
        if(x1[i]==0) {
            num1=i;
            break;
        }
    }
    while(check(x1)==1) {
        num2=800;
        for(int i=0;i<num1;i++) {
            if(work[i][x2[i]].hours==0) {
                continue;
            }
            if(k1[i]>k2[work[i][x2[i]].matchine]) {
                num3=k1[i]+work[i][x2[i]].hours;
            }
            else {
                num3=k2[work[i][x2[i]].matchine]+work[i][x2[i]].hours;
            }
            if(num2>num3) {
                num2=num3;
                t1=i;
                t2=work[i][x2[i]].matchine;
            }
        }
        k1[t1]=num2;
        k2[t2]=num2;
        x1[t1]--;
        x2[t1]++;
    }
    for(int i=0;i<num2;i++) {
        sum=sum+k1[i];
    }
    printf("%d\n",sum);
}

int main() {
    int n,m;
    int x1[180]={0},x2[180]={0},k1[180]={0},k2[180]={0};
    machine_t work[80][180];
    memset(work,0,sizeof(work));
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d",&x1[i]);
        for(int j=0;j<x1[i];j++) {
            scanf("%d %d",&work[i][j].matchine,&work[i][j].hours);
        }
    }
    work_sort(work,x1,x2,k1,k2);
}
