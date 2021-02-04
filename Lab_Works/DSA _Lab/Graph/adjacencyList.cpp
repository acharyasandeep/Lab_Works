#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V; //V means no of vertices
    list <int> *l; //l is a pointer to list
public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V]; //creating a dyanamic array of lists with size V
    }
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
        /*
        for eg. addEdge(0,1) means
        we should append 1 to the list[0]
        we should append 0 to the list[1]
        0->1
        1->0
        again addEdge(0,2) means
        we should append 2 to the list[0]
        we should append 0 to the list[2]
        0->1,2
        1->0
        2->0
        again addEdge(1,2) means
        we should append 2 to list[1]
        we should append 1 to list[2]
        0->1,2
        1->0,2
        2->0,1
        */
    }
    void printAdjList()
    {
        for(int i=0;i<V;i++)
        {
            cout<<"Vertex "<<i<<"->";
            for(int nbr:l[i])
                cout<<nbr<<",";
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(4); //we created the graph with 4 vertices(0,1,2,3)
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.printAdjList();
    return 0;
}
