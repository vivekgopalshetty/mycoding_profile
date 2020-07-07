//https://www.geeksforgeeks.org/medium/dynamic-programming/8/
//recustion

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999

int subsequence_atleastk_dist(int arr[],int n,int k)
{
    if(n<=0)
    {
        return 0;
    }
    
    return max(arr[n-1]+subsequence_atleastk_dist(arr,n-k-1,k),
        subsequence_atleastk_dist(arr,n-1,k));
}

int lcs_with_atmost_kchanges(int arr1[],int arr2[],int n,int m,int k)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    
    int c4=INT_MIN;
    if(arr1[n-1]==arr2[m-1])
    {
        c4=1+lcs_with_atmost_kchanges(arr1,arr2,n-1,m-1,k);
    }
    int c1=lcs_with_atmost_kchanges(arr1,arr2,n-1,m,k);
    int c2=INT_MIN;
    if(k>0)
    {
       c2=1+lcs_with_atmost_kchanges(arr1,arr2,n-1,m-1,k-1);   
    }
    
    int c3=lcs_with_atmost_kchanges(arr1,arr2,n,m-1,k);
    
    return max(max(c1,c2),max(c3,c4));
}

int min_cell_jumps(int mat[MAX][MAX],int n,int m,int x,int y)
{
    if(x<0 || y<0 || x>n-1 || y>m-1)
    {
        return INT_MAX;
    }
    
    if(x==n-1 && y==m-1)
    {
        return 0;
    }
    
    return 1+min(min_cell_jumps(mat,n,m,x,y+mat[x][y]),
            min_cell_jumps(mat,n,m,x+mat[x][y],y));
}

//0 house
//1 office
int cnt_ways_to_build_house_office(int n,int lane1,int lane2)
{
    if(n<0)
    {
        return 0;
    }
    
    if(n==0)
    {
        return 1;
    }
    
    int sum=0;
    sum+=cnt_ways_to_build_house_office(n-1,0,0);
    if(lane1==1)
    {
        sum+=cnt_ways_to_build_house_office(n-1,0,1);
    }
    else
    {
        if(lane2==1)
        {
             sum+=cnt_ways_to_build_house_office(n-1,1,0);
        }
        else
        {
             sum+=cnt_ways_to_build_house_office(n-1,0,1);
             sum+=cnt_ways_to_build_house_office(n-1,1,0);
        }
    }
    
    return sum;
}

int main() {
    
    // int arr[] = {50, 70, 40, 50, 90, 70, 60,40, 70, 50};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int k = 2;
    // cout << subsequence_atleastk_dist(arr,n,k);
    
    // int arr1[] = { 1, 2, 3, 4, 5 };
    // int arr2[] = { 5, 3, 1, 4, 2 };
    // int n=sizeof(arr1)/sizeof(arr1[0]);
    // int m=sizeof(arr2)/sizeof(arr2[0]);
    // int k = 1;
    // cout << lcs_with_atmost_kchanges(arr1,arr2,n,m,k);
    
    // int mat[MAX][MAX] = { {2, 3, 2, 1, 4},
    //                 {3, 2, 5, 8, 2},
    //                 {1, 1, 2, 2, 1}};
                    
    // int n=3;
    // int m=5;
    // cout << min_cell_jumps(mat,n,m,0,0);
    
    int n=2;
    cout << cnt_ways_to_build_house_office(n-1,0,1)+
    cnt_ways_to_build_house_office(n-1,1,0)+cnt_ways_to_build_house_office(n-1,0,0);
	return 0;
}