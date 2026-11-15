
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compare degrees
bool compareDegree(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first > b.first;

    return a.second < b.second;
}

int main()
{
    int n, m, u, v, k;
    char choice;

    cout << "Enter number of substations: ";
    cin >> n;

    vector< vector<int> > adj(n + 1);

    cout << "Enter number of power lines: ";
    cin >> m;

    cout << "Enter power lines (u v):\n";

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Do you want to add a new substation? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        int newNode = ++n;
        adj.resize(n + 1);

        cout << "New substation added: " << newNode << endl;

        cout << "Enter number of power lines for it: ";
        cin >> k;

        cout << "Enter power lines (u v):\n";

        for (int i = 0; i < k; i++)
        {
            cin >> u >> v;

            if (u >= 1 && u <= n &&
                v >= 1 && v <= n && u != v)
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            else
            {
                cout << "Invalid connection!\n";
                i--;
            }
        }
    }

    cout << "\nGraph Representation:\n";

    for (int i = 1; i <= n; i++)
    {
        cout << "Substation " << i << ": ";

        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }

    cout << "\nIsolated Substations:\n";

    bool found = false;

    for (int i = 1; i <= n; i++)
    {
        if (adj[i].empty())
        {
            cout << "Substation " << i
                 << " has no connections.\n";

            found = true;
        }
    }

    if (!found)
    {
        cout << "No isolated substations.\n";
    }

    vector< pair<int, int> > degree;

    for (int i = 1; i <= n; i++)
    {
        degree.push_back(
            make_pair((int)adj[i].size(), i)
        );
    }

    sort(degree.begin(), degree.end(), compareDegree);

    cout << "\nSubstations in Descending Order of Degree:\n";

    for (int i = 0; i < degree.size(); i++)
    {
        cout << "Substation " << degree[i].second
             << " : Degree = " << degree[i].first << endl;
    }

    return 0;
}
