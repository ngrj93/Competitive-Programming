/*
ID: ngrj931
PROG: friday
LANG: C++11
*/

#include<fstream>
using namespace std;

int main(){
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	int n;
	fin>>n;
	int year=1900,month=1,day=-1;
	int frequency[7]={0};
	while(year<=1900+n-1){
		switch(month){
			case 1:	day=(day+13)%7;
					frequency[day]++;
					day=(day+18)%7;
					month++;
					break;	
			case 2:	day=(day+13)%7;
					frequency[day]++;
					if(!(year%400) || (!(year%4) && year%100))
						day=(day+16)%7;
					else
						day=(day+15)%7;
					month++;
					break;	
			case 3:	day=(day+13)%7;
					frequency[day]++;
					day=(day+18)%7;
					month++;
					break;	
			case 4:	day=(day+13)%7;
					frequency[day]++;
					day=(day+17)%7;
					month++;
					break;	
			case 5:	day=(day+13)%7;
					frequency[day]++;
					day=(day+18)%7;
					month++;
					break;	
			case 6:	day=(day+13)%7;
					frequency[day]++;
					day=(day+17)%7;
					month++;
					break;	
			case 7:	day=(day+13)%7;
					frequency[day]++;
					day=(day+18)%7;
					month++;
					break;	
			case 8: day=(day+13)%7;
					frequency[day]++;
					day=(day+18)%7;
					month++;
					break;	
			case 9:	day=(day+13)%7;
					frequency[day]++;
					day=(day+17)%7;
					month++;
					break;	
			case 10:	day=(day+13)%7;
						frequency[day]++;
						day=(day+18)%7;
						month++;
						break;	
			case 11:	day=(day+13)%7;
						frequency[day]++;
						day=(day+17)%7;
						month++;
						break;	
			case 12:	day=(day+13)%7;
						frequency[day]++;
						day=(day+18)%7;
						month=1;
						year++;
						break;	
		}
	}
	for(int i=5;i<7;i++)
		fout<<frequency[i]<<" ";
	for(int i=0;i<4;i++)
		fout<<frequency[i]<<" ";
	fout<<frequency[4];
	fout<<endl;
	return 0;
}