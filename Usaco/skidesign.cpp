/*
ID: ngrj931
PROB: skidesign
LANG: C++11
*/

#include<fstream>
#include<algorithm>
#include<iostream>
#include<climits>

using namespace std;

int main(){
	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");
	int n;
	fin>>n;
	int height[n];
	int minsum=INT_MAX;
	for(int i=0;i<n;i++)
		fin>>height[i];
	sort(height,height+n);
	int diff=height[n-1]-height[0];
	if(diff>17){
		int leftindex=height[0],rightindex=height[0]+17;
		while(rightindex<=height[n-1]){
			int cursum=0;
			for(int i=n-1;i>=0;i--){
				if(height[i]>rightindex)
					cursum+=(height[i]-rightindex)*(height[i]-rightindex);
				else 
					break;
			}
			for(int i=0;i<n;i++){
				if(height[i]<leftindex)
					cursum+=(height[i]-leftindex)*(height[i]-leftindex);
				else
					break;
			}
			minsum=minsum>cursum?cursum:minsum;
			rightindex++;
			leftindex++;
		}
		fout<<minsum<<endl;
	}
	else
		fout<<0<<endl;
	return 0;
}
