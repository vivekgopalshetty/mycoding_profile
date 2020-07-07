//https://www.geeksforgeeks.org/medium/dynamic-programming/
//dynamic-programming

#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int dp_sum_k[1000][1000];
int max_sum_divisibility_k(int arr[],int n,int k,int start,int sum)
{
    if(dp_sum_k[start][sum]!=-1)
    {
        return dp_sum_k[start][sum];
    }
    
    if(start>n)
    {
        return 0;
    }
    
    if(start==n)
    {
        if((sum)%k==0)
        {
            return sum;
        }
        
        return 0;
    }
    
    
    dp_sum_k[start][sum]=max(max_sum_divisibility_k(arr,n,k,start+1,sum+arr[start]),
            max(max_sum_divisibility_k(arr,n,k,start+1,sum),
             max_sum_divisibility_k(arr,n,k,start+2,sum+arr[start])));
             
    return dp_sum_k[start][sum];
}

//another_solution check again
int max_sum_divisibility_k_v2(int arr[],int n,int k,int start,int sum)
{
    
    if(start==n)
    {
        return 0;
    }
    
     if(dp_sum_k[start][sum]!=-1)
    {
        return dp_sum_k[start][sum];
    }
    
    
    int ans=0;
    if((sum+max_sum_divisibility_k_v2(arr,n,k,start+1,sum)%k)==0)
    {
        ans=max_sum_divisibility_k_v2(arr,n,k,start+1,sum);
    }

    if((sum+arr[start]+max_sum_divisibility_k_v2(arr,n,k,start+1,(sum+arr[start])%k))%k==0)
    {
        ans=max(ans,arr[start]+max_sum_divisibility_k_v2(arr,n,k,start+1,(sum+arr[start])%k));
    }
    
    dp_sum_k[start][sum]=ans;
    return dp_sum_k[start][sum];
}

int dp_divisors[10001];
void generate_divisors(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            dp_divisors[i]++;
        }
    }
}

int max_multiples(int arr[],int n)
{
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,dp_divisors[arr[i]]);
        generate_divisors(arr[i]);
    }
    
    return maxi;
}

int min_steps_endof_s(string s,int n,int k)
{
    int dp[n+1];
    if(s[0]!='1' || s[n-1]!='1')
    {
        return 0;
    }
    
    dp[0]=0;
    dp[1]=s[1]==1 ? 1 :0;
    
    int ans;
    for(int i=2;i<n;i++)
    {
        ans=INT_MAX;
        if((i-k)>=0 && s[i-k]=='1')
        {
            ans=1+dp[i-k];
        }
        
        if((i-2)>=0 && s[i-2]=='1')
        {
            ans=min(ans,1+dp[i-2]);
        }
        
        if((i-1)>=0 && s[i-1]=='1')
        {
            ans=min(ans,1+dp[i-1]);
        }
        
        dp[i]=ans;
    }
    
    return dp[n-1];
}

int binary_string_with_lesslen3_substring(int n)
{
    int dp[3][n+2];
    dp[0][2]=2;
    dp[1][2]=1;
    dp[2][2]=1;
    
    
    for(int i=3;i<=n+1;i++)
    {
        dp[2][i]=dp[1][i-1];
        dp[1][i]=dp[0][i-1];
        dp[0][i]=dp[0][i-1]+dp[1][i-1]+dp[2][i-1];
        cout <<dp[0][i] << " " << dp[1][i] << " " <<dp[2][i]<< endl;
    }
    
    return dp[0][n+1];
}

int max_value_by_operations(int arr[],int n)
{
    int dp[n+1][2];
   
    dp[1][0]=arr[0]+arr[1];
    dp[1][1]=arr[0]*arr[1];
    
    for(int i=2;i<n;i++)
    {
        dp[i][0]=arr[i]+max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=dp[i-1][0]-arr[i-1]+(arr[i]*arr[i-1]);
    }
    
    return max(dp[n-1][0],dp[n-1][1]);
}

int longest_subarray_with_sum_atleatk(int arr[],int n,int k)
{
    int sum=0;
    int cnt=0;
    int maxcnt=0;
    
    for(int i=0;i<n;i++)
    {
        if((sum+arr[i])<=k)
        {
            sum=sum+arr[i];
            cnt++;
        }
        else if(sum!=0)
        {
            sum=sum-arr[i-cnt]+arr[i];
        }
        
        maxcnt=(maxcnt,cnt);
    }
    
    return maxcnt;
}

int remove_min_to_cut_byk(int arr[],int n,int k)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    
    sum=sum-k;
    int l=longest_subarray_with_sum_atleatk(arr,n,k);
    
    return n-l;
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

// int max_sum_segment(int arr[][MAX],int prev,int start,int n,int m)
// {
    
// }

int min_halls_required(vector<pair<int,int> > v)
{
   // sort(v.begin(),v.end());
    
    //int end=v[0].second;
    int cnt=1;
    // for(int i=1;i<v.size();i++)
    // {
    //     if(v[i-1].second<v[i].first)
    //     {
    //         cnt++;
    //     }
    // }
    
    return v.size()-cnt;
}

