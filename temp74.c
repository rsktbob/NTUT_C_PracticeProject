#include <stdio.h>

void load(int num1[],char x1[]) {
    int k1;
    for(int i=0; ;i++) {
        if(x1[i] == '\0') {
            k1=i;
            break;
        }
    }
    for(int i=0,j=80-k1;x1[i]!='\0';i++,j++) {
        num1[j]=x1[i]-'0';
    }
}

void shift(int num1[]) {
    for(int i=0;i<79;i++) {
        num1[i]=num1[i+1];
    }
    num1[79]=0;
}

void add(int num1[],int num2[],int num3[]) {
    int sum;
    int carry=0;
    for(int i=79;i>=0;i--) {
        sum=num1[i]+num2[i]+carry;
        carry=0;
        if(sum>9) {
            sum=sum-10;
            carry=1;
        }
        num3[i]=sum;
    }
}

void sub(int num1[],int num2[],int num3[]) {
    int difference;
    int borrow=0;
    for(int i=79;i>=0;i--) {
        difference=num1[i]-num2[i]-borrow;
        borrow=0;
        if(difference<0) {
            difference=difference+10;
            borrow=1;
        }
        num3[i]=difference;
    }
}

void mul(int num1[],int num2[],int num3[]) {
    int k1=0;
    for(int i=0;i<80;i++) {
        if(num2[i]!=0) {
            k1=80-i;
            break;
        }        
    }
    for(int i=79;i>79-i;i--) {
        for(int j=0;j<num2[i];j++) {
            add(num1,num3,num3);
        }
        shift(num1);
    }
}

int main() {
    char x1[80]={};
    char x2[80]={};
    int num1[80]={0};
    int num2[80]={0};
    int num3[80]={0};
    scanf("%s",x1);
    scanf("%s",x2);
    load(num1,x1);
    load(num2,x2);
    mul(num1,num2,num3);
    for(int i=0; i<80; i++) {
        printf("%d ",num3[i]);
    }
}