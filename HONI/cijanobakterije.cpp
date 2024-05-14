#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+7;

int n, m;
int dists[maxn];
int dists2[maxn];
//int parents[maxn];

vector<int> roads[maxn];
vector<int> roads2[maxn];

/*int qParent(){
	
}

void connect(int a, int b){
	int x = qParent(a);
	int y = qParent(b);
}*/

pair<int, int> dfs(int a, int distance){
	if (dists[a] > 0) return {-1, -1};
	dists[a] = distance;
	int ret = 0;
	int pos = 0;
	
	//cout << a << ' ' << distance << '\n';
	
	int s = roads[a].size();
	int truecounter = 0;
	while(truecounter < s){
		truecounter++;
		int el = roads[a][truecounter-1];
		
		if(dists[el] == -1){
			pair<int, int> x = dfs(el, distance+1);
			if(x.first > ret){
				ret = x.first;
				pos = x.second;
			}
		} else if(dists[el] == -1){
			pair<int, int> x = dfs(el, distance+1);
			if(x.first > ret){
				ret = x.first;
				pos = x.second;
			}
		}
	}
	
	pair<int, int> coma = {dists[a], a};
	pair<int, int> comb = {ret, pos};
	if(dists[a] >= ret) return coma;
	else return comb;
}

pair<int, int> dfs2(int a, int distance){
	if (dists2[a] > 0) return {-1, -1};
	dists2[a] = distance;
	int ret = -1;
	int pos = -1;
	
	//cout << a << ' ' << distance << '\n';
	
	int s = roads2[a].size();
	int truecounter = 0;
	while(truecounter < s){
		truecounter++;
		int el = roads2[a][truecounter-1];
		
		if(dists2[el] == -1){
			pair<int, int> x = dfs2(el, distance+1);
			if(x.first > ret){
				ret = x.first;
				pos = x.second;
			}
		} else if(dists2[el] == -1){
			pair<int, int> x = dfs2(el, distance+1);
			if(x.first > ret){
				ret = x.first;
				pos = x.second;
			}
		} 
	}
	
	pair<int, int> coma = {dists2[a], a};
	pair<int, int> comb = {ret, pos};
	if(dists2[a] >= ret) return coma;
	else return comb;
}

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; a--; b--;
		roads[a].push_back(b);
		roads[b].push_back(a);
		roads2[a].push_back(b);
		roads2[b].push_back(a);
	}
	
	for(int i = 0; i < n; i++){
		dists[i] = -1; dists2[i] = -1;
	}


	int sol = 0;
	for(int i = 0; i < n; i++){
		if(dists[i] == -1){
			pair<int, int> s = dfs(i, 1);
			
			pair<int, int> x = dfs2(s.second, 1);

			sol+=max(x.first, 0);
		}
	}
	
	cout << sol;
}