#include<iostream>
#include<cmath>
using namespace std;

int input[]={137,1315,73,136,255,1384,16385};

string string_expand(int num){
	if(num==0)
		return "";
	else if(num==1)
		return "2(0)";
	else if(num==2)
		return "2";
	else if(num==3)
		return "2+2(0)";
	else{
		int p=log2(num);
		int rem=num-pow(2,p);
		string ans;
		if(rem)
			ans="2("+string_expand(p)+")+"+string_expand(rem);
		else
			ans="2("+string_expand(p)+")";
		return ans;
	}
}

int main(){
	for(int i=0;i<7;i++)
		cout<<input[i]<<"="<<string_expand(input[i])<<endl;
	return 0;
}


