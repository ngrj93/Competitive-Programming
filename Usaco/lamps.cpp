/*
ID: ngrj931
PROG: lamps
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<set>
using namespace std;

int n,c;
int finalr[101];
int initial[101];
set<string> ans;

bool check(){
	for(int i=1;i<=n;i++){
		if(initial[i]==1 && finalr[i]==0)
			return false;
		else if(initial[i]==0 && finalr[i]==1)
			return false;
	}
	return true;
}

void press_button(int val){
	switch(val){
		case 1:	for(int i=1;i<=n;i++){
							if(initial[i]==1)
								initial[i]=0;
							else
								initial[i]=1;
						}
						break;
		case 2:	for(int i=1;i<=n;i+=2){
							if(initial[i]==1)
								initial[i]=0;
							else
								initial[i]=1;
						}
						break;
		case 3: for(int i=2;i<=n;i+=2){
							if(initial[i]==1)
								initial[i]=0;
							else
								initial[i]=1;
						}
						break;
		case 4: for(int i=1,k=0;i<=n;k+=1,i=k*3+1){
							if(initial[i]==1)
								initial[i]=0;
							else
								initial[i]=1;
						}
						break;
	}
}

void generate_configuration(int cur){
	if(cur==c||cur==4){
		if(check()){
			string str="";
			for(int i=1;i<=n;i++)
				str+=to_string(initial[i]);
			ans.insert(str);
		}
		return;
	}
	for(int i=1;i<=4;i++){
		press_button(i);
		generate_configuration(cur+1);
		press_button(i);
	}
}

int main(){
	ofstream fout("lamps.out");
	ifstream fin("lamps.in");
	fin>>n>>c;
	for(int i=0;i<101;i++){
		finalr[i]=2;
		initial[i]=1;
	}
	int index;
	fin>>index;
	while(index!=-1){
		finalr[index]=1;
		fin>>index;
	}
	fin>>index;
	while(index!=-1){
		finalr[index]=0;
		fin>>index;
	}
	generate_configuration(0);
	if(ans.size()==0)
		fout<<"IMPOSSIBLE"<<endl;
	else{
		for(set<string>::iterator it=ans.begin();it!=ans.end();it++)
			fout<<*it<<endl;
	}
	return 0;
}

