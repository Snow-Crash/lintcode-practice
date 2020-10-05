# Detect cycle in directed acyclic graph

## DFS

```cpp

bool Graph::isCyclic()
{
    // Initialize color of all vertices as WHITE
    int *color = new int[V];
    for (int i = 0; i < V; i++)
        color[i] = WHITE;
  
    // Do a DFS traversal beginning with all vertices
    for (int i = 0; i < V; i++)
        if (color[i] == WHITE)
           if (DFSUtil(i, color) == true)
              return true;
  
    return false;
}
// https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
  
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

```

## BFS

```cpp
bool Graph::isCycle()
{
    // Create a vector to store indegrees of all vertices. Initialize all indegrees as 0.
    vector<int> in_degree(V, 0);
  
    // Traverse adjacency lists to fill indegrees of vertices. This step takes O(V+E) time
    for (int u = 0; u < V; u++) {
        for (auto v : adj[u])
            in_degree[v]++;
    }
  
    // Create an queue and enqueue all vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);
  
    // Initialize count of visited vertices
    int cnt = 0;
  
    // Create a vector to store result (A topological ordering of the vertices)
    vector<int> top_order;
  
    // One by one dequeue vertices from queue and enqueue adjacents if indegree of adjacent becomes 0
    while (!q.empty()) {
  
        // Extract front of queue (or perform dequeue)
        // and add it to topological order
        int u = q.front();
        q.pop();
        top_order.push_back(u);
  
        // Iterate through all its neighbouring nodes of dequeued node u and decrease their in-degree by 1
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
  
            // If in-degree becomes zero, add it to queue
            if (--in_degree[*itr] == 0)
                q.push(*itr);
  
        cnt++;
    }
  
    // Check if there was a cycle
    if (cnt != V)  
        return true;
    else
        return false;
}
```
