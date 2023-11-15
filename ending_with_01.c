#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void matched(char* str)
{
    int length=strlen(str);
    int col=0;
    int row=0;
    int arr[3][2]={{1,0},
                    {1,2},
                    {1,0}};
    for(int i=0;i<length;i++)
    {
        if(str[i]=='0')
            col=0;
        else
            col=1;
        row=arr[row][col];
    }
    if(row==2)
        printf("The given string is ending with 01\n");
    else
        printf("The given string is not ending with 01\n");
}
int main()
{
    printf("Enter the string:");
    char* str=(char*)malloc(20*sizeof(char));
    scanf("%[^\n]s",str);
    matched(str);
    return 0;
}