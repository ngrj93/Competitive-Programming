/*
ID: ngrj931
PROG: crypt1
LANG: C++11
*/

#include<fstream>
#include<algorithm>
using namespace std;

int countt,multiply[5];

bool check_digits(int val,int num){
	int temp=0;
	while(val>0){
		val/=10;
		temp++;
	}
	if(temp==num)
		return true;
	return false;
}

bool contains_digits(int val,int digit[],int n){
	while(val>0){
		int rem=val%10;
		if(!binary_search(digit,digit+n,rem))
			return false;
		val/=10;
	}
	return true;
}

bool multiplication(int digit[],int n){
	int multiplicand=100*multiply[0]+10*multiply[1]+multiply[2];
	int multiplier=10*multiply[3]+multiply[4];
	if(check_digits(multiplicand*multiply[3],3) && check_digits(multiplicand*multiply[4],3) && check_digits(multiplicand*multiplier,4)){
		if(contains_digits(multiplicand*multiply[3],digit,n) && contains_digits(multiplicand*multiply[4],digit,n) && contains_digits(multiplicand*multiplier,digit,n))
			countt++;
	}
	else
		return false;
	return true;
}

void generate_combinations(int digit[],int n,int cur){
	for(int i=0;i<n;i++){
		multiply[cur]=digit[i];
		if(cur==4){
			bool cont=multiplication(digit,n);
			if(!cont)
				break;
		}
		else
			generate_combinations(digit,n,cur+1);
	}
}


int main(){
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");
	int n;
	fin>>n;
	int digit[n];
	for(int i=0;i<n;i++)
		fin>>digit[i];
	sort(digit,digit+n);
	generate_combinations(digit,n,0);
	fout<<countt<<endl;
	return 0;
}
