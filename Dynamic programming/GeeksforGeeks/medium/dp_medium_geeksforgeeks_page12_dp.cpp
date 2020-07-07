//https://www.geeksforgeeks.org/medium/dynamic-programming/12/
//recursion

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999
#define inf 99999999
#define mod 1000000007

set<string> st;
void cnt_distinct_subseq(string s,string prefix,int n)
{
    if(n==0)
    {
       st.insert(prefix);
       return;
    }
    
    cnt_distinct_subseq(s,prefix,n-1);
    cnt_distinct_subseq(s,prefix+s[n-1],n-1);
}

int min_cost(int cost[],int n,int w,int ans)
{
    if(w==0)
    {
        return ans;
    }
    
    if(w<0)
    {
        return INT_MAX;
    }
    
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(cost[i]!=-1)
        {
              mini=min(mini,min_cost(cost,n,
                w-(i+1),ans+cost[i]));   
        }
    }
    
    return mini;
    
}

int cnt_t_in_s(string s,string t,int n,int m)
{
    if(n==0)
    {
        if(m==0)
        {
            return 1;
        }
        
        return 0;
    }
    
    if(m==0)
    {
        return 1;
    }
    
    int ans=0;
    if(s[n-1]==t[m-1])
    {
        ans+=cnt_t_in_s(s,t,n-1,m-1);
    }
    
    ans+=cnt_t_in_s(s,t,n-1,m);
    return ans;
}

int LCS(string X, string Y, int m, int n) 
{ 
    // Build L[m+1][n+1] in bottom up fashion 
    int L[m+1][n+1];
    for (int i = 0; i <= m; i++) 
    { 
        for (int j = 0; j <= n; j++) 
        { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
    return L[m][n]; 
} 

set<string> lcsst;
void printing_all(string s,string t,int n,int m,string prefix,int len)
{
    if(m==0 || n==0)
    {
       if(prefix.length()==len)
       {
           lcsst.insert(prefix);
       }
       return;
    }

    if(s[n-1]==t[m-1])
    {
        printing_all(s,t,n-1,m-1,prefix+s[n-1],len);
    }
    
    printing_all(s,t,n-1,m,prefix,len);
    printing_all(s,t,n,m-1,prefix,len);
}

int longest_pall_subseq(string s,string t,int n,int m)
{
     if(m==0)
    {
       return n;
    }
    
    if(n==0)
    {
        return m;
    }

    if(s[n-1]==t[m-1])
    {
        return longest_pall_subseq(s,t,n-1,m-1);
    }
    
    return 1+min(longest_pall_subseq(s,t,n-1,m),longest_pall_subseq(s,t,n,m-1));
}

bool check_if_kpall(string s,int k)
{
    int n=s.length();
    string t=s;
    reverse(s.begin(),s.end());
    
    return (longest_pall_subseq(s,t,n,n) <= 2*k);
}

int min_time_skip_no_2cons(int arr[],int n,bool prev)
{
    if(n==0)
    {
        return 0;
    }
    
    if(!prev)
    {
        return arr[n-1]+min_time_skip_no_2cons(arr,n-1,true);
    }
    else
    {
       return min(arr[n-1]+min_time_skip_no_2cons(arr,n-1,true),
       min_time_skip_no_2cons(arr,n-1,false));   
    }
}

int cnt_ways_no_2balls_adjancent_samcol(int p,int q,int r,int last)
{
      if(p<0 || q<0 || r<0)
    {
        return 0;
    }
    
    if(p==0 && q==0 && r==0)
    {
        return 1;
    }
    
    if(last==1)
    {
        return cnt_ways_no_2balls_adjancent_samcol(p,q-1,r,2)+
            cnt_ways_no_2balls_adjancent_samcol(p,q,r-1,3);
    }
    else if(last==2)
    {
        return cnt_ways_no_2balls_adjancent_samcol(p-1,q,r,1)+
            cnt_ways_no_2balls_adjancent_samcol(p,q,r-1,3);
    }
    else if(last==3)
    {
        return cnt_ways_no_2balls_adjancent_samcol(p-1,q,r,1)+
            cnt_ways_no_2balls_adjancent_samcol(p,q-1,r,2);
    }
    else
    {
        return cnt_ways_no_2balls_adjancent_samcol(p-1,q,r,1)+
            cnt_ways_no_2balls_adjancent_samcol(p,q-1,r,2)+
            cnt_ways_no_2balls_adjancent_samcol(p,q,r-1,3);
    }
}

int main()
{
    // string s="ggg";
    // string p="";
    // cnt_distinct_subseq(s,p,s.length());
    // cout << st.size();
    
    // int W = 5;
    // int cost[] = {-1, -1, 4, 5, -1};
    // int n=sizeof(cost)/sizeof(cost[0]);
    // cout << min_cost(cost,n,W,0);
    
    // string a = "GeeksforGeeks";
    // string b = "Gks";
    // cout << cnt_t_in_s(a,b,a.length(),b.length());
    
    // string X = "AATCC";
    // string Y = "ACACG";
    // int len=LCS(X,Y,X.length(),Y.length());
    // printing_all(X,Y,X.length(),Y.length(),"",len);
    
    //  for (string str : lcsst)
    //  {
    //     reverse(str.begin(),str.end());
    //     cout << str << endl;
    //  }
    
    // int arr[] = {10, 5, 2, 7, 10}; 
    // int n = sizeof(arr)/sizeof(arr[0]); 
    // cout << min(min_time_skip_no_2cons(arr,n,true),
    //             min_time_skip_no_2cons(arr, n,false)) << endl; 
  
    
    cout << cnt_ways_no_2balls_adjancent_samcol(1,1,1,-1);
}