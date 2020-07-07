//https://www.geeksforgeeks.org/easy/dynamic-programming/4/
//recursion

#include <bits/stdc++.h>
using namespace std;

#define MAX 50

int theif_problem(int arr[],int start,int n)
{
    if(start>n)
    {
        return 0;
    }
    
    return max(arr[start]+theif_problem(arr,start+2,n),
    theif_problem(arr,start+1,n));
}

int lcs(int circular_buff[],int start,int prev,int n)
{
    if(start>=n)
    {
        return 1;
    }
    
    int c1=0;
    if(circular_buff[start]>prev || prev==-123)
    {
        c1=1+lcs(circular_buff,start+1,circular_buff[start],n);
    }
    
    return max(c1,lcs(circular_buff,start+1,prev,n));
}

int circular_lcs(int arr[],int n)
{
    int res=INT_MIN;
    int circular_buff[2*n];
    
    for(int i=0;i<n;i++)
    {
        circular_buff[i]=arr[i];
    }
    for(int i=n;i<2*n;i++)
    {
        circular_buff[i]=arr[i-n];
    }
    
    
    for(int i=0;i<n;i++)
    {
        res=max(res,lcs(circular_buff,i,i+n-1,-123));
    }
    
    return res;
}

int sum_all_substring(string s)
{
    int ans=0;
    long long int mf=1;
    for(int i=s.size()-1;i>=0;i--)
    {
        ans+=(s[i]-'0')*(i+1)*mf;
        
        mf=mf*10+1;
    }
    
    return ans;
}

void print_distinct_order(string s)
{
    int arr[256]={0};
    
    for(int i=0;i<s.size();i++)
    {
        arr[s[i]]++;
    }
    
    for(int i=0;i<s.size();i++)
    {
        if(arr[s[i]]==1)
        {
            cout << s[i] ; 
        }
    }
}

int gold_mine(int arr[][MAX],int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return INT_MIN;
    }
    
    if(y==m-1)
    {
        return arr[x][y];
    }
    
    return arr[x][y]+max(gold_mine(arr,x+1,y+1,n,m),
    max(gold_mine(arr,x-1,y+1,n,m),gold_mine(arr,x,y+1,n,m)));
}

//wrong answer
int maximum_sum_path(int arr[][MAX],int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return INT_MIN;
    }
    
    if(y==m-1)
    {
        return arr[x][y];
    }
    
    return arr[x][y]+max(maximum_sum_path(arr,x+1,y-1,n,m),
    max(maximum_sum_path(arr,x+1,y,n,m),maximum_sum_path(arr,x+1,y+1,n,m)));
}


int friends_pairing(int n)
{
    if(n==0)
    {
        return 1;
    }
    
    if(n<0)
    {
        return 0;
    }
    
    return friends_pairing(n-1)+(n-1)*friends_pairing(n-2);
}

int max_sum_path_triangle(int arr[][MAX],int n)
{
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<n;i++)
    {
        dp[n-1][i]=arr[n-1][i];    
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i][j]=arr[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    
    return dp[0][0];
}

int longest_common_subsequence(string s1,string s2,int n,int m)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    
    if(s1[n-1]==s2[m-1])
    {
        return 1+longest_common_subsequence(s1,s2,n-1,m-1);
    }
    
    return max(longest_common_subsequence(s1,s2,n,m-1),
                    longest_common_subsequence(s1,s2,n-1,m));
}

int longest_common_subsequence_3(string s1,string s2,string s3,int n,int m,int k)
{
    if(m==0 || n==0 || k==0)
    {
        return 0;
    }
    
    if(s1[n-1]==s2[m-1] && s2[m-1]==s3[k-1])
    {
        return 1+longest_common_subsequence_3(s1,s2,s3,n-1,m-1,k-1);
    }
    
    return max(longest_common_subsequence_3(s1,s2,s3,n-1,m,k),
            max(longest_common_subsequence_3(s1,s2,s3,n,m-1,k),
                longest_common_subsequence_3(s1,s2,s3,n,m,k-1)));
}

int count_subarray_max_greaterk(int arr[],int n,int k)
{
    int cnt=0;
    int maxi=0;
    
    for(int i=0;i<n;i++)
    {
        maxi=arr[i];
        if(maxi>k)
        {
            cnt++;
        }
        for(int j=i+1;j<n;j++)
        {
            maxi=max(maxi,arr[j]);
            if(maxi>k)
            {
                cnt++;
            }
        }
    }
    
    return cnt;
}

int main() {
    
    // int hval[] = {6, 7, 1, 3, 8, 2, 4}; 
    // int n = sizeof(hval)/sizeof(hval[0]); 
    // cout << "Maximum loot possible : "
    //     << theif_problem(hval,0, n); 
    
    // int arr[] = { 1, 4, 6, 2, 3 }; 
    // int n = sizeof(arr)/sizeof(arr[0]); 
    // cout << "Length of LICS is " << circular_lcs( arr,n ); 
    
    // string num = "6759"; 
    // cout << sum_all_substring(num) << endl; 
    
    // int gold[MAX][MAX]= {{10, 33, 13, 15},
    //               {22, 21, 04, 1},
    //               {5, 0, 2, 3},
    //               {0, 6, 14, 2}};
    // int m = 4, n = 4; 
    // int ans=0;
    // for(int i=0;i<n;i++)
    // {
    //     ans=max(ans,gold_mine(gold,i,0,n,m));
    // }
    // cout << ans;
    
    // int mat[MAX][MAX] = { { 4, 2 , 3 , 4 }, 
    //     { 2 , 9 , 1 , 10}, 
    //     { 15, 1 , 3 , 0 }, 
    //     { 16 ,92, 41, 44 } 
    // }; 
    
    // int m = 4, n = 4;
    // int ans=0;
    // for(int i=0;i<n;i++)
    // {
    //     ans=max(ans,maximum_sum_path(mat,i,0,n,m));
    // }
    // cout << ans ;
    
    // cout << friends_pairing(12);
    
    // int tri[MAX][MAX] = { {8, 0, 0,0}, 
				// 	{2, -4, 0,0}, 
    //                 { 2 , 2, 6, 0},
				// 	{1, 1, 1 , 1 } }; 
    // cout << max_sum_path_triangle(tri, 4); 
    
    // string s1 = "AGGTAB";  
    // string s2 = "GXTXAYB";  
    // int n = s1.length();  
    // int m = s2.length(); 
    // cout<<"Length of LCS is "<< longest_common_subsequence( s1, s2, n , m ) ; 
    
    // string X = "AGGT12"; 
    // string Y = "12TXAYB"; 
    // string Z = "12XBA"; 
    //  cout << "Length of LCS is " << longest_common_subsequence_3(X, Y, Z ,
    //                             X.length(),Y.length(),Z.length()); 
    
    // int arr[] = { 1, 2, 3 , 6 , 5 , 3 }; 
    // int k = 2; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << count_subarray_max_greaterk(arr, n, k); 
	return 0;
}