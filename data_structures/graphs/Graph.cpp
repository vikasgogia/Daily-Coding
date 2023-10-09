#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph {
    private: 
        bool isDirected = 0;
        unordered_map<int, list<int>> adj;

        void dfs(int node, unordered_map<int, bool> &visited, vector<int> &component) {
            if(visited[node]) return;
            component.push_back(node);
            visited[node] = 1;
            for(auto i: adj[node]) {
                if(!visited[i]) dfs(i, visited, component);
            }
        }

    public:
        Graph(bool isDirected) {
            // false = undirected
            // true = directed
            this->isDirected = isDirected;
        }

        int countNodes() {
            return adj.size();
        }

        unordered_map<int, list<int>> getAdjacencyListForEducationalPurposes() {
            return adj;
        }

        void addEdge(int u, int v){
            adj[u].push_back(v);

            // if undirected
            if(!isDirected) adj[v].push_back(u);
        }

        void printAdjList(){
            for(auto i:adj){
                cout << i.first << " -> "; // node
                for(auto j: i.second) 
                    cout << j << ", "; // neighbors
                cout << endl;
            }
        }

        void bfsTraversal() {
            unordered_map<int, bool> visited;
            queue<int> q;

            cout << "\nBFS: ";
            // loop for disconnected components
            for(int x=0; x< adj.size(); x++) {
                if(!visited[x]) {
                    q.push(x);
                    visited[x] = true;
                }

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    cout << node << ", ";

                    for(int i: adj[node]) {
                        if (!visited[i]) {
                            q.push(i);
                            visited[i] = true;
                        }
                    }
                }
            }
        }

        void dfsTraversal() {
            unordered_map<int, bool> visited;

            cout << "\nDFS: ";
            
            // loop for disconnected components
            for(int i=0; i< countNodes(); i++) {
                if(!visited[i]) {
                    vector<int> component;
                    dfs(i, visited, component);
                    
                    for(auto c: component) cout << c << ", ";
                }
            }
        }
};