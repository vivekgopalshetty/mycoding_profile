#include<bits/stdc++.h>
using namespace std;

int s1_to_s2(int mem[][10],string s1,string s2,int start1,int start2)
{
    if(mem[start1][start2]==0)
    {

        if(start1>=s1.length())
        {
            mem[start1][start2]=s2.length()-start2;
        }

        else if(start2>=s2.length())
        {
            mem[start1][start2]=s1.length()-start1;
        }

        else if(s1[start1]==s2[start2])
        {
            mem[start1][start2]=s1_to_s2(mem,s1,s2,start1+1,start2+1);
        }
        else{

            int x1=s1_to_s2(mem,s1,s2,start1+1,start2); //insert
            int x2=s1_to_s2(mem,s1,s2,start1,start2+1); //delete
            int x3=s1_to_s2(mem,s1,s2,start1+1,start2+1); //replaces
            mem[start1][start2]=1+min(x1,min(x2,x3));
        }

    }

    return mem[start1][start2];
}


int main()
{
    string s1,s2;
    cin >> s1;
    cin >> s2;

    int mem[100][10]={};
    cout << s1_to_s2(mem,s1,s2,0,0);
}
