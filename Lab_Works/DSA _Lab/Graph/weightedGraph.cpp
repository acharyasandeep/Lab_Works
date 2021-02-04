#include <iostream>
#include <list>
using namespace std;
class Graph
{
private:
    int V; //v is the no of vertices in graph
    list<pair<int,int>> *adjList; //stores the neighbours of the vertices,
    //pairs means there's (vertex,weight)
public:
    Graph(int v)
    {
        V=v;
        adjList = new list<pair<int,int>>[v]; //create
    }
    void addEdge(int vertex1,int vertex2,int weight)
    {
        if (vertex1>=V || vertex2>=V)
        {
            cout<<"supplied vertex can't be greater than the no of vertex"<<endl;
            return;
        }
        adjList[vertex1].push_back(make_pair(vertex2,weight));
        adjList[vertex2].push_back(make_pair(vertex1,weight));
    }
    void printAdjList()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"-> ";
            for(auto nbrs:adjList[i])
            {
                cout<<"("<<nbrs.first<<", "<<nbrs.second<<")"<<", ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g(5);
    //connection of 0 with vertices
    g.addEdge(0,1,5);
    g.addEdge(0,4,10);
    g.addEdge(0,2,6);
    //connection of 1 with vertices
    g.addEdge(1,2,15);
    g.addEdge(1,4,20);
    //connection of 3 with vertices
    g.addEdge(3,0,1);
    g.addEdge(3,4,10);
    g.addEdge(3,10,10);
    g.printAdjList();
}
