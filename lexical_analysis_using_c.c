#include <iostream>

using namespace std;
int search(string a1[], string a2[], string a3[], string tok)
{
    //array1
    int i;
    for(i=0 ; i<15 ; i++)
    {
        if(tok==a1[i])
            return 1;
    }
    for(i=0 ; i<18 ; i++)
    {
        if(tok==a2[i])
            return 2;
    }
    for(i=0 ; i<32 ; i++)
    {
        if(tok==a3[i])
            return 3;
    }
    for (int i = 0; i < tok.length(); i++) {
        if (isdigit(tok[i]) == false) {
            return 5;
        }
    }
    return 4;
}

int main()
{
    string keywords[32]={"auto","break","case","char","const","continue","default","do",
                        "double","else","enum","extern","float","for","goto","if",
                        "int","long","register","return","short","signed","sizeof","static",
                        "struct","switch","typedef","union","unsigned","void","volatile","while"};
                        
                        
    string delimiters[18]={"@","#","$","^","(",")","_","[","]","{","}","\\",
    ";",":","\"","'",",","."};
    
    string operators[15]={"+","-","*","/","%","|","||","&&","&","!","~","<",">","=","?"};
    
    
    char arr[100];
    cin.getline(arr,100);
    char separator=' ';
    int i=0;
    int top=0;
    string tokens[100];
    
    string s; 
    while(arr[i]!='\0') 
    {
        if(arr[i]!=separator) 
        {
            s+=arr[i]; 
        } 
        else 
        {
            tokens[top]=s;
            cout<<tokens[top]<<endl;
            top++;
            s.clear();
        }
        i++;
    }
    tokens[top]=s;
    cout<<tokens[top]<<endl;
    top++;
    cout<<top<<endl;
    for(int j=0;j<top;j++)
    {
        int flag=search(operators,delimiters,keywords,tokens[j]);
        if(flag==1)
        cout<<tokens[j]<<" is an operator"<<endl;
        else if(flag==2)
        cout<<tokens[j]<<" is a delimiter"<<endl;
        else if(flag==3)
        cout<<tokens[j]<<" is a Keyword"<<endl;
        else if(flag==4)
        cout<<tokens[j]<<" is a Number"<<endl;
        else
        cout<<tokens[j]<<" is a Variable or String"<<endl;
    }
    
    return 0;
}

