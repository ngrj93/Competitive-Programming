#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		char s1[100001], s2[100001];
		scanf(" %s", s1);
		scanf("%s", s2);
		char temp[200001] = "\0"; 
		strcat(temp, s1);
		strcat(temp, s1);
		if (strstr(temp, s2) != NULL) 
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

