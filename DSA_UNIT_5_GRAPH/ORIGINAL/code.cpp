#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V, E, u, v;

    cout << "Enter number of substations: ";
    cin >> V;

    vector<vector<int>> adj(V + 1);

    cout << "Enter number of power lines: ";
    cin >> E;

    cout << "Enter each power line (u v):\n";

    for (int i = 0; i < E; i++) {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "\nGraph Representation:\n";

    for (int i = 1; i <= V; i++) {
        cout << "Substation " << i << ": ";

        for (int j : adj[i]) {
            cout << j << " ";
        }

        cout << endl;
    }

    cout << "\nDegree of Each Substation:\n";

    for (int i = 1; i <= V; i++) {
        cout << "Substation " << i << ": "
             << adj[i].size() << endl;
    }

    return 0;
}
