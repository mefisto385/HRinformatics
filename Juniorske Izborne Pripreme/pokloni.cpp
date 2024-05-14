//CREDITS TO BORNAG TARPENT
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+7;

int n, m, x;
int dp[maxn][maxn];
int bp[maxn];
int d[maxn];
int p[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> x;
	
	for(int i = 0; i < n; i++)
		cin >> d[i];
		
	for(int i = 0; i < m; i++)
		cin >> p[i];

	int sa = INT_MAX;
	for(int j = 0; j < n; j++){
		if(p[0] <= d[j]) dp[1][j] = abs(x-(j+1))+1;
		else dp[1][j] = INT_MAX;
		
		if(sa < INT_MAX) sa++;
		
		if(p[1] <= d[j]){
			bp[j] = sa;
		} else bp[j] = INT_MAX;
		
		if(p[0] <= d[j]){
			sa = min(sa, dp[1][j]);
		}
	}
	
	sa = INT_MAX;
	for(int j = n-1; j >= 0; j--){
		if(sa < INT_MAX) sa++;
		
		if(p[1] <= d[j]){
			bp[j] = min(sa, bp[j]);
		}
		
		if(p[0] <= d[j]){
			sa = min(sa, dp[1][j]);
		}
	}
	
	for(int i = 2; i < m; i++){
		sa = INT_MAX;
		for(int j = 0; j < n; j++){
			if(bp[j] < INT_MAX) dp[i][j] = bp[j]+1;
			else dp[i][j] = INT_MAX;
			
			if(sa < INT_MAX) sa++;
			
			if(p[i] <= d[j]) bp[j] = sa;
			else bp[j] = INT_MAX;
			
			if(p[i-1] <= d[j]) sa = min(sa, dp[i][j]);
		}
		
		sa = INT_MAX;
		for(int j = n-1; j >= 0; j--){
			if(sa < INT_MAX) sa++;
			
			if(p[i] <= d[j]) bp[j] = min(sa, bp[j]);
			if(p[i-1] <= d[j]) sa = min(sa, dp[i][j]);
		}
	}
	
	int sol = INT_MAX;
	
	for(int i = 0; i < n; i++) sol = min(sol, bp[i]);
	
	cout << sol+1 << '\n';
}
