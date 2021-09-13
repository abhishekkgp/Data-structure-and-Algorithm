/*
Problem Description:

Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B of size M x 2 
where (B[i][0], B[i][1]) represents two nodes B[i][0] and B[i][1] connected by an edge.

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:
The cycle must contain atleast three nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
*/
------------------------------------------------------------------------------------------------------------------------------------
1. METHOD-1 (mostly given everywhere this solution)
In this case, time complexity=O(n)
             space complexity= O(n)

int find_parent(int u, vector<int> &parent)
{
    if(u==parent[u]) return u;
    return parent[u]=find_parent(parent[u],parent);
}

void union_set(int u, int v, vector<int> &rank, vector<int> &parent)
{
    if(rank[u]>rank[v])
    {
        parent[v]=u;
    }
    else if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else
    {
        parent[u]=v;
        rank[v]++;
    }
    
}

int IsCycle(int A, vector<vector<int> > &B) { //solution Main Function
    vector<int> rank(A+1,0);
    vector<int> parent(A+1);
    for(int i=1;i<=A;i++)
    {
        parent[i]=i;
    }
    for(int i=0;i<B.size();i++)
    {
        int u=B[i][0], v=B[i][1];
        int u_parent=find_parent(u,parent);
        int v_parent=find_parent(v,parent);
        //cout<<u_parent<<" "<<v_parent<<endl;
        if(u_parent != v_parent)
        {
            union_set(u_parent,v_parent,rank,parent);
        } 
        else 
        {
            return 1;
        }    
    }
    return 0;
}

--------------------------------------------------------------------------------------
    
 Method -2 ( I solved using this once and looked simple then above solution)
 In this case also, time complexity=O(n)
                    space complexity= O(n)   
  
     
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    //bfs
    // keeping track of last element importanat as we don't consider cycle using last node 
    // as two node note make cycle but if connected with other under processed node then it will make cycle
    bool dfs( vector<int> adj[],vector<int> &vis, int node, int last)  
    {
        if(vis[node]==0) return true; //under process
        else if(vis[node]==1) return false; // already processed so return false as it won't have come here if we had alredy find cycle using this node
        vis[node]=0; //
        for(auto x: adj[node])
        {
            if(dfs(adj,vis,x,node) && x!=last)
            {
                return 1;
            }
        }
        vis[node]=1;
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) { // here adj[i] contains all adjecent vertex of vertex i.
        // Code here
        vector<int> vis(V,-1);
        for(int i=0;i<V;i++) // if whole graph is not connected
        {
            if(vis[i]==-1 && dfs(adj,vis,i,-1)) return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
