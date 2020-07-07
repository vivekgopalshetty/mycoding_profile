//https://www.geeksforgeeks.org/medium/dynamic-programming/10/
//recustion

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999
#define inf 99999999
#define mod 1000000007 

int seq_len_elem_gt_or_twice_ofprev(int m,int n)
{
    if(n>m)
    {
        return 0;
    }
    
    if(n==0)
    {
        return 1;
    }
    
    return seq_len_elem_gt_or_twice_ofprev(m/2,n-1)+seq_len_elem_gt_or_twice_ofprev(m-1,n);
}

int min_deletions_to_make_string_pall(string s,int start,int end)
{
    if(start==end)
    {
        return 0;
    }
    
    if(s[start]==s[end] && start==end+1)
    {
        return 0;
    }
    
    if(s[start]==s[end])
    {
        return min_deletions_to_make_string_pall(s,start+1,end-1);
    }
    
    return 1+min(min_deletions_to_make_string_pall(s,start+1,end),
        min_deletions_to_make_string_pall(s,start,end-1));
}

//modify 1 or elem itself
int max_adj_diff_modify_arr(int arr[],int start,int n,int diff)
{
    if(start==n-1)
    {
        return diff;
    }

    int c1=max_adj_diff_modify_arr(arr,start+1,n,diff+abs(arr[start]-arr[start+1]));
    arr[start+1]=1;
    int c2=max_adj_diff_modify_arr(arr,start+1,n,diff+abs(arr[start]-1));
    return max(c1,c2);
}

int cnt_string_oneb_twocs_atmost(int start,int n,int b_cnt,int c_cnt)
{
    if(start==n)
    {
         if(b_cnt<=1 && c_cnt<=2)
        {
            return 1;
        }
        
        return 0;
    }
    
    
    int res=0;
    res+=cnt_string_oneb_twocs_atmost(start+1,n,b_cnt,c_cnt);
    res+=cnt_string_oneb_twocs_atmost(start+1,n,b_cnt,c_cnt+1);
    res+=cnt_string_oneb_twocs_atmost(start+1,n,b_cnt+1,c_cnt);

    return res;
}

int highway_billboard(int arr[],int val[],int start,int prev,int n,int k)
{
    if(start==n)
    {
        return 0;
    }
    
    int c1=INT_MIN;
    if(arr[start]-prev>k || prev==0)
    {
        c1=val[start]+highway_billboard(arr,val,start+1,arr[start],n,k);
    }
    
    int c2=highway_billboard(arr,val,start+1,prev,n,k);
    return max(c1,c2);
}

int ans=inf;
void solve(int i, int par, int a[], int n, 
                  int k, int current_ans) 
{ 
    if (par > k) 
        return; 
        
    if (par==k && i==n-1) 
    { 
        ans = min(ans, current_ans); 
        return; 
    } 
  
    for (int j=i+1; j<n; j++) 
        solve(j, par+1, a, n, k, current_ans + 
                  (a[j]-a[i+1])*(a[j]-a[i+1])); 
} 

     
int main()
{
    
    // int n=4;
    // int m=10;
    // cout << seq_len_elem_gt_or_twice_ofprev(m,n);
    
    // string s="geeksforgeeks";
    // cout << min_deletions_to_make_string_pall(s,0,s.length()-1);
    
    // int arr[] = {3, 2, 1, 4, 5};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << max_adj_diff_modify_arr(arr,0,n,0);
    
   // cout << cnt_string_oneb_twocs_atmost(0,10,0,0);
   
   
    // int x[] = {6, 9, 12, 14};
    // int revenue[] = {5, 6, 3, 7};
    // int n=sizeof(x)/sizeof(x[0]);
    // int t = 2;
    // cout << highway_billboard(x,revenue,0,0,n,t);
    
    // int k = 2; 
    // int a[] = {1, 5, 8, 10}; 
    // int n = sizeof(a)/sizeof(a[0]); 
    // solve(-1, 0, a, n, k, 0); 
    
}