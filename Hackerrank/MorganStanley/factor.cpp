#include<iostream>
#include<map>
#include<cmath>
#define MAX 1000001
using namespace std;

long long n;
bool arr[MAX];
map<int,int> primes;

void primenum(){
	for(int i=4;i<MAX;i+=2)
		arr[i]=true;
	for(int i=3;i<MAX;i+=2){
		if(arr[i]==false){
			for(int j=i+i;j<MAX;j+=i)
				arr[j]=true;
		}
	}
}

void solve(){
	int div1=1,div2=1;
	for(map<int,int>::iterator it=primes.begin();it!=primes.end();it++){
		div1*=it->second+1;
		div2*=it->second*2+1;
	}
	div2=(div2-1)/2;
	div1-=1;
	cout<<div2-div1<<endl;
}

void generate_primes(){
	long long num=n;
	while(!(num%2)){
		if(!primes.count(2))
			primes.insert(make_pair(2,1));
		else
			primes[2]=primes[2]+1;
		num/=2;
	}
	int i=3;
	while(i<MAX && num!=1){
		if(arr[i]==false){
			while(!(num%i)){
				if(!primes.count(i))
					primes.insert(make_pair(i,1));
				else
					primes[i]=primes[i]+1;
				num/=i;
			}
		}
		i+=2;
	}
	if(num!=1)
		primes[num]=1;
}

int main(){
	cin>>n;
	arr[0]=arr[1]=true;
	primenum();
	generate_primes();
	solve();
	return 0;
}



