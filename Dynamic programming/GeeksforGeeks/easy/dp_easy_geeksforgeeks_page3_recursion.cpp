//https://www.geeksforgeeks.org/easy/dynamic-programming/3/
//recursion

#include<bits/stdc++.h>
using namespace std;

#define MAX 50

int count_sum134(int n)
{
    if(n<0)
    {
        return 0;
    }
    
    if(n==0)
    {
        return 1;
    }
    
    return count_sum134(n-1)+count_sum134(n-3)+count_sum134(n-4);
    
}

int no_of_monotones(int n,int k)
{
    if(k==0)
    {
        return 1;
    }
    
    int sum=0;
    for(int i=n+1;i<10;i++)
    {
        sum+=no_of_monotones(i,k-1);
    }
    
    return sum;
}


//kadenes algorithm 
int maximum_subarray_sum(int arr[],int n)
{
    int max_so_far=INT_MIN;
    int max_ending_here=0;
    
    for(int i=0;i<n;i++)
    {
        max_ending_here=max_ending_here+arr[i];
        if(max_ending_here>max_so_far)
        {
            max_so_far=max_ending_here;
        }
        
        if(max_ending_here<0)
        {
            max_ending_here=0;
        }
    }
    
    return max_so_far;
}

//now above problem with prefix sum
int maximum_subarray_sum_usingprefix(int arr[],int n)
{
   
    int min_prefix_sum = 0; 
    int res = numeric_limits<int>::min(); 
  
    int prefix_sum[n]; 
    prefix_sum[0] = arr[0]; 
    for (int i = 1; i < n; i++)  
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];         
  
    for (int i = 0; i < n; i++) { 
        res = max(res, prefix_sum[i] -  
                       min_prefix_sum); 
        min_prefix_sum = min(min_prefix_sum,  
                             prefix_sum[i]); 
    } 
      
    return res;
}

bool check_path_available(int mat[][5],int x,int y,int m,int n)
{
    if(x==m-1 && y==n-1)
    {
        return true;    
    }
    
    if(x<0 || y<0 || x>m-1 || y>n-1)
    {
        return false;
    }
    
   if(mat[x+1][y]==0)
   {
       return check_path_available(mat,x+1,y,m,n);
   }
    
    if(mat[x][y+1]==0)
   {
       return check_path_available(mat,x,y+1,m,n);
   }
   
    if(mat[x-1][y]==0)
   {
       return check_path_available(mat,x-1,y,m,n);
   }
   
    if(mat[x][y-1]==0)
   {
       return check_path_available(mat,x,y-1,m,n);
   }
   
   return false;
}


int product_increasing_subsequence(int arr[],int start,int prev,int end,int product)
{
    if(start>=end)
    {
        return product;
    }
    
    int c1=0;
    if(arr[start]>prev)
    {
        c1=product_increasing_subsequence(arr,start+1,arr[start],end,product*arr[start]);
    }
    
    return max(c1,product_increasing_subsequence(arr,start+1,prev,end,product));
}

int hosaya_traingle(int n,int m)
{
   if ((n == 0 && m == 0) || 
        (n == 1 && m == 0) ||  
        (n == 1 && m == 1) || 
        (n == 2 && m == 1)) 
        return 1; 
  
    // Recursive step 
    if (n > m) 
        return hosaya_traingle(n - 1, m)  
               + hosaya_traingle(n - 2, m); 
  
    else if (m == n) 
        return hosaya_traingle(n - 1, m - 1)  
               + hosaya_traingle(n - 2, m - 2); 
  
    else
        return 0; 
    
}

void print_hosaya(int n)
{
   for (int i = 0; i < n; i++) { 
        for (int j = 0; j <= i; j++)  
            cout << hosaya_traingle(i, j) << " ";      
  
        cout << endl; 
    } 
}

int eulerian_number(int n,int m)
{
    if(m==0)
    {
        return 1;
    }
    
    if(m>=n || n==0)
    {
        return 0;
    }
    
    return (n-m)*eulerian_number(n-1,m-1)+(m+1)*eulerian_number(n-1,m); 
}

//method 1
int max_difference_onesandzeros_v1(string arr,int start,int end,int zeros,int ones)
{
    if(start>end)
    {
        return abs(ones-zeros);
    }
    
   if(arr[start]==0 && arr[end]==0)
   {
       return max(max_difference_onesandzeros_v1(arr,start+1,end,zeros-1,ones),
            max_difference_onesandzeros_v1(arr,start,end-1,zeros-1,ones));
   }
   else if(arr[start]==1 && arr[end]==0)
   {
       return max(max_difference_onesandzeros_v1(arr,start+1,end,zeros,ones-1),
            max_difference_onesandzeros_v1(arr,start,end-1,zeros-1,ones));
   }
   else if(arr[start]==0 && arr[end]==1)
   {
       return max(max_difference_onesandzeros_v1(arr,start+1,end,zeros-1,ones),
            max_difference_onesandzeros_v1(arr,start,end-1,zeros,ones-1));
   }
   else if(arr[start]==1 && arr[end]==1)
   {
       return max(max_difference_onesandzeros_v1(arr,start+1,end,zeros,ones-1),
            max_difference_onesandzeros_v1(arr,start,end-1,zeros,ones-1));
   }
    
}

