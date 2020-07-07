//https://www.geeksforgeeks.org/medium/dynamic-programming/11/
//recursion

#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 99999999
#define inf 99999999
#define mod 1000000007

int max_dot_prod_inserting_0s_in2ndarr(int arr1[],int arr2[],int n,int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    
    return max((arr1[n-1]*arr2[m-1])+max_dot_prod_inserting_0s_in2ndarr(arr1,arr2,n-1,m-1),
            max_dot_prod_inserting_0s_in2ndarr(arr1,arr2,n-1,m));
}

//wrong
int unbounded_knapsack(int val[],int w[],int weight,int n)
{
    if(n==0 || weight==0)
    {
        return 0;
    }
    
    if(w[n-1]>weight)
    {
        return unbounded_knapsack(val,w,weight,n-1);
    }
    
    return max(unbounded_knapsack(val,w,weight,n-1),
        max(val[n-1]+unbounded_knapsack(val,w,weight-w[n-1],n-1),
        val[n-1]+unbounded_knapsack(val,w,weight-w[n-1],n)));
}

set<int> s;
void distinct_subset_sum(int arr[],int n,int sum)
{
    if(n==0)
    {
        s.insert(sum);
        return;
    }
    
    distinct_subset_sum(arr,n-1,sum+arr[n-1]);
    distinct_subset_sum(arr,n-1,sum);
}

int cnt_occurence_t_in_s_as_subseq(string s,string t,int n,int m)
{
    if(n==0)
    {
        return m==0;
    }
    
    if(m==0)
    {
        return 1;
    }
    
    int cnt=0;
    if(s[n-1]==t[m-1])
    {
        cnt=cnt_occurence_t_in_s_as_subseq(s,t,n-1,m-1)+
            cnt_occurence_t_in_s_as_subseq(s,t,n-1,m);
    }
    else
    {
        cnt=cnt_occurence_t_in_s_as_subseq(s,t,n-1,m);
    }
    
    return cnt;
}

int choice_area(int flag,int a,int b,vector<vector<int>> v)
{
    if(a<=0 || b<=0)
    {
        return 0;
    }
    
    int temp=0;
    if(flag==0)
    {
        temp=1+max(choice_area(1,a+v[1][0],b+v[1][1],v),
           choice_area(2,a+v[2][0],b+v[2][1],v));
    }
    else if(flag==1)
    {
        temp=1+max(choice_area(0,a+v[0][0],b+v[0][1],v),
        choice_area(2,a+v[2][0],b+v[2][1],v));
    }
    else if(flag==2)
    {
        temp=1+max(choice_area(0,a+v[0][0],b+v[0][1],v),
        choice_area(1,a+v[1][0],b+v[1][1],v));
    }
    
    return temp;
}

int main() {
    
    // int A[] = {2, 3 , 1, 7, 8};
    // int  B[] = {3, 6, 7};      
    // cout << max_dot_prod_inserting_0s_in2ndarr(A,B,5,3);
    
    // int W = 8;
    // int val[] = {10, 40, 50, 70};
    // int wt[]  = {1, 3, 4, 5};
    // int n=4;
    // cout << unbounded_knapsack(wt,val,W,n);
    
    // int arr[] = {2, 3, 4, 5, 6};
    // int n=5;
    // distinct_subset_sum(arr,n,0);
    // set<int> :: iterator it1;
    // for(it1=s.begin();it1!=s.end();it1++)
    // {
    //     cout << *it1 << " ";
    // }
    
    // string a = "banana";
    // string b = "ban"; 
    // cout <<  cnt_occurence_t_in_s_as_subseq(a,b,a.length(),b.length());
  
    // int a=20;
    // int b=8;
    
    // vector<vector<int>> v={{3,2},{-5,-10},{-20,5}};
    // cout << choice_area(0,a,b,v) << endl;
    // cout << choice_area(1,a,b,v) << endl;
    // cout << choice_area(2,a,b,v) << endl;
    
	return 0;
}