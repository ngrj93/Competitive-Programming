#include<cstdio>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int sum=a+b+c;
		int large=(a>b)?((a>c)?a:c):((b>c)?b:c);
		int small=(a<b)?((a<c)?a:c):((b<c)?b:c);
		printf("Case %d: %d\n",i,sum-large-small);
	}
	return 0;
}
