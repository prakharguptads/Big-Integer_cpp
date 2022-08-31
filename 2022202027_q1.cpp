#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std;

string addition(string a,string b)
{
    string c="";
    int a_len=a.length(),b_len=b.length();
    int m=min(a_len,b_len),carry=0;
    for(int i=1;i<=m;i++)
    {
        int a1=a[a_len-i]-'0',b1=b[b_len-i]-'0';
        int c1=a1+b1+carry;
        if(c1>9)
        {
            c1=c1%10;
            char ch=c1+'0';
            c=ch+c;
            carry=1;
        }
        else
        {
            char ch=c1+'0';
            c=ch+c;
            carry=0;
        }
    }
    if(m==a_len)
    {
        for(int i=m+1;i<=b_len;i++)
        {
            int t = (b[b_len-i]-'0');
            int c1=t+carry;
            if(c1>9)
            {
            c1=c1%10;
            char ch=c1+'0';
            c=ch+c;
            carry=1;
            }
            else
            {
            char ch=c1+'0';
            c=ch+c;
            carry=0;
            }
        }
    }
    else{
        for(int i=m+1;i<=a_len;i++)
        {
            int t = (a[a_len-i]-'0');
            int c1=t+carry;
            if(c1>9)
            {
            c1=c1%10;
            char ch=c1+'0';
            c=ch+c;
            carry=1;
            }
            else
            {
            char ch=c1+'0';
            c=ch+c;
            carry=0;
            }
        }
    }
    if(carry==1)
    c='1'+c;
    return c;
}
string subtraction(string a,string b)
{
    string c;
    int a_len=a.length(),b_len=b.length();
    int m=min(a_len,b_len),bowwor=0;
    for(int i=1;i<=m;i++)
    {
        int a1=a[a_len-i]-'0',b1=b[b_len-i]-'0';
        if(bowwor==1)
        {
            a1--;
            bowwor=0;
        }
        if(a1>=b1)
        {
            c = to_string(a1-b1)+c;
        }
        else{
            a1=10+a1;
            bowwor=1;
            c = to_string(a1-b1)+c;
        }
    }
    for(int i=m+1;i<=a_len;i++)
    {
        int a1=a[a_len-i]-'0',b1=b[b_len-i]-'0';
        if(bowwor==1)
        {
            if(a1==0)
            {
                bowwor=1;
                a1=9;
            }
            else{
                a1--;
                bowwor=0;
            }
        }
        c=to_string(a1)+c;
    }
    while(c.length()>1 && c[0]=='0')
    c=c.substr(1);
    return c; 
    return c; 
}
string multiplication(string a,string b)
{
    string c;
    int a_len=a.length(),b_len=b.length();
    int mul[a_len+b_len];
    for(int i=0;i<a_len+b_len;i++)
    mul[i]=0;
    for(int i=0;i<a_len;i++)
    {
        for(int j=0;j<b_len;j++)
        {
            mul[i+j]+=(a[(a_len-1)-i]-'0')*(b[(b_len-1)-j]-'0');
        }
    }
    for(int i=0;i<(a_len+b_len);i++)
    {
        int d = mul[i]%10;
        int carry=mul[i]/10;
        if(i<(a_len+b_len))
        mul[i+1]+=carry;
        c=to_string(d)+c;
    }
    while(c[0]=='0')
    c=c.substr(1);
    return c; 
}
string gcd(string a,string b)
{
    //cout<<a<<" "<<b<<endl;
    if(a=="0")
    return b;
    if(b=="0")
    return a;
    if(a.length()>b.length() || (a.length()==b.length() && a>b))
    {
        //cout<<subtraction(a,b)<<endl;
        return gcd(subtraction(a,b),b);
        }
    return gcd(a,subtraction(b,a));
}
string exponential(int a,int b)
{
    string c="1";
    for(int i=0;i<b;i++)
        c=multiplication(to_string(a),c);
    return c;
}
string factorial(int a)
{
    string c="1";
    for(int i=2;i<=a;i++)
    c=multiplication(to_string(i),c);
    return c;
}

string operation1(string s)
{
    s=s+"@";
    string result,a="-1",b="-1",c="-1",d="-1",temp="";
    char ch = '#',ch1='#';
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='@')
        {
            temp=temp+s[i];
        }
        else{
            if(ch=='#')
            {
                if(a=="-1")
                a=temp;
                ch=s[i];
                temp="";
            }
            else if(s[i]=='*')
            {
                if(ch=='#')
                ch=s[i];
                else if(ch1=='#')
                {
                    b=temp;
                    ch1=s[i];
                    temp="";
                }
                else
                {
                    b=multiplication(b,temp);
                    temp="";
                    ch1=s[i];
                }
            }
            else
            {
                if(ch1!='#')
                {
                    temp=multiplication(b,temp);
                    ch1='#';
                }
                if(ch=='+')
                a=addition(a,temp);
                else if(ch=='-')
                a=subtraction(a,temp);
                else if(ch=='*')
                a=multiplication(a,temp);
                temp="";
                ch=s[i];
            }
        }
    }
    return a;
}

int main()
{
    int t;
    cin>>t;
    if(t==1)
    {
        string s;
        cin>>s;
        cout<<operation1(s);
    }
    else if(t==2)
    {
        int s,t;
        cin>>s>>t;
        cout<<exponential(s,t);
    }
    else if(t==3)
    {
        string s,t;
        cin>>s>>t;
        cout<<gcd(s,t);
    }
    else
    {
        int s;
        cin>>s;
        cout<<factorial(s);
    }
    return 0;
}
