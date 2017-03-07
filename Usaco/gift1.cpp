/*
ID: ngrj931
PROG: gift1 
LANG: C++11
*/
#include<fstream>
#include<cstring>
using namespace std;

int main(){
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	int n;
	fin>>n;
	string name[n];
	int final_amount[n];
	fin.ignore();
	memset(final_amount,0,sizeof(final_amount));
	for(int i=0;i<n;i++)
		fin>>name[i];
	for(int i=0;i<n;i++){
		string curr_name;
		int initial_amount,count;
		fin>>curr_name>>initial_amount>>count;
		if(count!=0){
			for(int j=0;j<n;j++){
				if(curr_name==name[j]){
					final_amount[j]+=initial_amount%count-initial_amount;
					break;
				}
			}
			fin.ignore();
			for(int j=0;j<count;j++){
				string tempname;
				fin>>tempname;
				for(int k=0;k<n;k++){
					if(name[k]==tempname){
						final_amount[k]+=(initial_amount-initial_amount%count)/count;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++)
		fout<<name[i]<<" "<<final_amount[i]<<endl;
	return 0;
}

