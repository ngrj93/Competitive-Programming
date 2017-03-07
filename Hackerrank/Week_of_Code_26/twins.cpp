#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main () {
	int m, n;
	cin >> m >> n;
	int sieve_size = n - m + 1, root = sqrt (n), ans = 0;
	bool sieve[sieve_size];
	memset (sieve, 0, sizeof (sieve));
	if (m == 0) 
		sieve[0] = sieve[1] = true;
	else if (m == 1)
		sieve[0] = true;
	for (int i = 2; i <= root; i++) {
		int curr = ceil ((double) m / i) * i - m;
		if (m + curr != i)
			sieve[curr] = true;
		for (int j = curr + i; j < sieve_size; j += i) 
			sieve[j] = true;
	}
	for (int i = 0; i < sieve_size - 2; i++) {
		if (!sieve[i] && !sieve[i + 2])
			ans++;
	}
	cout << ans << endl;
	return 0;
}
