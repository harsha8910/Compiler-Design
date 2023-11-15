#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void matched(char* str)
{
    int length=strlen(str);
    int col=0;
    int row=0;
    int arr[6][2]={{0,1},
                    {2,3},
                    {4,5},
                    {0,1},
                    {2,3},
                    {4,5}};
    for(int i=0;i<length;i++)
    {
        if(str[i]=='0')
            col=0;
        else
            col=1;
        row=arr[row][col];
    }
    if(row==0)
        printf("The given string is divisible by 6\n");
    else
        printf("The given string is not divisible by 6\n");
}
int main()
{
    printf("Enter the string:");
    char* str=(char*)malloc(20*sizeof(char));
    scanf("%[^\n]s",str);
    matched(str);
    return 0;
}