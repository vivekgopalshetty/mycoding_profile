//https://www.geeksforgeeks.org/medium/dynamic-programming/6/
//recursion


#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int fact(int n)
{
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
    }
    
    return ans;
}

int numberofbst(int n)
{
    return fact(2*n)/(fact(n+1)*fact(n));
}

int numberofBTs(int n)
{
    return numberofbst(n)*fact(n);
}

int max_profit_wines(int arr[],int start,
           int end,int year)
{
    if(start>end)
    {
        return 0;
    }
    
    return max(arr[start]*year+
    max_profit_wines(arr,start+1,end,year+1),arr[end]*year+
    max_profit_wines(arr,start,end-1,year+1));
    
}

int cnt_decreaing_paths(int arr[MAX][MAX],int x,int y,
                        int n,int m)
{
    if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return 0;
    }
    
    int ans=1;
    if(arr[x][y]>arr[x-1][y])
    {
        ans+=cnt_decreaing_paths(arr,x-1,y,n,m);
    }
    
     if(arr[x][y]>arr[x][y-1])
    {
        ans+=cnt_decreaing_paths(arr,x,y-1,n,m);
    }
    
     if(arr[x][y]>arr[x+1][y])
    {
        ans+=cnt_decreaing_paths(arr,x+1,y,n,m);
    }
    
     if(arr[x][y]>arr[x][y+1])
    {
        ans+=cnt_decreaing_paths(arr,x,y+1,n,m);
    }
    
    return ans;
}


int cnt_all_decreasing_paths(int mat[MAX][MAX],int n,int m)
{
    int dp[MAX][MAX];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=0;
        }
    }
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans+=cnt_decreaing_paths(mat,i,j,n,m);
        }
    }
    
    return ans;
}

int dp_k[MAX][MAX];
int longest_till_i_andinclude_kind(int arr[],int n, int prev){
    if(n<0)
        return 0;
        
    if(dp_k[n][prev]) 
        return dp_k[n][prev];
    
    int inc=0;
    int exc = 0;
    if(arr[n] < prev)
    {
        inc = prev+ longest_till_i_andinclude_kind(arr,n-1,arr[n]);
    }
    
    exc = longest_till_i_andinclude_kind(arr,n-1,prev);
    
    return dp_k[n][prev] = max(inc,exc);

}

void printsets(vector<int> s1,vector<int> s2)
{
    for(int i=0;i<s1.size();i++)
    {
        cout << s1[i] << " ";
    }
    cout << endl;
    
     for(int i=0;i<s2.size();i++)
    {
        cout << s2[i] << " ";
    }
}

int partition_problem(vector<int> v,int start,
            vector<int>& s1,vector<int>& s2,int sum1,int sum2)
{
    if(start==v.size())
    {
        if(sum1==sum2)
        {
            printsets(s1,s2);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    s1.push_back(v[start]);
    bool res=partition_problem(v,start+1,s1,s2,sum1+v[start],sum2);
    
    if(res)
        return res;
        
    s1.pop_back();
    s2.push_back(v[start]);
    res=partition_problem(v,start+1,s1,s2,sum1,sum2+v[start]);
    
    if(res==false)
    {
        if(!s2.empty())
        {
            s2.pop_back();
        }
    }
    
    return res;
}

int max_res_afterops(int arr[],int start,int n,int res,int& maxi)
{
     if(res>maxi || res<0)
    {
        return INT_MIN;
    }
    
    if(start>=n)
    {
        return res;
    }
    
    return max(max_res_afterops(arr,start+1,n,res-arr[start],maxi),
         max_res_afterops(arr,start+1,n, res+arr[start],maxi));
   
}

int forming_string(string s,string prefix,int start)
{
    if(start>s.length())
    {
        return INT_MAX;
    }
    
    if(s==prefix)
    {
        return 0;
    }
    
    int c1=INT_MAX;
    if(prefix[0]==s[start])
    {
        c1=forming_string(s,prefix+prefix,start+prefix.length());
    }
    
    return 1+min(c1,forming_string(s,prefix+s[start],start+1));
}

bool check_divsible(int arr[],int& n,int& m,int start,int sum)
{
    if(start==n)
    {
        if(sum%m==0)
        {
            return true;
        }
        return false;
    }
    
    return check_divsible(arr,n,m,start+1,sum+arr[start]) || 
            check_divsible(arr,n,m,start+1,sum-arr[start]);
}

int main() {
	
  //int price[] = { 2, 4, 6, 2, 5 }; 
  //int n = sizeof(price) / sizeof(price[0]); 
  //cout << max_profit_wines(price,0, n-1, 1);
  
  //   int mat[MAX][MAX]={ { 1, 2, 3 },
  //                   { 1, 3, 4 },
  //                   { 1, 5, 6 } };
  //   int n=3;
  //   int m=3;
  //   cout << cnt_all_decreasing_paths(mat,n,m);
  
    // int arr[] = {1, 101, 2, 3, 100, 4, 5};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int k = 6;
    // int i = 4;
    // memset(dp_k,0,sizeof(dp_k));
    // cout << longest_till_i_andinclude_kind(arr,i,arr[k]);
    
//   vector<int> s1;
//   vector<int> s2;
//   vector<int> v={5, 5, 1, 11};
//   partition_problem(v,0,s1,s2,0,0);

//   int arr[]={3, 10, 6, 4, 5};
//   int n=sizeof(arr)/sizeof(arr[0]);
//   int res=1;
//   int max=15;
//   cout << max_res_afterops(arr,0,n,res,max);

    // string s= "aaaaaa";
    // cout << forming_string(s,"",0);
    
    // int arr[]= {1, 3, 9};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int  m = 2;
    // cout << check_divsible(arr,n,m,0,0);
	return 0;
}