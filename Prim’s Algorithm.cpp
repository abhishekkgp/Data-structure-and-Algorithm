PROBLEM DESCRIPTION:-
  Given a weighted, undirected and connected graph of V vertices and E edges. 
  The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

Input format:
  First input is integer "V" denoting the number of vertices.
  Next input is an 2d array "edges" where each edges[i] contains three space-separated integers denoting each edge and weight between the edges.

Output format:
  Return sum of weights of the edges of the Minimum Spanning Tree

example:
    V=3
    edges:
        0 1 5
        1 2 3
        0 2 1
    
Output: 4
------------------------------------------------------------------------------------------------------------------------------------------------------------

int PrimsMinimumSpanningTree(int V, vector<vector<int>> edges)
{
    // storing {weight,node} pair for each node and the node it is connected with
    vector<vector< pair<int,int> >> adj(V); 
    for(int i=0;i<V; i++)
    {
        adj[edges[i][0]].push_back({edges[i][2],edges[i][1]}); // storing {weight,node} pair
        adj[edges[i][1]].push_back({edges[i][2],edges[i][0]}); // storing {weight,node} pair
    }

    // MIN HEAP applying using priority_queue
    priority_queue< pair<int,int>, vector<pair<int,int> >, geater<pair<int,int> > > pq;

    vector<bool> vis(V,false); // to check wheather we have already added the node in minimum spanning tree or not
    
    int MST=0; // result of minimum weight some storing in this

    // Intially adding 0th node (we can choose any arbitary node initially), 
    // weight of starting/intial node will be 0
    pq.push({0,0}); //{weight,node}

    while(!pq.empty())
    {
      // Select the item <node,weight> with minimum weight
        auto top=pq.top();
        pq.pop();
        int node=top.second, wt=top.first;
      
        // If the node is node not yet added to the minimum spanning tree add it
        if(vis[node]==false)
        {
            vis[node]=true;
            MST+=wt;
          
            // Iterate through all the nodes adjacent to the node taken out of priority queue.
            // Push only those nodes (weight,node) that are not yet present in the minumum spanning tree
            for(auto x: adj[node])
            {
                int val=x.second;
                if(vis[val]==false)
                {
                    pq.push(x);
                }
            }
        }
    }

    return MST;


}
