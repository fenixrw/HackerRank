#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Node{
    public:
    Node(){}
    vector<int> connections;
};

class Graph {
    vector<Node> nodes;
    public:
        Graph(int n) {
            nodes.resize(n);
        }
    
        void add_edge(int u, int v) {
            nodes[u].connections.push_back(v);
            nodes[v].connections.push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            vector<int> distance(nodes.size());
            
            for(int i=0;i<distance.size();i++){
                distance[i] = -1; // distance < 0 == not visited
            }
            
            distance[start] = 0;
            
            queue<int> visitNext;
            
            visitNext.push(start);
            
            while(!visitNext.empty())
            {
                int id = visitNext.front();
                visitNext.pop();
                
                for(int i=0; i<nodes[id].connections.size();i++)
                {
                    if(distance[nodes[id].connections[i]] < 0)
                    {
                        distance[nodes[id].connections[i]] = distance[id] + 6;
                        visitNext.push(nodes[id].connections[i]);
                    }
                }
                
            }
            
            return distance;
            
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
