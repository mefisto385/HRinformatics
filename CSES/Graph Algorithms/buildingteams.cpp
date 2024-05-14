#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5+7;
 
int n, m;
vector<int> gph[maxn];;
int vis[maxn];
 
void dfs(int node, int c){
	vis[node] = c;
	
	if(c == 1) c = 2;
	else c = 1;
	for(auto nex : gph[node]){
		if(!vis[nex])
			dfs(nex, c);
	}
}
 
int main(){
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; a--; b--;
		
		gph[a].push_back(b);
		gph[b].push_back(a);
	}
	
	vector<int> componentMain;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			componentMain.push_back(i);
			dfs(i, 1);
		}
	}
	
	bool wrong = false;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < gph[i].size(); j++){
			if(vis[gph[i][j]] == vis[i]) wrong = true;
		}
	}
	
	if(wrong) cout << "IMPOSSIBLE";
	else{
		for(int i = 0; i < n; i++){
			cout << vis[i] << ' ';
		}
	}
}
