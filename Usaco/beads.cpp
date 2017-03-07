/*
ID: ngrj931
PROB: beads
LANG: C++11
*/

#include<fstream>
using namespace std;

int main(){
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	int n;
	fin>>n;
	string str;
	fin.ignore();
	fin>>str;
	string input=str+str+str;
	int best=0;
	for(int i=n;i<2*n;i++){
		int left=1,right=1;
		char lbead=input[i-1],rbead=input[i];
		for(int j=i-2;j>i-n;j--){
			if(input[j]!='w' && lbead=='w')
				lbead=input[j];
			if(input[j]!='w' && input[j]!=lbead)
				break;
			left++;
		}
		for(int j=i+1;j<i+n;j++){
			if(input[j]!='w' && rbead=='w')
				rbead=input[j];
			if(input[j]!='w' && input[j]!=rbead)
				break;
			right++;
		}
		best=best>left+right?best:left+right;
	}
	if(best>n)
		fout<<n<<endl;
	else
		fout<<best<<endl;
	return 0;
}