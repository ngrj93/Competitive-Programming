/*
ID: ngrj931
PROG: preface
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<map>
using namespace std;

int n;
int roman_count[7];
map<char,int> mp;

void solve(){
	mp['I']=mp['V']=mp['X']=mp['L']=mp['C']=mp['D']=mp['M']=0;
	for(int j=1;j<=n;j++){
		int q=j;
		string roman="";
		while(q>=1000){
			roman+='M';
			q-=1000;
		}
		if(q>=900){
			roman+="CM";
			q-=900;
		}
		if(q>=500){
			roman+='D';
			q-=500;
		}
		if(q>=400){
			roman+="CD";
			q-=400;
		}
		while(q>=100){
			roman+='C';
			q-=100;
		}
		if(q>=90){
			roman+="XC";
			q-=90;
		}
		if(q>=50){
			roman+='L';
			q-=50;
		}
		if(q>=40){
			roman+="XL";
			q-=40;
		}
		while(q>=10){
			roman+='X';
			q-=10;
		}
		if(q==9){
			roman+="IX";
			q-=9;
		}
		if(q>=5){
			roman+="V";
			q-=5;
		}
		if(q==4){
			roman+="IV";
			q-=4;
		}
		while(q>0){
			roman+='I';
			q--;
		}
		cout<<roman<<endl;
		for(int i=0;i<roman.length();i++)
			mp[roman[i]]++;	
	}
}

int main(){
	ofstream fout("preface.out");
	ifstream fin("preface.in");
	fin>>n;
	solve();
	bool flag=false;
	string str="";
	if(mp['M']){
		flag=true;
		str="M "+to_string(mp['M'])+'\n'+str;
	}
	if(mp['D']||flag){
		flag=true;
		str="D "+to_string(mp['D'])+'\n'+str;
	}
	if(mp['C']||flag){
		flag=true;
		str="C "+to_string(mp['C'])+'\n'+str;
	}
	if(mp['L']||flag){
		flag=true;
		str="L "+to_string(mp['L'])+'\n'+str;
	}
	if(mp['X']||flag){
		flag=true;
		str="X "+to_string(mp['X'])+'\n'+str;
	}
	if(mp['V']||flag){
		flag=true;
		str="V "+to_string(mp['V'])+'\n'+str;
	}
	if(mp['I']||flag){
		flag=true;
		str="I "+to_string(mp['I'])+'\n'+str;
	}
	fout<<str;
	return 0;
}
