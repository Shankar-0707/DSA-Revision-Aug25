#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;


class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction){
        //direction = 0 mtlb undirected graph
        //direction = 1 mtlb directed graph

        if(direction == 0){
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        else{
            adjList[u].push_back({v,wt});
        }
    }



    void printAdjlist(int n){
        for(int i=0; i<n; i++){
            cout << i <<" -> " << "{" ;
            list<pair<int,int>> temp = adjList[i];
            for(auto j : temp){
                cout << "(" << j.first << "," << j.second << ")" << "," ;
            }
            cout << "}" << endl;
        }
    }
};

int main() {

    Graph g;
    g.addEdge(0,1,3,1);
    g.addEdge(0,2,2,1);
    g.addEdge(1,2,1,1);
    g.addEdge(2,3,10,1);
    g.printAdjlist(4);


    return 0;
}