#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int input[n], dp[n];
	int index[k - 1][n + 1];
	for (int i = 0; i < n; i++)
		cin >> input[i];
	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j < n; j++) { 
			int temp;
			cin >> temp;
			index[i][temp] = j;
		}
	}
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			bool flag = false;
			for (int l = 0; l < k - 1; l++) {
				if (index[l][input[i]] < index[l][input[j]]) {
					flag = true;
					break;
				}
			}
			dp[i] = flag ? dp[i] : max(dp[i], dp[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}
