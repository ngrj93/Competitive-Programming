/*
ID: ngrj931
PROG: ariprog
LANG: C++11
*/

#include<fstream>
#include<iostream>

using namespace std;

bool arr[1000000];
ofstream fout("ariprog.out");

void generate(int m){
	for(int i=0;i<=m;i++)
		for(int j=i;j<=m;j++)
			arr[i*i + j*j]=true;
}

void search(int n,int m,int last){
	bool flag=true;
	int length=1,lenmax=last/(n-1);
	while(length<=lenmax){
		int lmax=last-length;
		for(int i=0;i<=lmax;i++){
			if(arr[i] && arr[i+(n-1)*length]){
				int current=i,count=1;
				while(count<n){
					if(arr[current+count*length])
						count++;
					else
						break;
				}
				if(count==n){
					flag=false;
					fout<<i<<" "<<length<<endl;
				}
			}
		}
		length++;
	}
	if(flag)
		fout<<"NONE"<<endl;
}	

int main(){
	ifstream fin("ariprog.in");
	int n,m;
	fin>>n>>m;
	int last=m*m+m*m;
	generate(m);
	search(n,m,last);
	return 0;
}
