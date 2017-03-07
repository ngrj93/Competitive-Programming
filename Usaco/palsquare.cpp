/*
ID: ngrj931
PROG: palsquare
LANG: C++11
*/

#include<fstream>
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
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	int n,num;
	fin>>n;
	for(int i=1;i<=300;i++){
		num=i*i;
		string base_val=convert(num,n);
		if(ispalindrome(base_val))
			fout<<convert(i,n)<<" "<<base_val<<endl;
	}
	return 0;
}
