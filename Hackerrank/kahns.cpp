#include <bits/stdc++.h>
using namespace std;

bool required[20001];

void dfs(int temp, vector<vector<int> > &adj) {
	required[temp] = true;
	for (int i = 0; i < adj[temp].size(); i++) {
		if (!required[adj[temp][i]]) 
			dfs(adj[temp][i], adj);
	}
}

void kahns(vector<vector<int> > &reverse, vector<int> &indegree, int n) {
	priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		if (required[i] && indegree[i] == 0)
			q.push(-i);
	}
	vector<int> result;
	int count = 0;
	while (!q.empty()) {
		count++;
		int u = -q.top();
		q.pop();
		result.push_back(u);
		for (int i = 0; i < reverse[u].size(); i++) {
			if (required[reverse[u][i]] && --indegree[reverse[u][i]] == 0) {
				q.push(reverse[u][i]);
			}
		}
	}
	cout << count << endl;
	for (int i = 0; i < result.size(); i++) 
		cout << result[i] << " ";
	cout << endl;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > forward, reverse;
		vector<int> indegree;
		indegree.resize(n);
		forward.resize(n);
		reverse.resize(n, 0);
		for (int i = 0; i < n; i++) {
			int d;
			cin >> d;
			for (int j = 0; j < d; j++) {
				int temp;
				cin >> temp;
				temp--;
				forward[i].push_back(temp);
				reverse[temp].push_back(i);
				indegree[i]++;
			}
		}
		int required[n];
		memset(required, 0, sizeof(required));
		for (int i = 0; i < m; i++) {
			int temp;
			cin >> temp;
			temp--;
			dfs(temp, forward);
		}
		kahns(reverse, indegree, n);
	}
	return 0;
}
