/*
ID: ngrj931
PROG: ride
LANG: C++11
*/

#include<fstream>
using namespace std;

int main(){
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	string comet,group;
	fin>>comet>>group;
	int comet_product=1,group_product=1;
	for(int i=0;i<comet.size();i++)
		comet_product*=comet[i]-64;
	for(int i=0;i<group.size();i++)
		group_product*=group[i]-64;
	if(comet_product%47==group_product%47)
		fout<<"GO"<<endl;
	else
		fout<<"STAY"<<endl;
	return 0;
}
