#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int min_d = 0, max_d = 20000;
	int cur = 0;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		int t;
		string s;
		cin >> t;
		cin.ignore();
		cin >> s;
		if ((s == "East" || s == "West") && (cur == min_d || cur == max_d)) {
			cout << "NO" << endl;
			flag = false;
			break;
		}
		else if (s == "South" and (cur = cur + t) > max_d) {
			cout << "NO" << endl;
			flag = false;
			break;
		}
		else if (s == "North" and (cur = cur - t) < min_d) {
			cout << "NO" << endl;
			flag = false;
			break;
		}
	}
	if (flag && cur != min_d) {
		cout << "NO" << endl;
		flag = false;
	}
	if (flag) 
		cout << "YES" << endl;
	return 0;
}
