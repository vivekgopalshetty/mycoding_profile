//https://www.geeksforgeeks.org/medium/dynamic-programming/
//recursion

#include<bits/stdc++.h>
using namespace std;

int max_sum_divisible_byk(int arr[],int n,int k,int sum)
{
    if(n<0)
    {
        return 0;
    }
    
    if(n==0)
    {
        if(sum%k==0)
        {
            return sum;
        }
        
        return 0;
    }
    
    return max(max_sum_divisible_byk(arr,n-1,k,sum+arr[n-1]),
                max_sum_divisible_byk(arr,n-2,k,sum+arr[n-1]));
}

int max_multiples(int arr[],int n)
{
    int maxi=0;
    for(int i=1;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<i;j++)
        {
            if(arr[j]%arr[i]==0)
            {
                cnt++;
            }
        }
        
        maxi=max(maxi,cnt);
    }
    
    return maxi;
}

int min_steps_endof_s(string s,int start,int n,int k)
{
    if(s[start]=='0')
    {
        return INT_MAX;
    }
    
    if(start>n)
    {
        return INT_MAX;
    }
    
    if(start==n-1 && s[n-1]=='1')
    {
        return 0;
    }
    
    return 1+min(min_steps_endof_s(s,start+1,n,k),min(min_steps_endof_s(s,start+2,n,k),
    min_steps_endof_s(s,start+k,n,k)));
}

int dp_cnt;

void binary_string_with_lesslen3_substring(int n,int k,string prefix)
{
    if(k==n)
    {   
        dp_cnt++;
        cout << prefix << endl;  
        return;
    }
    
    if(k>1)
    {
        int st=prefix.length();
        if(prefix[st-2]=='1' && prefix[st-1]=='1')
        {
            return binary_string_with_lesslen3_substring(n,k+1,prefix+'0');
        }
    }
     
    binary_string_with_lesslen3_substring(n,k+1,prefix+'0');
    binary_string_with_lesslen3_substring(n,k+1,prefix+'1');
     
}

int max_value_by_operations(int arr[],int start,int n,int sum,int flag)
{
    if(start==n)
    {
        return sum;
    }
    
    int c1=0;
    if(flag==1)
    {
        c1=max_value_by_operations(arr,start+1,n,sum+arr[start],0);
    }
    else
    {
        return max(max_value_by_operations(arr,start+1,n,sum+arr[start],0),
        max_value_by_operations(arr,start+1,n,sum-arr[start-1]+
        (arr[start]*arr[start-1]),1));
    }
}

int remove_min_to_cut_byk(int arr[],int start,int end,int k)
{
    if(k<0)
    {
        return 0;
    }
    
    if(start>end)
    {
        return 0;
    }
    
    return 1+min(remove_min_to_cut_byk(arr,start+1,end,k-arr[start]),
            remove_min_to_cut_byk(arr,start,end-1,k-arr[end]));
}

int min_cost_to_merge_all(int arr[],int i,int j,int n)
{
    if(i==j)
    {
        return 0;
    }
    
    int sum=0;
    for(int k=i;k<=j;k++)
    {
        sum+=arr[k];
    }
    
    int x=INT_MAX;
    for(int k=i+1;i<=j;k++)
    {
        x=min(x,sum+min_cost_to_merge_all(arr,i,k-1,n)
        +min_cost_to_merge_all(arr,k,j,n));
    }
    
    return x;
}


int countSubSeq(string str, int len) 
{ 
     
    int ans = 0; 
    int mul = 1; 
  
    for (int i = 0; i < len; i++) { 
        if (str[i] == '0') 
            ans += mul;
        mul *= 2; 
    } 
  
    return ans; 
} 

//segmentation fault check
// int dp_cost[10001][10001];
// int min_cost_partition_k(string& s,int k,int cost,int start,int& n)
// {
//     if(dp_cost[start][k]!=-1)
//     {
//         return dp_cost[start][k];
//     }
    
//     if(k==1)
//     {
//         int count_0s=0;
//         for(int j=start;j<n;j++)
//         {
//             if(s[j]=='0')
//             {
//                 count_0s++;
//             }
//         }
        
//         dp_cost[start][k]=cost+(n-start-count_0s)*(count_0s);
//         return dp_cost[start][k];
//     }
    
//     int count_0s=0;
//     int curr_cost=INT_MAX;
//     for(int j=start;j<n-k+1;j++)
//     {
//         if(s[j]=='0')
//         {
//             count_0s++;
//         }
//         int current_length=j-start+1;
        
//         int part_cost=(count_0s)*(current_length-count_0s);
//         part_cost+=min_cost_partition_k(s,k-1,0,j+1,n);
        
//         curr_cost=min(curr_cost,part_cost);
//     }
    
