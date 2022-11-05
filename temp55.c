#include <stdio.h>
#define gate void (*x1)(struct gate_s*)

typedef struct gate_s {
    int in1;
    int in2;
    int out1;
    gate;
} gate_t;

void AND(gate_t *logicgate)
{
    if(logicgate->in1==0 || logicgate->in2==0)
    {
        logicgate->out1 = 0;
        return;
    }
    logicgate->out1 = 1;
}

void OR(gate_t *logicgate)
{
    if(logicgate->in1==1 || logicgate->in2==1)
    {
        logicgate->out1 = 1;
        return;
    }
    logicgate->out1 = 0;
}

void XOR(gate_t *logicgate)
{
    if((logicgate->in1==1 && logicgate->in2==0) || (logicgate->in1==0 && logicgate->in2==1))
    {
        logicgate->out1 = 1;
        return;
    }
    logicgate->out1 = 0;
}

void NOT(gate_t *logicgate)
{
    if(logicgate->in1==1)
    {
        logicgate->out1 = 0;
        return;
    }
    logicgate->out1 = 1;
}

void EMPTY(gate_t *logicgate)
{
    logicgate->out1 = logicgate->in1;
}

int main()
{
    int I1,I2,I3,I4;
    char x1[6]={};
    gate_t logicgate[6];
    scanf("%d,%d,%d,%d",&I1,&I2,&I3,&I4);
    scanf(" %c,%c,%c,%c,%c,%c",&x1[0],&x1[1],&x1[2],&x1[3],&x1[4],&x1[5]);
    for (int i=0; i<6; i++)
    {
        switch (x1[i])
        {
            case 'A': logicgate[i].x1=AND; break;
            case 'O': logicgate[i].x1=OR; break;
            case 'X': logicgate[i].x1=XOR; break;
            case 'N': logicgate[i].x1=NOT; break;
            case 'E': logicgate[i].x1=EMPTY; break;
        }
    }
    logicgate[0].in1=I1;
    logicgate[0].in2=I2;
    logicgate[2].in2=I3;
    logicgate[4].in2=I4;
    logicgate[0].x1(&logicgate[0]);
    logicgate[1].in1=logicgate[0].out1;
    logicgate[2].in1=logicgate[0].out1;
    logicgate[1].x1(&logicgate[1]);
    logicgate[2].x1(&logicgate[2]);
    logicgate[3].in1=logicgate[1].out1;
    logicgate[3].in2=logicgate[2].out1;
    logicgate[4].in1=logicgate[2].out1;
    logicgate[3].x1(&logicgate[3]);
    logicgate[4].x1(&logicgate[4]);
    logicgate[5].in1=logicgate[3].out1;
    logicgate[5].in2=logicgate[4].out1;
    logicgate[5].x1(&logicgate[5]);
    printf("%d,%d,%d\n",logicgate[1].out1,logicgate[3].out1,logicgate[5].out1);
}