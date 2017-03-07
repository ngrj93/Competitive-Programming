/*
ID: ngrj931
PROG: namenum
LANG: C++11
*/

#include<fstream>
#include<algorithm>
using namespace std;

string dictionary[5000];
int count_dict;
ofstream fout("namenum.out");
ifstream fin("namenum.in");
int total;

char character[10][3]={	{'\0','\0','\0'},
								{'\0','\0','\0'},
								{'A','B','C'},
								{'D','E','F'},
								{'G','H','I'},
								{'J','K','L'},
								{'M','N','O'},
								{'P','R','S'},
								{'T','U','V'},
								{'W','X','Y'}	};	

void print_valid_names(string s,int i,string name){
	if(i==s.size()){
		if(binary_search(dictionary,dictionary+5000,name)){
			fout<<name<<endl;
			total++;
		}
	}
	else{
		int current=s[i]-48;
		for(int j=0;j<3;j++){
			name[i]=character[current][j];
			print_valid_names(s,i+1,name);
		}
	}
}
		
int main(){
	string s;
	ifstream fin2("dict.txt");
	fin>>s;
	while(fin2>>dictionary[count_dict++]);
	string name(s.size(),'\0');
	print_valid_names(s,0,name);
	if(!total)
		fout<<"NONE"<<endl;
	return 0;
}
