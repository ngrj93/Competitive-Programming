#include<cstdio>
#include<iostream>
#include<cmath>
#define MAX 1000000
using namespace std;

bool primes[MAX];

void PrimeFind(){
	for(int i=2;i<MAX;i++){
		if(!primes[i]){
			for(int j=i+i;j<MAX;j+=i)
				primes[j]=true;
		}
	}
}	

bool IsPrime(int num){
	if(num==1)
		return false;
	int ub=(int)sqrt(num);
	for(int i=2;i<=ub;i++){
		if(!primes[i] && !(num%i))
			return false;
	}
	return true;
} 

void ListPrimes(int m,int n){
	for(int i=m;i<=n;i++){
		if(IsPrime(i))
			printf("%d\n",i);
	}
}

int main(){
	int t;
	cin>>t;
	PrimeFind();
	while(t--){
		int n,m;
		cin>>m>>n;
		ListPrimes(m,n);
		cout<<endl;
	}
	return 0;
}
