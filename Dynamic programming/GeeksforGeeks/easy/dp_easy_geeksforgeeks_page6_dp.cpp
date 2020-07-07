//https://www.geeksforgeeks.org/easy/dynamic-programming/6/
//dynamic-programming

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define NUM_STATION 4
#define INF 99999  

//wrong
int count_given_score(int n)
{
    int dp[n+1];
    
    dp[0]=0;dp[1]=0;dp[2]=0;
    dp[3]=1;dp[4]=0;
    dp[5]=1;dp[6]=1;dp[7]=0;dp[8]=0;
    dp[10]=2;dp[9]=1;
    
    for(int i=11;i<=n;i++)
    {
        dp[i]=dp[i-3]+dp[i-5]+dp[i-10];
    }
    
    cout << dp[n];
}

//logic almost correct but for big numbers problem
unsigned long int ways_to_nth_stairs(int n)
{
    long int dp[n+1];
    
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int count_number_of_binary_strings(int n)
{
    int zeros[n+1];
    int ones[n+1];
    
    zeros[0]=1;
    ones[0]=1;
    
    for(int i=1;i<n;i++)
    {
        zeros[i]=zeros[i-1]+ones[i-1];
        ones[i]=zeros[i-1];
    }
    
    return zeros[n-1]+ones[n-1];
}

int catalan_sequence(int n)
{
    int dp[n];
    
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<n;i++)
    {
        dp[i]=0;
        for(int j=0;j<i;j++)
        {
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    
    return dp[n-1];
}

int numberOfPaths(int m, int n) 
{ 
    int count[m][n]; 
  
    for (int i = 0; i < m; i++) 
        count[i][0] = 1; 
  
    for (int j = 0; j < n; j++) 
        count[0][j] = 1; 
  
    
    for (int i = 1; i < m; i++) { 
        for (int j = 1; j < n; j++)
            count[i][j] = count[i - 1][j] + count[i][j - 1]; 
    } 
    return count[m - 1][n - 1]; 
} 

int assembly_line(int a[][4],int t[][4],
                int e[],int x[],int n)
{
    int t1[n],t2[n];
    
    t1[0]=e[0]+a[0][0];
    t2[0]=e[1]+a[1][0];
    
    for(int i=1;i<n;i++)
    {
        t1[i]=min(a[0][i]+t1[i-1],a[i][0]+t1[i-1]+t[1][i]);
        t2[i]=min(a[1][i]+t2[i-1],a[i][0]+t2[i-1]+t[0][i]);
    }
    
    return min(x[0]+t1[n-1],x[1]+t2[n-1]);
}

int longest_common_substring(string s1,string s2)
{
    int n=s1.length();
    int m=s2.length();
    
    int dp[n+1][m+1];
    int result=0;
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                result=max(dp[i][j],result);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    
    return result;
}

void primeFactors(int n)  
{  
    while (n % 2 == 0)  
    {  
        cout << 2 << " ";  
        n = n/2;  
    }  

    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            cout << i << " ";  
            n = n/i;  
        }  
    }  
  
    if (n > 2)  
        cout << n << " ";  
}  

int binomialCoeff(int n, int k)  
{  
    int res = 1;  
 
    if ( k > n - k )  
        k = n - k;  
 
    for (int i = 0; i < k; ++i)  
    {  
        res *= (n - i);  
        res /= (i + 1);  
    }  
  
    return res;  
}  


void floyd_warshall(int graph[][MAX],int v)
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            for(int k=0;k<v;k++)
            {
                if(graph[i][k]+graph[k][j]<graph[i][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
    
     for (int i = 0; i < v; i++)  
    {  
        for (int j = 0; j < v; j++)  
        {  
            if (graph[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<graph[i][j]<<"     ";  
        }  
        cout<<endl;
    }
}

int minJumps(int arr[], int n) 
{ 
    // jumps[n-1] will hold the result 
    int* jumps = new int[n]; 
    int i, j; 
  
    if (n == 0 || arr[0] == 0) 
        return INT_MAX; 
  
    jumps[0] = 0; 
  
    // Find the minimum number of jumps to reach arr[i] 
    // from arr[0], and assign this value to jumps[i] 
    for (i = 1; i < n; i++) { 
        jumps[i] = INT_MAX; 
        for (j = 0; j < i; j++) { 
            if (i <= j + arr[j] && jumps[j] != INT_MAX) { 
                jumps[i] = min(jumps[i], jumps[j] + 1); 
                break; 
            } 
        } 
    } 
    return jumps[n - 1]; 
} 

int min_cost_path(int arr[][MAX],int n,int m)
{
    int dp[n][m];
    
    dp[0][0]=arr[0][0];
    
    for(int i=1;i<n;i++)
    {
        dp[i][0]=arr[i][0]+dp[i-1][0];
    }
    
    for(int j=1;j<m;j++)
    {
        dp[0][j]=arr[0][j]+dp[0][j-1];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j]=arr[i][j]+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    return dp[n-1][m-1];
}


int main()
{
    // cout << count_given_score(20);
    
    // cout << ways_to_nth_stairs(84);
    
    // cout << count_number_of_binary_strings(4);
    
    // for (int i=1; i<10; i++) 
    //     cout << catalan_sequence(i) << " ";
    
     // cout << numberOfPaths(3,2);
     
    // int a[][4] = {{4, 5, 3, 2},  
    //             {2, 10, 1, 4}};  
    // int t[][4] = {{0, 7, 4, 5},  
    //             {0, 9, 2, 8}};  
    // int e[] = {10, 12}, x[] = {18, 7};
    // cout << assembly_line(a,t,e,x,4);
    
    // string X = "abcdxyz";  
    // string Y = "xyzabcd"; 
    // cout<<longest_common_substring(X,Y); 
    
    // int arr[MAX][MAX] = { {1, 2, 3}, 
    //                   {4, 8, 2}, 
    //                   {1, 5, 3} }; 
    // int n=3,m=3;
    // cout << min_cost_path(arr,n,m);
}