//     dp_cost[start][k]=cost+curr_cost;
//     return dp_cost[start][k];
// }

// int max_sum_segment(int arr[][MAX],int prev,int start,int n,int m)
// {
    
// }

int countWays(int n) 
{ 
    vector<int> a; 
    int i = 1; 
    while (i <= n) 
        a.push_back(i++); 
    int ways = 0; 
    do { 
        bool flag = (a[0] == 1); 

        for (int i = 1; i < n; i++) { 
  
            if (abs(a[i] - a[i - 1]) > 2) 
                flag = 0; 
        } 
  
        if (flag) 
            ways++; 
  
    } while (next_permutation(a.begin(), a.end())); 
  
    return ways; 
} 

int max_sum_subarray(int arr[],int n)
{
    int max_so_far=arr[0];
    int curr_max=arr[0];
    
    for(int i=1;i<n;i++)
    {
        curr_max=max(arr[i],arr[i]+curr_max);
        max_so_far=max(max_so_far,curr_max);
    }
    
    return max_so_far;
}

int max_sum_subarray_even_length(int arr[],int n)
{
   int dp[n+1];
   dp[n-1]=0;
   dp[n-2]=arr[n-1]+arr[n-2];
   
   for(int i=n-3;i>=0;i--)
   {
       dp[i]=max(arr[i]+arr[i+1],arr[i]+arr[i+1]+dp[i+2]);
   }
   
   return *max_element(dp,dp+n);
}

int max_sum_subarray_sumis_even(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    
    if(sum%2==0)
    {
        return n;
    }
    
    int len=0;    
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==1)
        {
            len=max(len,max(n-i-1,i));
        }
    }
    
    return len;
}



// const int N = 1e5 + 5; 
// int dp_n[N];
// int m;
// int convert_n_to_m(int n)
// {
//     if(dp_n[n]!=-1)
//     {
//         return dp_n[n];
//     }
    
//     if (n <= 0 || n >= 2e4) { 
//         return 1e9; 
//     } 
    
//     if(n==m)
//     {
//         return 0;
//     }
    
//     dp_n[n]=1+min(convert_n_to_m(n*2),
//             convert_n_to_m(n-1));
//     return dp_n[n];
// }

int count_path_array(int arr[],int n,int start)
{
    if(start>n)
    {
        return 0;
    }
    
    if(start==n-1)
    {
        return 1;
    }
    
    int sum=0;
    for(int i=start+1;i<=start+arr[start];i++)
    {
        sum+=count_path_array(arr,n,i);
    }
    
    return sum;
}

int main()
{
    // int arr[] = { 43, 1, 17, 26, 15 }; 
    // int k = 16; 
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << max_sum_divisible_byk(arr,n,k,0); 
    
    // int arr[] = { 8, 1, 28, 4, 2, 6, 7 }; 
    // int n = sizeof(arr) / sizeof(int); 
    // cout << max_multiples(arr,n);
    
    // string str = "10101010101111010101";
    // int k = 4;
    // cout << min_steps_endof_s(str,0,str.size(),k);
    
    // int n = 8; 
    // string s="";
    // dp_cnt=0;
    // binary_string_with_lesslen3_substring(n,0,s);
    // cout << dp_cnt;
    
    // int arr[] = { 5 ,-3 ,-5, 2, 3, 9, 4 }; 
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << max_value_by_operations(arr, 0,n, 0 ,1); 
    
    // int arr[] = {1, 11, 5, 5}; 
    // int n = sizeof(arr) / sizeof(int); 
    // int k = 11; 
    // cout << remove_min_to_cut_byk(arr, 0, n, k); 
    
    // int arr[] = { 1, 3, 7 }; 
    // int n = sizeof(arr) / sizeof(int); 
    // cout << min_cost_to_merge_all(arr,n);
    
    // cout << countWays(10);
    // string s = "110101"; 
    // int n = s.length(); 
    // int k = 3; 
    // memset(dp_cost,-1,sizeof(dp_cost));
    // cout << min_cost_partition_k(s,k,0,0,n);
    
    // int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3}; 
    // int n = sizeof(a)/sizeof(a[0]); 
    // cout << max_sum_subarray(a, n); 
    
    // int arr[] = { 8, 9, -8, 9, 10 }; 
    // int n = sizeof(arr) / sizeof(int); 
    // cout << max_sum_subarray_even_length(arr, n);
    
    // int a[] = { 1, 2, 3, 2 }; 
    // int n = sizeof(a) / sizeof(a[0]); 
    // cout << max_sum_subarray_sumis_even(a, n) ;
    
    // int arr[]={2, 3, 1, 1, 2};
    // int n = sizeof(arr) / sizeof(int);
    // cout << count_path_array(arr,n,0);
      
    // m=6;
    // cout << convert_n_to_m(4);
    return 0;
}