int sum_of_productsubarray_ksegments(int arr[],int n,int k)
{
    int dp[n + 1][n + 1] = { 0 }; 
    int cur_sum = 0; 
  
    for (int i = 1; i <= n; i++) { 
        dp[1][i] = arr[i - 1]; 
        cur_sum += arr[i - 1]; 
    } 
    
    for(int i=2;i<=k;i++)
    {
        int temp_sum=0;
        for(int j=1;j<=n;j++)
        {
            cur_sum-=dp[i-1][j];
            dp[i][j]=arr[j-1]*cur_sum;
            temp_sum+=dp[i][j];
        }
        cur_sum=temp_sum;
    }
    
    return cur_sum;
}

int divide_array_intok_cond(int arr[],int n,int k)
{
    int dp[500][500]={0};
    
    k=k-1;
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j]=INT_MAX;
            int max=-1;
            int sum=0;
            for (int l = i; l < n; l++) 
            {
                max_ = max(max_, arr[l]); 
                sum += arr[l]; 
 
                int diff = (l - i + 1) * max_ - sum; 
  
                if (j > 0) 
                    dp[i][j] 
                        = min(dp[i][j], 
                              diff + dp[l + 1][j - 1]); 
                else
                    dp[i][j] = diff; 
            } 
        }
    }
}

int max_sum_segments(int arr[][MAX],int n,int m)
{
    int dp[n + 1][3] = { 0 }; 
  
    for (int i = 0; i < n; i++) { 
        int m1 = 0, m2 = 0, m3 = 0; 
  
        for (int j = 0; j < m; j++) { 
            if ((j / (m / 3)) == 0) { 
                m1 = max(m1, arr[i][j]); 
            } 
 
            else if ((j / (m / 3)) == 1) { 
                m2 = max(m2, arr[i][j]); 
            } 
 
            else if ((j / (m / 3)) == 2) { 
                m3 = max(m3, arr[i][j]); 
            } 
        } 
  
        dp[i + 1][0] = max(dp[i][1], dp[i][2]) + m1; 
        dp[i + 1][1] = max(dp[i][0], dp[i][2]) + m2; 
        dp[i + 1][2] = max(dp[i][1], dp[i][0]) + m3; 
    } 
  
    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << '\n'; 
    return 0;
}


int lis_using_lcs(int arr[],int n)
{
    int arr2[n];
    for(int i=0;i<n;i++)
    {
        arr2[i]=arr[i];
    }
    sort(arr2,arr2+n);
    int dp[n+1][n+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(arr[i-1]==arr2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return dp[n][n];
}

int count_ways(int n)
{
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-3]+dp[i-1]+1;
    }
    
    return dp[n];
}

// const int mod = 1e9 + 7; 
// int count_path_array(int arr[],int n)
// {
//     int dp[n+1];
//     dp[n-1]=1;
    
//     for(int i=n-2;i>=0;i--)
//     {
//         dp[i]=0;
//         for(int j=1;(j<=arr[i] && (j+i)<n);j++)
//         {
//             dp[i]+=dp[i+j];
//             dp[i]=dp[i]%mod;
//         }
//     }
    
//     return dp[0]%mod;
// }

int main()
{
    // int arr[] = { 43, 1, 17, 26, 15, 1, 17, 26, 15 ,45 ,96,78}; 
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int k = 16;
    // memset(dp_sum_k,-1,sizeof(dp_sum_k));
    // cout << max_sum_divisibility_k(arr,n,k,0,0);
    
    // int arr[] = { 43, 1, 17, 26, 15, 1, 17, 26, 15 ,45 ,96,78}; 
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int k = 16;
    // memset(dp_sum_k,-1,sizeof(dp_sum_k));
    // cout << max_sum_divisibility_k_v2(arr,n,k,0,0);
    
    // int arr[] = { 8, 1, 28, 4, 2, 6, 7 }; 
    // int n = sizeof(arr) / sizeof(int);
    // memset(dp_divisors,0,sizeof(dp_divisors));
    // cout << max_multiples(arr,n);
    
    // string str = "1100000100111";
    // int k = 6;
    // cout << min_steps_endof_s(str,str.size(),k);
    
    // int n = 4; 
    // cout << binary_string_with_lesslen3_substring(n); 
  
    // vector<pair<int,int> >lectures;
    // lectures.push_back({0,5});
    // lectures.push_back({1,2});
    // lectures.push_back({1,10});
    // cout << min_halls_required(lectures);
    
    // int arr[] = { 5, -1, -5, -3, 2, 9, -4 }; 
    // int n = sizeof(arr) / sizeof(int);
    // cout << max_value_by_operations(arr,n);
    
    // cout << count_ways(10);
    
    int arr[]={ 12, 34, 1, 5, 40, 80 };
    int n = sizeof(arr) / sizeof(int);
    cout << lis_using_lcs(arr,n);
    
    
    // int arr[]={ 5, 3, 1, 4, 3 };
    // int n = sizeof(arr) / sizeof(int);
    // cout << count_path_array(arr,n);
    return 0;
}