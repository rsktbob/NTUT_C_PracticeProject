#include <stdio.h>

void insert_sort(int *num1) {
    int x1;
    for(int i=1;i<6;i++) {
        for(int j=i;j>0;j++) {
            if(num1[j]>=num1[j-1]) {
                break;
            }
            else {
                x1=num1[j];
                num1[j]=num1[j-1];
                num1[j-1]=x1;
            }
        }
    }
}

void quick_sort(int *num1,int start,int end) {
    if(start>=end) {
        return;
    }
    int x1;
    int i=start;
    int j=end;
    int key=num1[start];
    while(i<j) {
        while(num1[i]<=key && i<j) {
            i++;
        }
        while(num1[j]>key && i<j) {
            j--;
        }
        if(i<j) {
            x1=num1[i];
            num1[i]=num1[j];
            num1[j]=x1;
        }
    }
    if(num1[i]<key) {
        x1=num1[i];
        num1[i]=key;
        num1[start]=x1;
    }
    quick_sort(num1,start,i-1);
    quick_sort(num1,i+1,end);
}

int main() {
    int x1;
    int x2;
    int num1[6]={3,6,14,8,12,18};
    quick_sort(num1,0,5);
    for(int i=0;i<6;i++) {
        printf("%d\n",num1[i]);
    }
}