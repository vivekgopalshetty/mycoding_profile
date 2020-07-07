//https://www.geeksforgeeks.org/medium/dynamic-programming/7/
//recursion

#include<bits/stdc++.h>
using namespace std;
#define MAX 50

int binomialCoeff(int n, int k) 
{ 
    if (k == 0 || k == n) 
        return 1; 
 
    return binomialCoeff(n - 1, k - 1) + 
           binomialCoeff(n - 1, k); 
} 
  
int RencontresNumber(int n, int m) 
{ 
    if (n == 0 && m == 0) 
        return 1; 
  
    if (n == 1 && m == 0) 
        return 0; 
  
    if (m == 0) 
        return (n - 1) * (RencontresNumber(n - 1, 0) + 
                          RencontresNumber(n - 2, 0)); 
  
    return binomialCoeff(n, m) * RencontresNumber(n - m, 0); 
} 

int max_sum_removing_elems(int arr[],int n,map<int,int> m,int start)
{
    if(start==n)
    {
        return 0;
    }
    
    int c1=INT_MIN;
    if(m[start]==0)
    {
        m[arr[start]-1]=1;
        m[arr[start]+1]=1;
        c1=arr[start]+max_sum_removing_elems(arr,n,m,start+1);  
    }
    
    int c2=max_sum_removing_elems(arr,n,m,start+1);
    return max(c1,c2);
}

bool transform_s1_to_s2(string s1,string s2,int n,int m)
{
    if(n<0 || m<0)
    {
        return false;
    }
    
    if(n==0 && m==0)
    {
        return true;
    }
    
    if(toupper(s1[n-1])==s2[m-1])
    {
        return transform_s1_to_s2(s1,s2,n-1,m-1);
    }
    else if(isupper(s1[n-1]))
    {
        return false;
    }
    
    return transform_s1_to_s2(s1,s2,n-1,m) || transform_s1_to_s2(s1,s2,n,m-1);
    
}

int longest_pallindromic_subseq(string s,int i,int j)
{
    if(i==j)
    {
        return 1;
    }
    
    if(s[i]==s[j] && i+1==j)
    {
        return 2;
    }
    
    if(s[i]==s[j])
    {
        return 2+longest_pallindromic_subseq(s,i+1,j-1);
    }
    
    return max(longest_pallindromic_subseq(s,i+1,j),longest_pallindromic_subseq(s,i,j-1));
}

bool subset_sum_problem(int arr[],int n,int sum)
{
    if(sum==0)
    {
        true;
    }
    
    if(n==0)
    {
        return false;
    }
    
    return subset_sum_problem(arr,n-1,sum-arr[n-1],arr,n-1,sum);
}

int main()
{
    // int arr[] =  { 2, 2, 3, 4 ,2,10,9};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // map<int,int> m;
    // cout << max_sum_removing_elems(arr,n,m,0);
    
    // string s1 = "argaju";
    // string s2 = "RAJ"; 
    // cout << transform_s1_to_s2(s1,s2,s1.length(),s2.length());
    
    cout << ways_to_sumn_usingelemsgr_eq_m(10,2); 
    return 0;
}