int max_difference_onesandzeros(string s,int n)
{
    int dp[n+1];
    
    int max_so_far=INT_MIN;
    int max_ending_here=0;
 
    for(int i=0;i<n;i++)
    {
        max_ending_here=max_ending_here+(int)s[i];
        if(max_ending_here>max_so_far)
        {
            max_so_far=max_ending_here;
        }
        
        if(max_ending_here<0)
        {
         
            max_ending_here=0;
        }
    }
    
    return 0;
}

int smallestSumSubarr(int arr[], int n) 
{ 
    int min_ending_here = INT_MAX; 
    int min_so_far = INT_MAX; 
    
    for (int i=0; i<n; i++) 
    { 
        if (min_ending_here > 0) 
            min_ending_here = arr[i]; 
        else
            min_ending_here += arr[i]; 
          
        min_so_far = min(min_so_far, min_ending_here);             
    } 
    return min_so_far; 
} 
  
int unique_paths(int arr[3][4],int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return 0;
    }
    
    if(x==n-1 && y==m-1)
    {
        return 1;    
    }
    
    if(arr[x][y]==1)
    {
        return 0;
    }
    
    return unique_paths(arr,x+1,y,n,m)+unique_paths(arr,x,y+1,n,m);
}

int max_array_end_remove(int arr[],int start,int end,int k)
{
    if(start>end)
    {
        return 0;
    }
    
    return max(arr[start]*k+max_array_end_remove(arr,start+1,end,k+1)
    ,arr[end]*k+max_array_end_remove(arr,start,end-1,k+1));
}

int numberOfWays(int x) 
{ 
    if (x==0 || x==1)      
        return 1; 

    else 
        return numberOfWays(x-1) +  
               (x-1)*numberOfWays(x-2); 
} 

int longest_increasing_path(int arr[][MAX],int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return INT_MIN;
    }
    
    if(x==n-1 && y==m-1)
    {
        return 1;
    }
    
    int c1=0;
    if(arr[x][y]<arr[x+1][y])
    {
        c1=1+longest_increasing_path(arr,x+1,y,n,m);
    }
    
    int c2=0;
    if(arr[x][y]<arr[x][y+1])
    {
        c2=1+longest_increasing_path(arr,x,y+1,n,m);
    }
    
    return max(c1,c2);
}

void longest_alternating_subarray(int arr[],int n)
{
    int temp[n+1];
    
    int k=0;
    temp[k]=1;
    for(int i=1;i<n;i++)
    {
        if(abs(arr[i]-arr[i-1]))
        {
            temp[k]++;
        }
        else
        {
            k++;
            temp[k]=1;
        }
    }
    
    for(int i=0;i<=k;i++)
    {
        int l=temp[i];
        while(l>0)
        {
            cout << l-- << " ";
        }
    }
    
}

int main()
{
    // int n=10;
    // cout << count_sum134(n);
    
    // int k=3;
    // cout << no_of_monotones(0,k);
    
    // int arr1[] = { -2, -3, 4, -1, -2, 1, 5, -3 }; 
    // int n1 = sizeof(arr1) / sizeof(arr1[0]); 
    // cout << maximum_subarray_sum(arr1, n1) << endl; 
    
    // int row=5;
    // int col=5;
    // int arr[5][5] = { { 0, 0, 0, -1, 0 }, 
    //                   { -1, 0, 0, -1, -1 }, 
    //                   { 0, 0, 0, -1, 0 }, 
    //                   { -1, 0, -1, 0, -1 }, 
    //                   { 0, 0, -1, 0, 0 } }; 
    
    // cout << check_path_available(arr,0,0,5,5);
    
    // int arr[] = { 3, 100, 4, 5, 150, 6 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << product_increasing_subsequence(arr, 0, -100, n ,1 ); 
    
    // print_hosaya(5);
    
    // int n=3;
    // int m=1;
    // cout << eulerian_number(3,1);
    
    // string s = "11000010001"; 
    // int n = 11; 
    // cout << max_difference_onesandzeros_v1(s,0,n,4,7) << endl; 
    // return 0; 
    
    // int arr[3][4]={{0, 0, 0 , 0}, {0, 1, 0 , 1 }, {0, 0, 0 ,0}};
    // cout << unique_paths(arr,0,0,3,4);
    
    // int arr[] = { 1, 3, 1, 5, 2 }; 
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << max_array_end_remove(arr,0,n-1,1);
    
    //int mat[][MAX] = { 
    //    { 1, 2, 3, 4 ,5}, 
	//	{ 2, 2, 3, 4 ,10}, 
	//	{ 3, 2, 3, 4 ,23}, 
	//	{ 4, 5, 6, 7 ,24}, 
    // }; 
    // int n = 5, m = 5; 
    // cout << longest_increasing_path(mat,0,0, n, m) << endl; 
    
    // int arr[] = { 1, 0, 1, 0, 0, 1 , 0, 1, 0, 0, 1 , 0, 0, 1 , 0, };  
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // longest_alternating_subarray(arr,n);
    return 0;
}