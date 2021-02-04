#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <queue>
using namespace std;
//creating graph class
class Graph
{
    int vertices; //no of vertices in graph
    list<pair<int,int>> *adjList; //adjacency list
public:
    Graph(int v):vertices(v)
    {
        //intialize adjacency list with the no of vertices
        adjList = new list<pair<int,int>>[vertices];
    }
    //a function to add edge in graph
    //src is source node
    //dest is destination node
    //wt means the cost required to go from src to dest,0 if not specified
    //isBidirectional indicates if the edge is bidirectional, true if not specified
    void addEdge(int src,int dest,int wt=0,bool isBidirectional = true)
    {
        //insert the edge from src to dest with respective wt in the src vertex of the adjacency list
        adjList[src].push_back(make_pair(dest,wt));
        //for bidirectional edge also insert the edge from dest to src with respective wt in dest vertex of the adjacency list
        if(isBidirectional)
            adjList[dest].push_back(make_pair(src,wt));
    }

    void printAdjList()
    {
        for(int i=0;i<vertices;i++)
        {
            cout<<i<<" -> ";
            for(auto node:adjList[i])
            {
                cout<<"("<<node.first<<", "<<node.second<<")";
            }
            cout<<endl;
        }
    }
    void bfs(int src)//breadthFirstSearch
    {
        queue<int> q;//queue to store the nodes
        vector<bool> visited(vertices,false); //construct vector equal to the no of vertices
        //to keep track of the vertices visited during bfs
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            for(auto node:adjList[q.front()])
            {
                if(!visited[node.first])//if the nodes is not visited push it to queue
                 q.push(node.first);

                //set visit status of node to true
                visited[node.first]=true;
            }
            cout<<q.front()<<", ";
            q.pop();
        }
        cout<<endl;
    }
    void dfsHelper(int src, vector<bool> &visited)
    {
        cout<<src<<", ";
        visited[src]=true;
        for(auto node: adjList[src])
        {
            if(!visited[node.first])
                dfsHelper(node.first,visited);
        }
    }

    void dfs(int src)
    {
        vector<bool> visited(vertices,false);
        dfsHelper(src,visited);
    }
};
int main()
{
    Graph g(9);
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(4,6);
    g.addEdge(4,8);
    g.addEdge(4,7);
    g.printAdjList();
    cout<<"BFS(4 as start node): ";
    g.bfs(4);
    cout<<"DFS(2 as start node): ";
    g.dfs(2);
}
