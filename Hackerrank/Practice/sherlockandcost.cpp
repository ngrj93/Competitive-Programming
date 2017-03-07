#include <iostream>
#include <cmath>
#define MAX 100001
using namespace std;

int dp[MAX][2];

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr_b[n + 1];
		for (int i = 1; i <= n; i++) 
			cin >> arr_b[i];
		for (int i = 2; i <= n; i++) {
			dp[i][0] = dp[i - 1][1] + abs (arr_b[i - 1] - 1);
			dp[i][1] = max (dp[i - 1][0] + abs (arr_b[i] - 1), dp[i - 1][1] + abs (arr_b[i] - arr_b[i - 1]));
		}
		cout << max (dp[n][0], dp[n][1]) << endl;
	}
	return 0;
}
			
