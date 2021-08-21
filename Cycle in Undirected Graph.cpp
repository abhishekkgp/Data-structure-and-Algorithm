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
