#include <bits/stdc++.h>
using namespace std;

const int maxn = 107;

char vrata[maxn][maxn][maxn][maxn];
int n, m, q;

int dists[maxn][maxn];

int runSolver(int ai, int bi, int ci, int di, int blue, int green, int yellow, int red){
	queue<pair<int, int>> q;
	q.push({ai, bi});
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			dists[i][j] = 0;
		}
	}
	
	while(!q.empty()){
		pair<int, int> pos = q.front();
		q.pop();
		
		dists[pos.first][pos.second] = 1;
		//cout << pos.first << ' ' << pos.second << '\n';
		
		int offsetX[] = {0, 0, -1, 1};
		int offsetY[] = {1, -1, 0, 0};
		
		for(int i = 0; i < 4; i++){
			int xi = pos.first+offsetX[i];
			int yi = pos.second+offsetY[i];
			
			if(xi < 0 or yi < 0 or xi >= n or yi >= m) continue;
			
			char doorcolour = vrata[pos.first][pos.second][xi][yi];
			//cout << pos.first << ' ' << pos.second << ' ' << xi << ' ' << yi << '\n';
			//cout << doorcolour << '\n';
			if(doorcolour == 'Z' and green == 1){
				if(!dists[xi][yi]) q.push({xi, yi});
				dists[xi][yi] = 1;
			} else if(doorcolour == 'C' and red == 1){
				if(!dists[xi][yi]) q.push({xi, yi});
				dists[xi][yi] = 1;
			} else if(doorcolour == 'P' and blue == 1){
				if(!dists[xi][yi]) q.push({xi, yi});
				dists[xi][yi] = 1;				
			} else if(doorcolour == 'N' and yellow == 1){
				if(!dists[xi][yi]) q.push({xi, yi});
				dists[xi][yi] = 1;
			}
		}
	}
	return dists[ci][di];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		string inp; cin >> inp;
		for(int j = 0; j < m-1; j++){
			vrata[i][j][i][j+1] = inp[j];
			vrata[i][j+1][i][j] = inp[j];
		}
	}
	
	for(int i = 0; i < n-1; i++){
		string inp; cin >> inp;
		for(int j = 0; j < m; j++){
			vrata[i][j][i+1][j] = inp[j];
			vrata[i+1][j][i][j] = inp[j];
		}
	}
	
	cin >> q;
	for(int i = 0; i < q; i++){
		int a, b, c, d; cin >> a >> b >> c >> d; a--; b--; c--; d--;
		
		int sol = 4;
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 2; l++){
					for(int o = 0; o < 2; o++){
						int solvable = runSolver(a, b, c, d, j, k, l, o);
						if(solvable) sol = min(sol, j+k+l+o);
						//cout << solvable;
					}
				}
			}
		}
		cout << sol << '\n';
	}
}
