#include <stdio.h>
#include <stdlib.h>

void load(int *num1,char *x1,int *k1,int *t1) {
    int k=0;
    for(int i=0;x1[i]!='\0';i++) {
        k=i;
    }
    for(int i=79,j=k;x1[k]!='\0';i--,k--) {
        if(x1[k]=='-') {
            *k1=1;
            i++;
        }
        else if(x1[k]=='.') {
            *t1=79-i;
            i++;
        }
        else {
            num1[i]=x1[k]-'0';
        }
    }
}

int sebig(int *num1,int *num2) {
    for(int i=0;i<80;i++) {
        if(num1[i]<num2[i]) {
            return 1;
        }
        if(num1[i]>num2[i]) {
            return 0;
        } 
    }
    return 0;
}

void shift(int *num1,int k1) {
    for(int i=0;i<80-k1;i++) {
        num1[i]=num1[i+k1];
    }
    for(int i=80-k1;i<80;i++) {
        num1[i]=0;
    }
}

void align(int *num1,int *num2,int t1,int t2) {
    int k1;
    k1=abs(t1-t2);
    if(t1>t2) {
        shift(num2,k1);
    }
    else if(t1<t2) {
        shift(num1,k1);
    }
}

void add(int *num1,int *num2,int *c1) {
    int sum;
    int carry=0;
    for(int i=79;i>=0;i--) {
        sum=num1[i]+num2[i]+carry;
        carry=0;
        if(sum>9) {
            sum=sum-10;
            carry=1;
        }
        c1[i]=sum;
    }
}

void sub(int *num1,int *num2,int *c1) {
    int difference;
    int borrow=0;
    for(int i=79;i>=0;i--) {
        difference=num1[i]-num2[i]-borrow;
        borrow=0;
        if(difference<0) {
            difference=difference+10;
            borrow=1;
        }
        c1[i]=difference;
    }
}

void mul(int *num1,int *num2,int *c1) {
    int k=80;
    for(int i=0;i<80;i++) {
        if(num2[i]!=0) {
            k=i;
            break;
        }
    }
    if(k==80) {
        return;
    }
    else {
        for(int i=79;i>=k;i--) {
            for(int j=0;j<num2[i];j++) {
                add(num1,c1,c1);
            }
            shift(num1,1);
        }
    }
}

void array_out(int *num1,int k1,int t1) {
    for(int i=0;i<80;i++) {
        if(num1[i]!=0) {
            break;
        }
        if(num1[i]==0 && i==79) {
            printf("%d",0);
            return;
        }
    }
    if(k1==1) {
        printf("-");
    }
    int j;
    int k=79-t1;
    for(int i=79;i>79-t1;i--) {
        if(num1[i]!=0) {
            k=i;
            break;
        }
    }
    for(int i=0;i<=79-t1;i++) {
        if(num1[i]!=0 || i==79-t1) {
            j=i;
            break;
        }
    }
    for(int i=j;i<=k;i++) {
        printf("%d",num1[i]);
        if(i==79-t1 && k!=79-t1) {
            printf(".");
        }
    }
    printf("\n");
}

int main() {
    char x1[80]={};
    char x2[80]={};
    int num1[80]={};
    int num2[80]={};
    int k1=0;
    int k2=0;
    int t1=0;
    int t2=0;
    int j1=0;
    int j2=0;
    int j3=0;
    int c1[80]={};
    int c2[80]={};
    int c3[80]={};
    scanf("%s",x1);
    scanf("%s",x2);
    load(&num1[0],&x1[0],&k1,&t1);
    load(&num2[0],&x2[0],&k2,&t2);
    align(&num1[0],&num2[0],t1,t2);
    int t3=(t1>t2)?t1:t2;
    if(sebig(&num1[0],&num2[0])==0) {
        if(k1==0 && k2==0) {
            add(&num1[0],&num2[0],&c1[0]);
            sub(&num1[0],&num2[0],&c2[0]);
        }
        else if(k1==0 && k2==1) {
            sub(&num1[0],&num2[0],&c1[0]);
            add(&num1[0],&num2[0],&c2[0]);
        }
        else if(k1==1 && k2==0) {
            sub(&num1[0],&num2[0],&c1[0]);
            add(&num1[0],&num2[0],&c2[0]);
            j1=1;
            j2=1;
        }
        else if(k1==1 && k2==1) {
            add(&num1[0],&num2[0],&c1[0]);
            sub(&num1[0],&num2[0],&c2[0]);
            j1=1;
            j2=1;
        }
    }
    else if(sebig(&num1[0],&num2[0])==1) {
        if(k1==0 && k2==0) {
            add(&num1[0],&num2[0],&c1[0]);
            sub(&num2[0],&num1[0],&c2[0]);
            j2=1;
        }
        else if(k1==0 && k2==1) {
            sub(&num2[0],&num1[0],&c1[0]);
            add(&num1[0],&num2[0],&c2[0]);
            j1=1;
        }
        else if(k1==1 && k2==0) {
            sub(&num2[0],&num1[0],&c1[0]);
            add(&num1[0],&num2[0],&c2[0]);
            j2=1;
        }
        else if(k1==1 && k2==1) {
            add(&num1[0],&num2[0],&c1[0]);
            sub(&num2[0],&num1[0],&c2[0]);
            j1=1;
        }
    }
    mul(&num1[0],&num2[0],&c3[0]);
    if(k1^k2) {
        j3=1;
    } 
    array_out(&c1[0],j1,t3);
    array_out(&c2[0],j2,t3);
    array_out(&c3[0],j3,t3*2);
}