/*
ID: ngrj931
PROG: sort3 
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int n;
int arr[1000];

int main(){
	ofstream fout("sort3.out");
	ifstream fin("sort3.in");
	fin>>n;
	int onecount=0,twocount=0,threecount=0;
	for(int i=0;i<n;i++){
		fin>>arr[i];
		if(arr[i]==1)
			onecount++;
		else if(arr[i]==2)
			twocount++;
		else
			threecount++;
	}
	int count_array[6]={0};
	for(int i=0;i<n;i++){
		if(i<onecount){
			if(arr[i]==2)
				count_array[0]++;
			else if(arr[i]==3)
				count_array[1]++;
		}
		else if(i<onecount+twocount){
			if(arr[i]==1)
				count_array[2]++;
			else if(arr[i]==3)
				count_array[3]++;
		}
		else{
			if(arr[i]==1)
				count_array[4]++;
			else if(arr[i]==2)
				count_array[5]++;
		}
	}
	int minswap=0;
	minswap+=min(count_array[0],count_array[2]);
	count_array[0]-=minswap;
	count_array[2]-=minswap;
	int temp=min(count_array[1],count_array[4]);
	count_array[1]-=temp;
	count_array[4]-=temp;
	minswap+=temp;
	temp=min(count_array[3],count_array[5]);
	count_array[5]-=temp;
	count_array[3]-=temp;
	minswap+=temp;
	int rem=count_array[0]+count_array[1]+count_array[2]+count_array[3]+count_array[4]+count_array[5];
	minswap+=rem/3*2+rem%3;
	fout<<minswap<<endl;
	return 0;
}

