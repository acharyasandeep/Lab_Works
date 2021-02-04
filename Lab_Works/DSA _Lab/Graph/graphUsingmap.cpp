#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
using namespace std;
class Graph
{
private:
    int V;
    unordered_map<string,list<pair<string,int>>> adjList;
public:
    void addEdge(string x,string y ,bool bidir,int wt)
    {
        adjList[x].push_back(make_pair(y,wt));
        if(bidir)
            adjList[y].push_back(make_pair(x,wt));
    }
    void printAdjList()
    {
        for(auto key:adjList)
        {
            cout<<key.first<<" -> ";
            for(auto node:key.second)
                cout<<"("<<node.first<<","<<node.second<<")"<<" ";
            cout<<endl;
        }
    }
};
int main()
{
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("A","C",false,10);
    g.addEdge("B","D",false,30);
    g.addEdge("D","E",true,40);
    cout<<"The node list is: "<<endl;
    g.printAdjList();
    return 0;
}
