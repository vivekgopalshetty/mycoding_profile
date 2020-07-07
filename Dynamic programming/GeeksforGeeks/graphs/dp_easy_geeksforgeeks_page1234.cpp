//https://www.geeksforgeeks.org/easy/graph/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

bool ispath_bfs(vector<vector<int>> graph,int src,int dest)
{
    int vis[graph.size()]={0};
    queue<int> q;
    q.push(src);
    vis[src]=true;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        
        for(int i=0;i<graph[k].size();i++)
        {
            if(!vis[graph[k][i]])
            {
                if(graph[k][i]==dest)
                {
                    return true;
                }
                vis[graph[k][i]]=true;
                q.push(graph[k][i]);
            }
        }
    }
    
    return false;
}

//1.path exists
//2. distance between paths
void flyood_Warshall_types()
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            for(int k=0;k<V;k++)
            {
                 dp[i][j]=dp[i][j] || (dp[i][k] && dp[k][j]); //1
                 if(dp[i][j]>dp[i][k]+dp[k][j])  //2
                 {
                     dp[i][j]=dp[i][k]+dp[k][j];
                 }
                 
                 reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
                 // transitive closure
            }
        }
    }
    
    //negative cycle
    for(int i=0;i<V;i++)
    {
        if(dist[i][i]<0)
        {
            return true;
        }
    }
    
    return false;
}

vector<int> topological_sort()
{
    int indegree[n]={0};
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            indegree[j]+=1;
        }
    }
    
    int vis[n]={false};
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            vis[i]=true;
        }
    }
    
    vector<int> ans;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        ans.push_back(k);
        
        for(int i=0;i<adj[k].size();i++)
        {
            if(!vis[adj[k][i]])
            {
                indegree[adj[k][i]]=indegree[adj[k][i]]-1;
                if(indegree[adj[k][i]]==0)
                {
                    q.push(adj[k][i]);
                    vis[adj[k][i]]=1;
                }
            }
        }
        
    }
    
    return ans;
}

void to_the_end(vector<vector<int>> adj,int src,vector<int>& list,int vis[])
{
   
    vis[src]=1;
    list.push_back(src);
     
    int sum=0;
    for(int i=0;i<adj[src].size();i++)
    {
        if(!vis[adj[src][i]])
        {
            to_the_end(adj,adj[src][i],list);
        }
    }
}

vector<int> max_nodes_reachable_from_node(vector<vector<int>> adj)
{
    int n=adj.size();
    int vis[n]={0};
    vector<int> list;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        list.clear();
        if(vis[i]==0)
        {
           to_the_end(i); 
        }
        
        int cnt=list.size();
        for(int j=0;j<list.size();j++)
        {
            ans[list[i]]=cnt;
        }
    }
    
    return ans;
}

int binomical_coeff(int n,int k)
{
    if(k>n)
    {
        return 0;
    }
    
    int res=1;
    if(k>n-k)
    {
        k=n-k;
    }
    
    for(int i=0;i<k;i++)
    {
        res=res*(n-i);
        res=res/(i+1);
    }
    
    return res;
}

//n vertices
// m edges
int number_of_simple_graphs(int n,int m)
{
    int p=((n)*(n-1))/2;
    
    return binomical_coeff(p,m);
}

int cnt=0;
void dfs(vector<vector<int>> adj,int src,int dest,int vis[])
{
    vis[src]=1;
    if(src==dest)
    {
        cnt++;
        return;
    }
    
    for(int i=0;i<adj[src].size();i++)
    {
        if(vis[adj[src][i]]!=0)
        {
            dfs(adj,adj[src][i],dest,vis);
        }
    }
    
    vis[adj[src]]=0;
}

int walks_to_src_dest(vector<vector<int>> adj,int src,int dest)
{
    int visited[n]={0};
    dfs(adj,src,dest,vis);
    return cnt;
}

int nextmin_fordijkstra(bool inclu[],vector<int>& dist)
{
    int mini=INT_MAX;
    int minindex=-1;
    for(int i=0;i<n;i++)
    {
        if(inclu[i]==false && dist[i]<=min)
        {
            mini=dist[i];
            minindex=i;
        }
    }
    
    return minindex;
}

