/*
ID: ngrj931
PROG: pprime
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

bool prime[10001];
int palin[8];
int a,b;
ofstream fout("pprime.out");

void generate_prime(){
	for(int i=2;i<=10000;i++){
		if(!prime[i]){
			for(int j=i+i;j<=10000;j+=i)
				prime[j]=true;
		}
	}
}

int num_of_digits(int num){
	int c=0;
	while(num>0){
		num/=10;
		c++;
	}
	return c;
}

int convert_to_num(int length){
	int num=0;
	for(int i=0;i<length;i++)
		num=num*10+palin[i];
	return num;
}

void check_prime(int length){
	int val=convert_to_num(length);
	int max=sqrt(val);
	for(int i=2;i<=max;i++){
		if(!prime[i] && !(val%i))
			return;
	}
	if(val>=a && val<=b)
		fout<<val<<endl;
}

void palindrome_generate(int length,int cur){
	if(cur==length-1-cur){
		for(int i=0;i<=9;i++){
			palin[cur]=i;
			check_prime(length);
		}
		return;
	}
	if(cur>length-1-cur){
		check_prime(length);
		return;
	}
	if(cur==0){
		for(int i=1;i<=9;i++){
			palin[cur]=palin[length-1-cur]=i;
			palindrome_generate(length,cur+1);
		}
	}
	else{
		for(int i=0;i<=9;i++){
			palin[cur]=palin[length-1-cur]=i;
			palindrome_generate(length,cur+1);
		}
	}
}
		

int main(){
	ifstream fin("pprime.in");
	fin>>a>>b;
	generate_prime();
	int l=num_of_digits(a),r=num_of_digits(b);
	r=r>8?8:r;
	for(int i=l;i<=r;i++)
		palindrome_generate(i,0);
	return 0;
}
