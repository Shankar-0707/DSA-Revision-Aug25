class Solution {
  public:
  
    
    void BFS(int src,  unordered_map<int,list<int>>& adjList, int n, vector<int>& ans,unordered_map<int,bool>& visited){
        
        unordered_map<int,int> parent;
        queue<int> q;
        
        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        // main logic
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto nbr : adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
            }
        }
        
        
        
        // yha hmari parent array ready ho gyi h
        
        for(int i=0; i<n ; i++){
            int j = i;
            int count = 0;
            
            if(j == src){
                ans.push_back(count);
            }
            
            else{
                while(j != src || j != -1){
                    count++;
                    j = parent[j];
                }
                
                if(j == -1){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(count);
                }
            }
            
        }
        
        
    }
    
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        unordered_map<int,list<int>> adjList;
        unordered_map<int,bool> vis;
        
        int n = adj.size();
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            for(auto edge : adj[i]){
                adjList[i].push_back(edge);
            }
        }
        
        BFS(src, adjList, n , ans, vis);
        return  ans;
        
    }
};