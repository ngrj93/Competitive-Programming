#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	n--;
	int change, div;
	cin >> change >> div;
	vector<int> greater, lesser;
	if (div == 1)
		greater.push_back(1900);
	else
		lesser.push_back(1899);
	int temp = change;
	while (n--) {
		int p_div = div;
		cin >> change >> div;
		if (div == 1)
			greater.push_back(1900 - temp);
		else
			lesser.push_back(1899 - temp);
		temp += change;
	}
	vector<int>::iterator max_v = max_element(greater.begin(), greater.end());
	vector<int>::iterator min_v = min_element(lesser.begin(), lesser.end());
	if (min_v == lesser.end())
		cout << "Infinity" << endl;
	else if (max_v == greater.end())
		cout << *min_v + temp << endl;
	else if (*max_v <= *min_v) 
		cout << *min_v + temp << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}

