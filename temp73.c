#include <stdio.h>

int den(int x1) {
    if(x1<1) return 0;
    printf("%d\n",24);
    den(x1-1);
    printf("%d\n",3);
    den(x1-2);
    printf("%d\n",18);
}

int main() {
    int x1;
    int x2;
    x1=3;
    den(x1);
}