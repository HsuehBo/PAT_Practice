#include "cstdio"
#include "stdlib.h"
#include "algorithm"
#include "iostream"
#include <bits/stdc++.h>
using namespace std;

char sentence[10086];
/*δACԭ���Ϊ���ӣ���Ҫ��û�з�������Ŀ���ص㣬�������ӻ�������*/
int main()
{
    memset(sentence,'\0',sizeof(sentence));
    while(scanf("%s",sentence)!=EOF)
    {
        int Epos = -1;
        int tempDir = 0;
        while(sentence[tempDir]!='E')
        {
            tempDir++;
        }
        Epos = tempDir;
        if(sentence[0]=='-')
            printf("-");
        char moveSig = sentence[Epos+1];
        int moveBit = 0;
        for(int i=Epos+2; i<strlen(sentence); i++)
        {
            moveBit = moveBit*10 + sentence[i] - '0';
        }
        if(moveSig=='+') //����
        {
            for(int i=1; i<Epos; i++)
            {
                if(sentence[i]=='.')
                    continue;
                printf("%c",sentence[i]);
                if(i==moveBit+2&&i!=Epos-1)
                    printf(".");
                //+3.1425926535E+4;
            }
//            printf("\n%d %d\n",moveBit,strlen(sentence));
            for(int i=0; i<moveBit-(Epos-3); i++)
                printf("0");
        }
        else  //����
        {
            printf("0.");
            for(int i=0; i<moveBit-1; i++)
                printf("0");
            for(int i=1; i<Epos; i++)
            {
                if(sentence[i]=='.')
                    continue;
                printf("%c",sentence[i]);
            }
        }
        printf("\n");
        memset(sentence,'\0',sizeof(sentence));
    }
    return 0;
}
