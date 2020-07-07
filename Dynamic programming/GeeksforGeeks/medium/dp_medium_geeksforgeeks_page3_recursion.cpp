//https://www.geeksforgeeks.org/medium/dynamic-programming/3/
//recursion

#include <bits/stdc++.h>
using namespace std;

int min_cubes_req(int k)
{
   if (k < 8) 
        return k; 
        
    int res = k; 
    for (int i = 1; i <= k; i++) { 
        if ((i * i * i) > k) 
            return res; 
        res = min(res,min_cubes_req(k - (i * i * i)) + 1); 
    } 
    return res;
    
}

int pallindrome(string s,int start,int end)
{
    if(start>end)
    {
        return 0;
    }
    
    if(s[start]==s[end] && pallindrome(s,start+1,end-1)==s.length()==end-start+1)
    {
        return 2+pallindrome(s,start+1,end-1);
    }
    
    return max(pallindrome(s,start+1,end),pallindrome(s,start,end-1));
}

int solve(int i, int x, int dp[][4]) 
{ 
	if (i < 0) 
		return x == 3; 
	if (dp[i][x] != -1) 
		return dp[i][x]; 

	dp[i][x] = solve(i - 1, 0, dp); 

	dp[i][x] += solve(i - 1, x + 1, dp); 
	return dp[i][x]; 
} 

int subsequence_not_less_thank(int arr[],int start,int end,int k)
{
    if(start>end)
    {
        return 0;
    }
    
    return max(arr[start]+subsequence_not_less_thank(arr,start+k+1,end,k),
    subsequence_not_less_thank(arr,start+1,end,k));
}

int ways_to_score_r(int r,int b,int w,int arr[])
{
    if(w<=0 && r>0)
    {
        return 0;
    }
    
    if(r<0)
    {
        return 0; 
    }
    
    if(b<=0 && r!=0)
    {
        return 0;
    }
    
    if(r==0 && b==0)
    {
        return 1;
    }
    
    int ways=0;
    for(int i=0;i<7;i++)
    {
        if(arr[i]==-1)
        {
            ways+=ways_to_score_r(r,b-1,w-1,arr);
        }
        else
        {
            ways+=ways_to_score_r(r-arr[i],b-1,w,arr);
        }
    }
    
    return ways;
}

int max_sum_3arrays_nocons(int arr1[],int arr2[],int arr3[],int index,int start,int end)
{
   if(start>end)
   {
       return 0;
   }
   
   if(index==1)
   {
       return max(arr2[start]+max_sum_3arrays_nocons(arr1,arr2,arr3,2,start+1,end),
       arr3[start]+max_sum_3arrays_nocons(arr1,arr2,arr3,3,start+1,end));
   }
   else  if(index==2)
   {
       return max(arr1[start]+max_sum_3arrays_nocons(arr1,arr2,arr3,1,start+1,end),
       arr3[start]+max_sum_3arrays_nocons(arr1,arr2,arr3,3,start+1,end));
   }
   else  if(index==3)
   {
       return max(arr2[start]+max_sum_3arrays_nocons(arr1,arr2,arr3,2,start+1,end),
       arr1[start]+max_sum_3arrays_nocons(arr1,arr2,arr3,1,start+1,end));
   }
   
   return max(arr1[start]+max_sum_3arrays_nocons(arr1,arr2,arr3,1,start+1,end),
   max(arr2[start]+max_sum_3arrays_nocons(arr1,arr2,arr3,2,start+1,end),
   arr3[start]+max_sum_3arrays_nocons(arr1,arr2,arr3,3,start+1,end)));
}

int min_cost_path_jumps_lessthank(int arr[],int start,int end,int k)
{
    if(start>=end)
    {
        return INT_MAX;
    }
    
    if(start==end-1)
    {
        return 0;
    }
    
    int mini=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(start+i<end)
        {
            mini=min(mini,abs(arr[start]-arr[start+i])+
            min_cost_path_jumps_lessthank(arr,start+i,end,k));
        }
    }
    
    return mini;
    
}

int min_steps_delete_elems(int start,int end,string s)
{
    if(start>end)
    {
        return 0;
    }
    
    if(start==end)
    {
        return 1;
    }
    
    int res=1+min_steps_delete_elems(start+1,end,s);
    
    for(int i=start+1;i<=end;i++)
    {
        if(s[start]==s[i])
        {
            res=min(res,min_steps_delete_elems(start,i-1,s)+
                    min_steps_delete_elems(i+1,end,s));
        }
    }
    
    return res;
}

int min_prod_distance_k(int arr[],int start,int end,int k)
{
    if(start>end)
    {
        return 1;
    }
    
    int res=INT_MAX;
    for(int i=start+1;i<start+k;i++)
    {
        if(i<end)
        {
            res=min(res,arr[start]*min_prod_distance_k(arr,i,end,k));
        }
    }
    
    return res;
}

int main() {
    
    // int n=496;
    // cout << min_cubes_req(n);
    
//     int n = 10; 
// 	int dp[n][4]; 

// 	for (int i = 0; i < n; i++) 
// 		for (int j = 0; j < 4; j++) 
// 			dp[i][j] = -1; 

// 	for (int i = 0; i < n; i++) { 

// 		// Base condition: 
// 		// 2^(i+1) because of 0 indexing 
// 		dp[i][3] = (1 << (i + 1)); 
// 	} 

    // int arr[] = { 6, 7, 1, 3, 8, 2, 4 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // int k = 2; 
    // cout << subsequence_not_less_thank(arr, 0, n ,k); 
    
    //  int R = 40, B = 10, W = 4; 
    //  int arr[]={-1,0,1,2,4,3,6};
    //  cout << ways_to_score_r(40,10,4,arr);
    
    
    // int arr[]={40, 10, 20, 70, 80, 10};
    // int k=4;
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << min_cost_path_jumps_lessthank(arr,0,n,k);
    
    // int a[] = { 6, 8, 2, 7, 4, 2, 7 }; 
    // int b[] = { 7, 8, 5, 8, 6, 3, 5 }; 
    // int c[] = { 8, 3, 2, 6, 8, 4, 1 }; 
    // int n = sizeof(a) / sizeof(a[0]); 
    // cout << max_sum_3arrays_nocons(a,b,c,0,0,n);
    
    // string s = "abcddcba"; 
    // int n = s.length(); 
    // cout << min_steps_delete_elems(0,n-1,s);
    
    // int arr[] = { 1, 2, 3, 4 };
    // int k = 2;
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << min_prod_distance_k(arr,0,n,k);
	return 0;
}