#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print(vector<char> abc){
    for(int i=0;i<abc.size();i++){
        cout<<abc[i]<<",";
    }
    cout<<endl;
}
void print(vector<string> abc){
    for(int i=0;i<abc.size();i++){
        cout<<abc[i]<<",";
    }
    cout<<endl;
}
void lexical_analyzer(string s)
{
    vector<char> operator1;
    vector<string> number,identifier;
    vector<char> delim;
    for(int i=0;i<s.size();i++ ){
        if(int(s[i])>= 65 && s[i]<=90 || (s[i]>=97 && s[i]<=122))
        {
            string n=" ";
            for(i;i<s.size();i++){
                if(int(s[i])>= 65 && s[i]<=90 || (s[i]>=97 && s[i]<=122))
                    n=n+s[i];
                else 
                break;
            }
            i--;
            identifier.push_back(n);
        }
        else if(int(s[i])>= 48 && s[i]<=57 ){
            string num=" ";
            for(i;i<s.size();i++){
                if(int(s[i])>= 48 && s[i]<=57 )
                    num=num+s[i];
                else{
                    break;
                }
            }
            i--;
            number.push_back(num);
        }
        else if( int(s[i]==42) || (int(s[i])==43) || (int(s[i])==45) || (int(s[i])==47))
             operator1.push_back(s[i]);
        else{
        	if(int(s[i])!=61) //= Ascii 61
			delim.push_back(s[i]);
        }
            
    }
    cout<<"Identifier:" ;
    print(identifier);
    cout<<"Constant:" ;
    print(number);
    cout<<"Operator:" ;
    print(operator1);
    cout<<"Delimiter:";
    print(delim);
}
int main()
{
    string a;
    cout<<"Enter Expression for Lexical Analysis : ";
    cin>>a;
    cout<<endl;
    lexical_analyzer(a);
    return 0;
}
