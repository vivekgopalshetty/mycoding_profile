//https://www.geeksforgeeks.org/medium/dynamic-programming/9/
//recustion

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999


int painting_fence(int n,int k)
{
    long dp[n + 1]; 
    memset(dp, 0, sizeof(dp)); 
    long long mod = 1000000007; 
  
    dp[1] = k; 
    dp[2] = k * k; 
  
    for (int i = 3; i <= n; i++) { 
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod; 
    } 
  
    return dp[n]; 
}

double max_weight_val_ratio(int w[],int v[],int top,int down,int n,int k)
{
    if(n==0)
    {
        return INT_MIN;
    }
    
    if(k==(top/down))
    {
        return (top);
    }
    
    return max(max_weight_val_ratio(w,v,top+w[n-1],down+v[n-1],n-1,k),
            max_weight_val_ratio(w,v,top,down,n-1,k));
}

int main() {
	
	int w[] = {4, 10, 9 ,10,15,20};
    int v[] = {2, 4, 6 , 4, 6, 2};
	int n=6;
	int k=4;
	cout << max(max_weight_val_ratio(w,v,w[n-1],v[n-1],n-1,k),
	(max_weight_val_ratio(w,v,w[n-2],v[n-2],n-2,k)));
	return 0;
}