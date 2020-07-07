
#include<bits/stdc++.h>
using namespace std;

int longest_common_subsequnce(string s1,string s2)
{
    int dp[100][100]={};

    for(int i=s2.length();i>=1;i--)
    {
        for(int j=s1.length();j>=1;j--)
        {
            int x1=0;
            if(s1[i-1]==s2[j-1])
            {
                x1=max(1+dp[i-1][j-1],max(dp[i][j+1],dp[i+1][j]));
            }
            else
            {
               int x2=dp[i+1][j];
               int x3=dp[i][j+1];
               x1=max(x2,x3);

            }

            dp[i][j]=x1;
        }
    }

    return dp[0][0];

}

int main()
{
    string s1,s2;
    cin >> s1;
    cin >> s2;

    int dp[100][100]={};
    cout << longest_common_subsequnce(s1,s2);
}