vector<int> dijsktra(vector<vector<int>> adj,int src,int n)
{
    vector<int> dist[n];
    bool inclu[n];
    
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        inclu[i]=false;
    }
    
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        int u=nextmin_fordijkstra(inclu,dist);
        inclu[u]=true;
        
        for(int v=0;i<V;v++)
        {
            if(inclu[v]==false && dist[u]!=INT_MAX
             && dist[v]>adj[u][v]+dist[u])
             {
                 dist[v]=adj[u][v]+dist[u]
             }
        }
    }
}

bool bfs_for_shortest_path(vector<vector<int>> adj,int src,
            int dest,int pred[],int dist[])
{
    int vis[n]={false};
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        pred[i]=-1;
    }
    
    queue<int> q;
    q.push(src);
    vis[src]=true;
    
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        
        for(int i=0;i<adj[k].size();i++)
        {
            if(!vis[adj[k][i]])
            {
                pred[adj[k][i]]=k;
                vis[adj[k][i]]=true;
                dist[adj[k][i]=dist[i]+1;
                q.push(adj[k][i]);
                
                if(adj[k][i]==dest)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

void shortest_path_using_bfs(vector<vector<int>> adj,int src,int dest)
{
    int dist[n];
    int pred[n];
    if(!bfs_for_shortest_path(adj,src,dest,dist,pred))
    {
        cout << "components not connected";
        return;
    }
    
    vector<int> path;
    int backcrawler=pred[dest];
    path.push_back(dest);
    while(backcrawler!=-1)
    {
        backcrawler=pred[backcrawler];
        path.push_back(backcrawler);
    }
    
    cout << dist[dest] << " ";
    
    cout << endl;
    for(auto i:path)
    {
        cout << i << " ";
    }
}

// Return the Number of ways from a 
// node to make a loop of size K in undirected 
// complete connected graph of N nodes 
int numOfways(int n, int k) 
{ 
    int p = 1; 
  
    if (k % 2) 
        p = -1; 
  
    return (pow(n - 1, k) + p * (n - 1)) / n; 
} 


//counting no.of nodes in cycle 
int cnt_nodes_in_cycles(int arr[],int n)
{
    int parent[n]={-1};
    bool visited[n]={false};
    
     for (i = 0; i < n; i++) { 
        j = i; 
        if (parent[j] == -1) { 
            while (parent[j] == -1) { 
                parent[j] = i; 
                j = (j + A[j] + 1) % n; 
            } 
  
            if (parent[j] == i) { 
                while (!vis[j]) { 
                    vis[j] = 1; 
                    cnt++; 
                    j = (j + A[j] + 1) % n; 
                } 
            } 
        } 
     }
}

int min_cost_train(int graph[][],int n)
{
    int dist[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(dist[i]>dist[j]+graph[i][j])
            {
                dist[i]=dist[j]+graph[i][j]
            }
        }
    }
    
    return dist[n-1];
}

bool isbipartite(vector<vector<int>> adj)
{
    bool vis[n]={false};
    int colored[n]={0};
    queue<int> q;
    q.push(0);
    
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        
        for(int i=0;i<adj[k].size();i++)
        {
            if(!vis[adj[k][i]])
            {
                colored[adj[k][i]]=!colored[i];
                q.push(adj[k][i]);
            }
            else if(colored[adj[k][i]]==colored[i])
            {
                return false;
            }
        }
    }
    
    return true;
}

void greedycoloring()
{
    int result[V]; 
    result[0]  = 0; 
    for (int u = 1; u < V; u++) 
        result[u] = -1; 
 
    bool available[V]; 
    for (int cr = 0; cr < V; cr++) 
        available[cr] = false; 
  
    for (int u = 1; u < V; u++) 
    { 
        vector<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (result[*i] != -1) 
                available[result[*i]] = true; 
  
        int cr; 
        for (cr = 0; cr < V; cr++) 
            if (available[cr] == false) 
                break; 
  
        result[u] = cr;

        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (result[*i] != -1) 
                available[result[*i]] = false; 
    } 
  
    for (int u = 0; u < V; u++) 
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl; 
} 

void MakeGraph(){ 
    graph[1].push_back(2); 
    graph[2].push_back(1); 
    graph[2].push_back(3); 
    graph[3].push_back(2); 
    graph[3].push_back(4); 
    graph[4].push_back(3); 
    graph[5].push_back(6); 
    graph[6].push_back(5); 
    graph[6].push_back(7); 
    graph[7].push_back(6); 
    graph[5].push_back(7); 
    graph[7].push_back(5); 
} 
  
  
int main() {
	c
	return 0;
}