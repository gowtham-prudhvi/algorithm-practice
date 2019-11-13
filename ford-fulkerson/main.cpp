#include <iostream>
using namespace std;

#define V 6
bool bfs(int graph[V][V],int parent[V],int source,int sink)
{
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }


}
int fordFulkerson(int graph[V][V],int source,int sink)
{
    return 0;
}
int main() 
{ 
    // Let us create a graph shown in the above example 
    int graph[V][V] = { {0, 16, 13, 0, 0, 0}, 
                        {0, 0, 10, 12, 0, 0}, 
                        {0, 4, 0, 0, 14, 0}, 
                        {0, 0, 9, 0, 0, 20}, 
                        {0, 0, 0, 7, 0, 4}, 
                        {0, 0, 0, 0, 0, 0} 
                      }; 
  
    cout << "The maximum possible flow is " << fordFulkerson(graph,0, 5); 
    // cout << "Hello this is a test";
  
    return 0; 
} 