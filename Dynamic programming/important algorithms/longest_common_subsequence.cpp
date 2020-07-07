#include<bits/stdc++.h>
using namespace std;

int longest_common_subsequnce(string s1,string s2,int dp[][100],int start1,int start2)
{
    if(start1>=s1.length() || start2>=s2.length())
    {
        return 0;
    }

    if(dp[start1][start2]!=0)
    {
        return dp[start1][start2];
    }
    int x1=0;
    if(s1[start1]==s2[start2])
    {
        x1=1+longest_common_subsequnce(s1,s2,dp,start1+1,start2+1);
    }

    int x2=longest_common_subsequnce(s1,s2,dp,start1+1,start2);
    int x3=longest_common_subsequnce(s1,s2,dp,start1,start2+1);

    dp[start1][start2]=max(x1,max(x2,x3));
    return dp[start1][start2];
}

int main()
{
    string s1,s2;
    cin >> s1;
    cin >> s2;

    int dp[100][100]={};
    cout << longest_common_subsequnce(s1,s2,dp,0,0);
}

