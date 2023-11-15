#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void matched(char* arr)
{
    int length=strlen(arr);
    int temp=0;
    for(int i=0;i<length;i++)
    {
        if(arr[i]=='a' && temp==0)
            temp=1;
        else if(arr[i]=='b' && temp==0)
            temp=3;
        else if(arr[i]=='a' && temp==1)
            temp=2;
        else if(arr[i]=='b' && temp==1)
            temp=3;
        else if(arr[i]=='a' && temp==2)
            temp=2;
        else if(arr[i]=='b' && temp==2)
            temp=3;
        else if(arr[i]=='a' && temp==3)
            temp=1;
        else if(arr[i]=='b' && temp==3)
            temp=4;
        else if(arr[i]=='a' && temp==4)
            temp=1;
        else if(arr[i]=='b' && temp==4)
            temp=4;
    }
    if(temp==2 || temp==4)
        printf("The string is accepted");
    else
        printf("The string is not accepted");
}
int main()
{
    char* arr=(char*)malloc(20*sizeof(char));
    scanf("%[^\n]s",arr);
    matched(arr);
    return 0;
}