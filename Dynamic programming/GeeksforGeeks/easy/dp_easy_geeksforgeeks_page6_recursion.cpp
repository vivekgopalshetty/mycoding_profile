//https://www.geeksforgeeks.org/easy/dynamic-programming/6/
//recursion

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define NUM_STATION 4
#define INF 99999  

//considering (5,5,10) and (5,10,5) differently
int count_given_score(int n)
{
    if(n<3)
    {
        return 0;
    }
    
    if(n==3 || n==5)
    {
        return 1;
    }
    
    if(n==10)
    {
        return 2;
    }
    
    return count_given_score(n-10)+count_given_score(n-5)+count_given_score(n-3);
    
}

//unique (5,5,10) and (5,10,5) are same have to complete 
int count_given_score_unq(int n)
{
    return 0;
}

int  ways_to_reach_nstairs(int n)
{
    if(n==0)
    {
        return 1;
    }
    
    if(n==1)
    {
        return 1;
    }
    
    if(n==2)
    {
        return 2;
    }
    
    return ways_to_reach_nstairs(n-1)+ways_to_reach_nstairs(n-2);
}

int count_number_of_binary_strings(int n,int k,string prefix,int prev)
{
    if(k==n)
    {
        cout << prefix << " ";
        return 1;
    }
    
    if(prev==0)
    {
        return count_number_of_binary_strings(n,k+1,prefix+'0',0)+
                count_number_of_binary_strings(n,k+1,prefix+'1',1);
    }
    else
    {
        return count_number_of_binary_strings(n,k+1,prefix+'0',0);
    }
    
}

//very useful check uses link- geeksforgeeks.org/program-nth-catalan-number/
int catalan_sequence(int n)
{
    if(n<=1)
    {
        return 1;
    }
    
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=catalan_sequence(i)*catalan_sequence(n-i-1);
    }
    
    return sum;
}

int numberOfPaths(int m, int n) 
{ 
    if (m == 1 || n == 1) 
        return 1; 
  
    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1); 
} 

int assembly_line(int a[][NUM_STATION],int t[][ NUM_STATION],
                int e[],int x[],int n,int start,bool station)
{
    if(start==-1)
    {
        return min(e[0]+assembly_line(a,t,e,x,n,start+1,0),
               e[1]+assembly_line(a,t,e,x,n,start+1,1) );
    }
    
    if(start>=n)
    {
        if(!station)
        {
            return x[0];
        }
        else
        {
            return x[1];
        }
    }
    
    return min(a[(int)station][start]+assembly_line(a,t,e,x,n,start+1,station),
            t[(int)!station][start]+a[(int)station][start]
            +assembly_line(t,a,e,x,n,start+1,!station));
}

int longest_common_substring(string s1,string s2,int n,int m)
{
    
    if(n==0 || m==0)
    {
        return 0;
    }
    
    int c1=0;
    if(s1[n-1]==s2[m-1])
    {
        c1=1+longest_common_substring(s1,s2,n-1,m-1);
    }
    
    return max(c1,max(longest_common_substring(s1,s2,n-1,m),
                longest_common_substring(s1,s2,n,m-1)));
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

void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
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

int num_jumps(int arr[],int n)
{
    if(n==1)
    {
        return 0;
    }
    
    int res=INT_MAX;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]+i>=n-1)
        {
            int sub_res = num_jumps(arr, i + 1); 
            if (sub_res != INT_MAX) 
                res = min(res, sub_res + 1);
        }
    }
    
    return res;
}

int min_cost_path(int arr[][MAX],int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return INT_MAX;    
    }
    
    if(x==n-1 && y==m-1)
    {
        return arr[x][y];
    }
    
    return arr[x][y]+min(min_cost_path(arr,x+1,y,n,m),
                    min(min_cost_path(arr,x,y+1,n,m),
                min_cost_path(arr,x+1,y+1,n,m)));
    
}


int main()
{
   // cout << count_given_score(20);
    
   // cout << ways_to_reach_nstairs(84);
   
   //   string s="";
   //   cout << count_number_of_binary_strings(4,0,s,0);
   
   //   for (int i=0; i<10; i++) 
   //         cout << catalan_sequence(i) << " "; 
   
   // cout << numberOfPaths(3,2);
   
    // int a[][NUM_STATION] = {{4, 5, 3, 2},  
    //                         {2, 10, 1, 4}};  
    // int t[][NUM_STATION] = {{0, 7, 4, 5},  
    //                         {0, 9, 2, 8}};  
    // int e[] = {10, 12}, x[] = {18, 7};
    // cout << assembly_line(a,t,e,x,-1,4,0);
    
    // int n,m; 
    // string X = "abcdxyz";  
    // string Y = "xyzabcd"; 
    // n=X.size(); 
    // m=Y.size(); 
    // cout<<longest_common_substring(X,Y,n,m); 
    
    // int graph[MAX][MAX] = { {0, 5, INF, 10},  
    //                     {INF, 0, 3, INF},  
    //                     {INF, INF, 0, 1},  
    //                     {INF, INF, INF, 0}  
    //                 };  
  
    // floyd_warshall(graph,4);

    int arr[] = { 1, 3, 6, 1, 0, 9 }; 
    int size = sizeof(arr) / sizeof(int); 
    cout << "Minimum number of jumps to reach"
         << " end is " << num_jumps(arr, size ); 
    
    // int arr[MAX][MAX] = { {1, 2, 3}, 
    //                   {4, 8, 2}, 
    //                   {1, 5, 3} }; 
    // int n=3,m=3;
    // cout << min_cost_path(arr,0,0,n,m);
    
}