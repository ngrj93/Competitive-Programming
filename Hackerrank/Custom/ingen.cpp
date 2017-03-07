#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
	srand(time(NULL));
	int t = atoi(argv[1]);
	cout << t << endl;
	int len = atoi(argv[2]);
	for (int i = 0; i < t; i++) {
		string s1;
		for (int j = 0; j < len; j++) 
			s1 = s1 + (char)(rand() % 26 + 'a');
		cout << s1 << endl;
		string s2;
		int way = rand() % 2;
		if (way) {
			int start = rand() % len;
			s2 = s2 + s1[start];
			for (int j = (start + 1) % len; j != start; j = (j + 1) % len) 
				s2 = s2 + s1[j];
		}
		else {
			for (int j = 0; j < len; j++) 
				s2 = s2 + (char)(rand()%26 + 'a');
		}
		cout << s2 << endl;
	}
	return 0;
}
					
		
