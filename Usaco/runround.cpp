/*
ID: ngrj931
PROG: runround
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

unsigned long long n;
ofstream fout("runround.out");

int num_of_digits(int num){
	int c=0;
	while(num>0){
		num/=10;
		c++;
	}
	return c;
}

unsigned long long solve(){
	unsigned long long current=n+1;
	bool flag=false;
	while(current<pow(10,9)){
		int digits=num_of_digits(current);
		int max_l=pow(10,digits);
		for(;current<max_l;current++){
			bool visited[9]={0};
			bool num_visited[10]={0};
			string str=to_string(current);
			int count_l=0,i=0;
			while(count_l<digits){
				if(str[i]=='0')
					break;
				if(visited[i]==true||num_visited[str[i]-'0']==true)
					break;
				else{
					visited[i]=true;
					int temp=str[i]-'0';
					num_visited[temp]=true;
					i=(i+temp)%digits;
					count_l++;
				}
			}	
			if(count_l==digits && i==0){
				fout<<str<<endl;
				flag=true;
				break;
			}
		}
		if(flag)
			break;
	}
}
		
int main(){
	ifstream fin("runround.in");
	fin>>n;
	solve();
	return 0;
}

