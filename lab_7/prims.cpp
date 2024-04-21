#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 1e3;
int graph[MAX][MAX];
int n;

int prims(vector<string> cities)
{
    int selected[n];
    memset(selected, false, sizeof(selected));
    selected[0] = true;
    int no_edge = 0;
    int x;
    int y;
    int min_cost = 0;
    cout << "cost: ";
    while (no_edge < n - 1)
    {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j])
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << cities[x] << " " << cities[y] << " " << min << endl;
        min_cost += min;
        selected[y] = true;
        no_edge++;
    }
    return min_cost;
}

int main() {
   cout << "Enter the number of cities: ";
    cin >> n;
   cout<<"Enter the names of the cities: "<<endl;
    vector<string> cities(n);
    for(int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    cout<<"Enter the no of the edges: "<<endl;
    int m;
    cin >> m;
    cout<<"Enter the cost of the edges: (city1 city2 cost) "<<endl;
    for(int i = 0; i < m; i++) {
        string city1, city2;
        int cost;
        cin >> city1 >> city2 >> cost;
        int index1 = find(cities.begin(), cities.end(), city1) - cities.begin();
        int index2 = find(cities.begin(), cities.end(), city2) - cities.begin();
        graph[index1][index2] = cost;
        graph[index2][index1] = cost;
    }
    cout << prims(cities) << endl;
    return 0;
}
