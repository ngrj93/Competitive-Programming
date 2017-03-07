#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <string.h>
#include <map>
#include <cctype>
#include <list>
#include <stack>
 
 using namespace std;
 typedef long long ll;
#define INF 0x3f3f3f3f
#define LOCAL
 const int maxn = 5007;
 int dp[maxn][maxn];
 int path[maxn][maxn];
 vector<int> edge[maxn];
 vector<int> cost[maxn];
 int n, m;
 int T;
  
	int calc(int i, int j){
			if( dp[i][j] != -1){
						return dp[i][j];
							}
								else{
											dp[i][j] = INF;
													for(int index = 0; index < edge[i].size(); index++){
																	int value = calc(edge[i][index], j-1)+cost[i][index];
																				if( value < dp[i][j]){
																									dp[i][j] = value;
																													path[i][j] = edge[i][index];
																																}
																																		}
																																				return dp[i][j];
																																					}
	}
	 
	 int main(int argc, char ** argv)
	 {
#ifdef LOCAL
		 	freopen("/Users/yuyue/build/data.txt", "r", stdin);
				// freopen("/Users/yuyue/build/out.txt", "w", stdout);
#endif
					cin >> n >> m >> T;
						memset(dp, -1, sizeof(int)*maxn*maxn);
							dp[1][1] = 0;
								int u, v, time;
									int ans = 0;
										for(int i= 1; i <= m; i++){
													cin >> v >> u >> time;
															edge[u].push_back(v);
																	cost[u].push_back(time);
																		}
																			for(int i = n; i >= 1; i--){
																						if(calc(n, i) <= T){
																										ans = i;
																													break;
																															}
																																}
																																	printf("%d\n", ans);
																																		vector<int> final_path;
																																			final_path.push_back(n);	
																																				int now = n;
																																					while (ans>1){
																																								final_path.push_back(path[now][ans]);
																																										now =path[now][ans];
																																												ans--;
																																													}
																																														for(int i = final_path.size()-1; i > 0; i--)
																																																	printf("%d ", final_path[i]);
																																																	 
																																																	 	printf("%d\n", final_path[0]);
																																																			return 0;
	 }
