/* 计算桥牌发牌组合数 52!/13!*13!*13! */
/* 大数相乘 */
#include <stdio.h>
#include <string.h>

/*
 * 输入：A[]，B[]，每个字符都是数字字符
 * 输出：C[]，每个字符都是数字字符
 */
void Multiple(char A[], char B[], char C[])
{
    int TMP=0;  /* 两位相乘临时保存 */
    int In=0;   /* 两位相乘的进位 */
    int LenA=-1, LenB=-1;       /* 输入AB的字符个数 */
    while(A[++LenA] != '\0');   /* 计算A的字符个数 */
    while(B[++LenB] != '\0');   /* 计算B的字符个数 */
    int Index;                  /* 保存C修改位置的Index */
    int Start = LenA + LenB - 1;

    /* 输出保存字符串的初始化 */
    for(int l = 0; l < Start+1; l++)
        C[l]='0';
    /*printf("C=[%s]\n", C);*/

    /* 将B中从最后一位开始，每一位乘以A中的值递进 */
    for(int i=LenB-1; i>=0; i--)
    {
        Index = Start--;
        if(B[i] != '0')
        {
            In = 0;
            for(int j=LenA-1; j>=0; j--)
            {
                TMP = (C[Index]-'0') + (A[j]-'0') * (B[i] - '0') + In;
                C[Index--] = TMP % 10 + '0';
                In = TMP / 10;
                /*printf("In=[%d]C[%d]=[%c]\n", In,Index+1,C[Index+1]);*/
            }
            C[Index] = In + '0';
            /*printf("In=[%d]C[%d]=[%c]\n", In,Index,C[Index]);*/
        }
    }

    int m = 0, h = 0;
    while(C[m] == '0') m++;
    while(C[m] != 0x00) C[h++]=C[m++];
    while(h<100)    C[h++]=0x00;
    printf("C=[%s]\n", C);

    return;
}

/* 单次乘法的数组 */
char A[100];
char C[100];
char B[100];

int main(void)
{
    /*输出计算数据*/
    int count=1;
    /*保存数据*/
    int total[39];
    for(int i=0; i<39 ; i++)
    {
        total[i]=i+14;
        /*printf("total[%d]=%d\n",i,total[i]);*/
    }
    /*3次循环除以2-13*/
    for(int k=0;k<3;k++)
    {
        for(int j=2;j<14;j++)
        {
            int s=0;
            while(total[s]%j!=0)    s++;
            total[s]/=j;
        }
    }

    for(int t=0;t<39;t++)
    {
        if(total[t] > 1)
            printf("%d ",total[t]);
    }
    for(int t=0;t<39;t++)
    {
        if(count*total[t]>11297762)
        {
            printf("\ncount=%d\n",count);
            count=total[t];
        }
        else
            count*=total[t];
    }
    printf("\ncount=%d\n",count);

    memset(A,0x00,sizeof(A));sprintf(A,"%d",1);
    /*将total里的每个数字相乘*/
    for(int l=0;l<39;l++)
    {
        memset(B,0x00,sizeof(B));
        sprintf(B,"%d",total[l]);
        memset(C,0x00,sizeof(C));

        printf("A=[%s]\t", A);
        printf("B=[%s]\t", B);
        Multiple(A, B, C);
        /* 将计算结果中的C赋值回A */
        int m = 0, h = 0;
        while(C[m] == '0') m++;
        while(C[m] != 0x00) A[h++]=C[m++];

        /*printf("Aout=[%s]\n", A);*/
    }

    /*将count里的每个数字相乘*/
    int D[]={534888,458490,1771560,246820,2118760,204};
    memset(A,0x00,sizeof(A));sprintf(A,"%d",1);
    for(int l=0;l<6;l++)
    {
        memset(B,0x00,sizeof(B));
        sprintf(B,"%d",D[l]);
        memset(C,0x00,sizeof(C));

        printf("A=[%s]\t", A);
        printf("B=[%s]\t", B);
        /*printf("C=[%s]\n", C);*/
        Multiple(A, B, C);
        /*printf("Cout=%s\n", C);*/
        /* 将计算结果中的C赋值回A */
        int m = 0;
        while(C[m] != 0x00) A[m]=C[m],m++;
    }

    return 0;
}
//End of files
