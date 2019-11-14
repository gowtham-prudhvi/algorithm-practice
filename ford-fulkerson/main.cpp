#include <iostream>
using namespace std;

#define V 6
int queue[10];
int qfront = 0;
int qend = 0;

void push(int newval)
{
    queue[qend] = newval;
    qend++;
}

int pop()
{
    int tempval = queue[qfront];
    qfront++;
    return tempval;
}

int qlen()
{
    return qend - qfront;
}

bool bfs(int graph[V][V],int parent[V],int source,int sink)
{
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    qfront = 0;
    qend = 0;

    visited[source]=true;
    parent[source]=-1;
    push(source);
    while(qlen() != 0)
    {
        int curr_vertex=pop();
        // cout<<"curr_vertex " << curr_vertex<<endl;
        // cout<<"qfront " << qfront<<endl;
        // cout<<"qlen " << qlen()<<endl;
        visited[curr_vertex]=true;
        for(int i=0;i<V;i++)
        {
            if(visited[i] == false && graph[curr_vertex][i] > 0)
            {
                push(i);
                parent[i]=curr_vertex;
            }
        }
    }
    return (visited[sink] == true);
}

int fordFulkerson(int graph[V][V],int source,int sink)
{
    int resGraph[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            resGraph[i][j]=graph[i][j];
        }
    }
    // cout<<"initial res graph created "<<endl;
    int flow=0;
    int parent[V];
    while(bfs(resGraph,parent,source,sink))
    {
        int max_path_flow = 10000;
        for(int i=sink;parent[i]!=-1;i=parent[i])
        {
            // cout<<"i: "<<i<<" parent[i]: "<<parent[i]<<endl;
            max_path_flow=min(max_path_flow,resGraph[parent[i]][i]);
        }
        // cout<<"another bfs called properly with flow"<<max_path_flow<<endl;
        // return 0;
        flow+=max_path_flow;

        for(int i=sink;parent[i]!=-1;i=parent[i])
        {
            resGraph[i][parent[i]]+=max_path_flow;
            resGraph[parent[i]][i]-=max_path_flow;

        }

    }
    return flow;
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