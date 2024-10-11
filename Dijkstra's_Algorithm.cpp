#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

// Define a pair structure to store vertex and its weight
typedef pair<int, int> Pair;

// Dijkstra's Algorithm function
void dijkstra(vector<vector<Pair>>& graph, int source) {
    int V = graph.size();  // Number of vertices
    vector<int> dist(V, INT_MAX);  // Distance array, initialized to infinity
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;  // Min-heap priority queue

    // Set the source vertex distance to 0 and push it into the queue
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;  // Extract the vertex with the minimum distance
        pq.pop();

        // Traverse the adjacent vertices of u
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;   // Adjacent vertex
            int weight = neighbor.second;  // Edge weight

            // If a shorter path to v is found
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});  // Push the updated distance to the priority queue
            }
        }
    }

    // Print the shortest distances from source
    cout << "Vertex\t\tDistance from Source\n";
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Graph representation using adjacency list
    vector<vector<Pair>> graph(V);

    // Input for edges and weights
    cout << "Enter edges and their weights (format: u v w):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For undirected graph, include this line
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    // Run Dijkstra's Algorithm
    dijkstra(graph, source);

    return 0;
}
