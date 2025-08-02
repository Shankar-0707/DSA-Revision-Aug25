#include <iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;


class Graph{
    public:
    unordered_map<int, list<pair<int,int>>> adjList;

    void addEdge(int u, int v,  int wt, bool direction){
        // direction 0 = undirected graph
        // direction 1 = directed graph
        if(direction == 0){
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        else{
            adjList[u].push_back({v,wt});
        }
    }


    void printAllNodes(int n){
        for(int i=0; i<n; i++){
            cout << i << " -> " << "{";
            auto temp = adjList[i];
            // jo hme temp milega vo ek list hogi jo pair store kr rhi hogi 
            //  first -  node
            // second - weight
            for(auto nbr : temp){
                cout << "(" << nbr.first << "," << nbr.second << "),"; 
            }

            cout << "}" << endl;
        }
    }


    void BFS(int src){
        queue<int>q;
        unordered_map<int,bool> visited;

        // initial condition
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            auto frontNode = q.front();
            cout << frontNode << ",";
            q.pop();

            for(auto nbr : adjList[frontNode]){
                int node = nbr.first;
                if(!visited[node]){
                    q.push(node);
                    visited[node] = true;
                }
            }

            
        }
    }


    void dfsHelper(int src, unordered_map<int,bool>& visited){
        visited[src] = true;
        cout << src << "," ;

        for(auto nbr : adjList[src]){
            int node = nbr.first;
            if(!visited[node]){
                dfsHelper(node, visited);
            }
        }
    }

    void  DFS(int n){
        unordered_map<int,bool> visited;

        for(int src = 0; src<n; src++){
            if(!visited[src]){
                dfsHelper(src, visited);
            }
        }
    }

};


int main() {

    Graph g;

    g.addEdge(0,3,3,1);
    g.addEdge(0,5,3,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,5,3,1);
    g.addEdge(3,5,3,1);
    g.addEdge(5,4,3,1);
    g.addEdge(5,6,3,1);
    g.addEdge(4,1,3,1);
    g.addEdge(6,1,3,1);

    // int n = 7;
    // g.printAllNodes(n);

    // g.BFS(0);
    g.DFS(7);
    return 0;
}