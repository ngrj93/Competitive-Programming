/*
ID: ngrj931
PROG: barn1
LANG: C++11
*/

#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int m,s,c;
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
	fin>>m>>s>>c;
	int barn[c];
	for(int i=0;i<c;i++)
		fin>>barn[i];
	sort(barn,barn+c);
	int difference[c-1];
	for(int i=0;i<c-1;i++)
		difference[i]=barn[i+1]-barn[i]-1;
	sort(difference,difference+c-1);
	int count=0;
	for(int i=0;i<c-m;i++)
		count+=difference[i];
	fout<<count+c<<endl;
	return 0;
}
