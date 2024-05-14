//CREDIT TO BORNAG & TARPENT
#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+7;

int n, m, k;
vector<pair<int, int>> graph[maxn];
unordered_map<string, bool> sen;

int visited[maxn];
bool done[maxn];
int hasparent[maxn];

bool dfs(int node, int time, int depth){
	visited[node] = depth;
	
	if(depth >= k-1) return true;
	
	for(auto x : graph[node]){
		if(x.second <= time and visited[x.first] < depth+1){
			if(dfs(x.first, time, depth+1)) return true;
		}
	}
	
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++) hasparent[i] = INT_MAX;
	
	for(int i = 0; i < m; i++){
		int ai, bi; cin >> ai >> bi; ai--; bi--;
		string ind = to_string(ai) + " --- " + to_string(bi);

		if(!sen[ind]) graph[ai].push_back({bi, i});
		hasparent[bi] = min(hasparent[bi], i);
		sen[ind] = true;
	}
	
	int lo = 0;
	int hi = m;
	
	while(lo < hi){
		int mid = (lo+hi)/2;
		
		for(int i = 0; i < n; i++) visited[i] = 0;
		
		bool possibl = false;
		
		for(int i = 0; i < n; i++){
			bool pos = (hasparent[i] > mid);
			
			if(pos){
				bool s = dfs(i, mid, 0);
				
				if(s) possibl = true;
			}
		}
		
		if(possibl){
			done[mid] = true;
			hi = mid;
		} else {
			lo = mid+1;
		}
	}
	
	if(!done[lo]) cout << -1;
	else cout << lo+1;
}
