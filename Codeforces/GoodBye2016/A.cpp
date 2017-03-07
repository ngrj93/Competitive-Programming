#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int diff = 240 - k;
	int count = 0;
	for (int i = 1; i <=n; i++) {
		if (i * 5 <= diff) {
			count++;
			diff -= i * 5;
		}
	}
	cout << count << endl;
	return 0;
}
