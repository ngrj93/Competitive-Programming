#include<cstdio>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t){
		int n,m;
		scanf("%d%d",&n,&m);
		while(t--){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x<n){
				if(y>m)
					printf("NO\n");
				else if(y<m)
					printf("SO\n");
				else
					printf("divisa\n");
			}
			else if(x>n){
				if(y>m)
					printf("NE\n");
				else if(y<m)
					printf("SE\n");
				else
					printf("divisa\n");
			}
			else
				printf("divisa\n");
		}
		scanf("%d",&t);
	}
	return 0;
}
	
