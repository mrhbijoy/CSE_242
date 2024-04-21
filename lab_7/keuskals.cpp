#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3;
vector<pair<int, pair<int, int>>> edges;
int parent[MAX];
int n;

int find(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
    parent[find(x)] = find(y);
}

int kruskal(vector<string> cities) {
    sort(edges.begin(), edges.end());
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int min_cost = 0;
    cout << "cost: ";
    for(auto e : edges) {
        int w = e.first;
        int x = e.second.first;
        int y = e.second.second;
        if(find(x) != find(y)) {
            cout << cities[x] << " " << cities[y] << " " << w << endl;
            min_cost += w;
            union_set(x, y);
        }
    }
    return min_cost;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;
    cout << "Enter the names of the cities: " << endl;
    vector<string> cities(n);
    for(int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    cout << "Enter the no of the edges: " << endl;
    int m;
    cin >> m;
       cout<<"Enter the cost of the edges: (city1 city2 cost) "<<endl;
    for(int i = 0; i < m; i++) {
        string city1, city2;
        int cost;
        cin >> city1 >> city2 >> cost;
        int index1 = find(cities.begin(), cities.end(), city1) - cities.begin();
        int index2 = find(cities.begin(), cities.end(), city2) - cities.begin();
        edges.push_back({cost, {index1, index2}});
    }
    cout << kruskal(cities) << endl;
    return 0;
}