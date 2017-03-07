/*
ID: ngrj931
PROG: dualpal
LANG: C++11
*/

#include<fstream>
#include<climits>
using namespace std;

char digits[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I'};

string convert(int num,int base){
	string return_val="";
	while(num>0){
		int rem=num%base;
		return_val=digits[rem]+return_val;
		num/=base;
	}
	if(return_val[0]=='0')
		return_val=return_val.substr(1);
	return return_val;
}

bool ispalindrome(string s){
	for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
		if(s[i]!=s[j])
			return false;
	}
	return true;
}

int main(){
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	unsigned int n,s,count=0;
	fin>>n>>s;
	for(unsigned int i=s+1;i<=UINT_MAX;i++){
		int temp_count=0;
		for(int j=2;j<=10;j++){
			string base_val=convert(i,j);
			if(ispalindrome(base_val))
				temp_count++;
			if(temp_count>=2){
				fout<<i<<endl;
				count++;
				break;
			}
		}
		if(count==n)
			break;
	}
	return 0;
}
