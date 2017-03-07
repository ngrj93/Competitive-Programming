/*
ID: ngrj931
PROG: sprime
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;


ofstream fout("sprime.out");
int n;
int num[8];
bool prime[1000000];

void generate_prime(){
	for(int i=2;i<1000000;i++){
		if(!prime[i]){
			for(int j=i+i;j<1000000;j+=i)
				prime[j]=true;
		}
	}
}

bool is_prime(int cur){
	int val=0;
	for(int i=0;i<=cur;i++)
		val=val*10+num[i];
	int max=sqrt(val);
	for(int i=2;i<=max;i++){
		if(!prime[i] && !(val%i))
			return false;
	}
	return true;
}

void check_superprime(int cur){
	if(cur==n){
		for(int i=0;i<n;i++)
			fout<<num[i];
		fout<<endl;
		return;
	}
	if(cur==0){
		for(int i=2;i<=9;i++){
			if(!prime[i]){
				num[cur]=i;
				check_superprime(cur+1);
			}
		}
	}
	else if(cur<n && cur<6){
		for(int i=1;i<=9;i++){
			num[cur]=i;
			int val=0;
			for(int j=0;j<=cur;j++)
				val=val*10+num[j];
			if(!prime[val])
				check_superprime(cur+1);
		}
	}
	else{
		for(int i=1;i<=9;i++){
			num[cur]=i;
			if(is_prime(cur))
				check_superprime(cur+1);
		}
	}
}		
				
int main(){
	ifstream fin("sprime.in");
	fin>>n;
	generate_prime();
	check_superprime(0);
	return 0;
}
	
