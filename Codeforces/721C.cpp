#include <iostream>
#include <vector>
#include <climits>
#define MAX 5001
using namespace std;

int n, m, t;
vector<vector<pair<int, int> > > adj;
int dp[MAX][MAX];
int pred[MAX][MAX];

long long find_max_showcases(int cur, int num_v) {
	if (dp[cur][num_v] != -1)
		return dp[cur][num_v];
	if (num_v < 1)
		return dp[cur][num_v] = INT_MAX;
	dp[cur][num_v] = INT_MAX;
	for (int i = 0; i < adj[cur].size(); i++) {
		long long ans = find_max_showcases(adj[cur][i].first, num_v - 1);
		if (ans < INT_MAX && (ans + adj[cur][i].second <= t) && (ans + adj[cur][i].second < dp[cur][num_v])) {
			dp[cur][num_v] = ans + adj[cur][i].second;
			pred[cur][num_v] = adj[cur][i].first;
		}
	}
	return dp[cur][num_v];
}

/*void print(int cur) {
	if (pred[cur] == cur)
		cout << cur << " ";
	else {
		print(pred[cur]);
		cout << cur << " ";
	}
}*/
		
int main() {
	cin >> n >> m >> t;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int s, d, ti;
		cin >> s >> d >> ti;
		adj[d].push_back(make_pair(s, ti));
	}
	//pred[1] = 1;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			dp[i][j] = -1;
	dp[1][1] = 0;	
	for (int i = n; i > 0; i--) {
		dp[n][i] = find_max_showcases(n, i);
		if (dp[n][i] <= t) {
			cout << i << endl;
			//print(n);
			vector<int> fin;
			fin.push_back(n);
			int now = n;
			while (i > 1) {
				fin.push_back(pred[now][i]);
				now = pred[now][i];
				i--;
			}
			for (int j = fin.size() - 1; j >= 0; j--)
				cout << fin[j] << " ";
			break;
		}
	}
	cout << endl;
	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i <= n; i++)
		cout << pred[i] << " ";
	cout << endl;*/
	return 0;
}

	

		
