//https://www.geeksforgeeks.org/basic/graph/
#include<bits/stdc++.h>
using namespace std;

void BFS_using_adjaceny_list(int mat[MAXI][MAXI],int n,int m)
{
    vector<vector<int>> v(n);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==1)
            {
                v[i].push_back(j);
            }
        }
    }
    
    int visited[n]={0};
    queue<int> q;
    q.push(src);
    vis[src]=1;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        cout << k << " ";
        vis[k]=1;
        for(int i=0;i<v[k].size();i++)
        {
            if(vis[v[k][i]]!=1)
            {
                q.push(v[k][i]);   
                vis[v[k][i]]=1;
            }
        }
    }
}

void dfs(vector<vector<int>> graph,int visited[],int src,int curlevel,int l)
{
    if(curlevel==l)
    {
        ans++;
    }
    
    for(int i=0;i<graph[src].size();i++)
    {
        if(visited[graph[src][i]])
        {
             dfs(grpah,visited,graph[src][i],curlevel+1,l);
        }
    }
}

void dfs_init(vector<vector<int>> graph,int src,int edges,int l)
{
    bool visited[edges+1]={0};
    
    dfs(graph,visited,src,0,l);
}

int mini_distance_between_2nodes_bfs(vector<vector<int>> graph,int src,int dest)
{
    
    queue<int> q;
    int distance[graph.size()]={0};
    bool vis[graph.size()]={false};
    q.push(src);
    
    distance[src]=0;
    vis[src]=true;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        
        for(int i=0;i<graph[k].size();i++)
        {
            if(!vis[graph[k][i]])
            {
                if(distance[edges[k][i]]<distance[i]+1)
                {
                    distance[edges[k][i]]<distance[i]+1
                    q.push(graph[k][i]);
                    vis[graph[k][i]]=1;
                }
            }
        }
        
    }
    
    return distance[dest];
}

int mini_distance_between_2nodes_dfs(vector<vector<int>> graph,int src,int des,
                        int vis[],int edgecount,int& mincount)
{
    vis[src]=true;
    if(src==des)
    {
        if(edgecount<mincount)
        {
            mincount=edgecount;
        }
    }
    else
    {
        for(int i=0;i<graph[src].size();i++)
        {
            if(vis[graph[src][i]]!=1)
            {
                mini_distance_between_2nodes_dfs(graph,src,des,vis,edgecount++);
            }
        }
    }
    
    vis[src]=false;
    edgecount--;
}

int main() 
{ 
    
} 
