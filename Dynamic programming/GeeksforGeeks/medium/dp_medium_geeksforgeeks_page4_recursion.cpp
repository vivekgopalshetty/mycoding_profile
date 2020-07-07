//https://www.geeksforgeeks.org/medium/dynamic-programming/4/
//recursion

#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int ways_range_sum(int n,int l,int r,int sum)
{
    if(n<0)
    {
        return 0;
    }
    
    if(n==0)
    {
        return sum%2==0;
    }
    
    int ways=0;
    for(int i=l;i<=r;i++)
    {
        ways+=ways_range_sum(n-1,l,r,sum+i);
    }
    
    return ways;
}

int MOD=998244353;

int colour_nboxes_mcol_withk(int idx,int n,
                    int m,int k,int diff)
{
    if(idx>n)
    {
        if(diff==k)
        {
            return 1;
        }
        return 0;
    }
    
    int ans=colour_nboxes_mcol_withk(idx+1,n,m,k,diff);
    ans+=(m-1)*colour_nboxes_mcol_withk(idx+1,n,m,k,diff+1);
    
    return ans;
    
}

bool findmatch(char mat[MAX][MAX], string pat, int x, int y, 
               int nrow, int ncol, int level) 
{ 
    int l = pat.length(); 
    if (level == l) 
        return true; 
 
    if (x < 0 || y < 0 || x >= nrow || y >= ncol) 
        return false; 
  
    if (mat[x][y] == pat[level]) { 
  
        
        char temp = mat[x][y]; 
        mat[x][y] = '#'; 
  
        bool res = findmatch(mat, pat, x - 1, y, nrow, ncol, level + 1) |  
                   findmatch(mat, pat, x + 1, y, nrow, ncol, level + 1) |  
                   findmatch(mat, pat, x, y - 1, nrow, ncol, level + 1) |  
                   findmatch(mat, pat, x, y + 1, nrow, ncol, level + 1); 
  
        
        mat[x][y] = temp; 
        return res; 
    } 
    else 
        return false; 
} 
  
bool checkMatch(char mat[MAX][MAX], string pat, int nrow, int ncol) 
{ 
  
    int l = pat.length(); 
  
    if (l > nrow * ncol) 
        return false; 
  
    for (int i = 0; i < nrow; i++) { 
        for (int j = 0; j < ncol; j++) { 
            
            if (mat[i][j] == pat[0]) 
                if (findmatch(mat, pat, i, j, nrow, ncol, 0)) 
                    return true; 
        } 
    } 
    return false; 
} 

int cnt_path_with_edge_m_weight_k(int passed,int w,int k,int m,int sum,int level)
{
    if(sum>w || level>k)
    {
        return 0;
    }
    
    if(sum==w)
    {
        if(passed)
        {
            return 1;
        }
        
        return 0;
    }
    
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        if(i>=m)
        {
            ans+=cnt_path_with_edge_m_weight_k(1,w,k,m,sum+i,level+1);
        }
        else
        {
             ans+=cnt_path_with_edge_m_weight_k(passed,w,k,m,sum+i,level+1);
        }
       
    }
    
    return ans;
}

int treasure_and_cities(int T[],int C[],int& a,int& b,int start,int& end,int prev)
{
    if(start>end-1)
    {
        return 0;
    }
    
    int ans=0;
    int c1=0,c2=0;
    if(prev==0 || prev!=C[start])
    {
        c1=b*T[start]+treasure_and_cities(T,C,a,b,start+1,end,C[start]);
        c2=treasure_and_cities(T,C,a,b,start+1,end,prev);
        ans=max(c1,c2);
    }
    else
    {
        c1=a*T[start]+treasure_and_cities(T,C,a,b,start+1,end,C[start]);
        c2=treasure_and_cities(T,C,a,b,start+1,end,prev);
        ans=max(c1,c2);
    }
    
    return ans;
}

int main() {
    
    // int n=10;
    // int l=1;
    // int r=6;
    // cout << ways_range_sum(n,l,r,0);
    
    // int n=5;
    // int m=3;
    // int k=2;
    // cout << m*colour_nboxes_mcol_withk(2,n,m,k,0);
    
    // int W = 4, K = 3, M = 2;
    // cout << cnt_path_with_edge_m_weight_k(0,W,K,M,0,0);
    
    // int A = -5, B = 7; 
    // int treasure[] = { 4, 8, 2, 9 }; 
    // int color[] = { 2, 2, 6, 2 }; 
    // int n = sizeof(color) / sizeof(color[0]);
    // cout << treasure_and_cities(treasure, color,A, B,0,n, 0); 
	return 0;
}