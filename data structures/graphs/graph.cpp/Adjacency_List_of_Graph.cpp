#include <bits/stdc++.h>
using namespace std;

//bfs of a graph bfs is visiting adjacent nodes
void bfs(int v, vector<int> adj[]) {
	vector<int> bfs;
	vector<int> vis(v + 1, 0);
	for (int i = 1; i < v + 1; i++) {
		if (!vis[i]) {
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int node = q.front();
				vis[node] = 1;
				bfs.push_back(node);
				q.pop();
				for (auto it : adj[node]) {
					if (!vis[it]) {
						q.push(it);
						vis[it] = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < bfs.size(); i++) {
		cout << bfs[i] << " ";
	}
}


//adjacency list representaion of a graph

int main() {
	//n is nodes m is edges
	int n, m;
	cin >> n >> m;
	//array of vector
	vector<int> g[n + 1];

	//inserting nodes u,v of a edge m into array of vector
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);

	}

	//printing the edges
	bfs(n, g);
}