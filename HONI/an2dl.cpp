#include <bits/stdc++.h>
using namespace std;

const int maxn = 7e3+7;

int n, m, r, s;
int mat[maxn][maxn];

int solmat[maxn][maxn];
int sol[maxn][maxn];

deque<pair<int, int>> q;
int cnt_added = 0;
int cnt_removed = 0;

void addEl(int new_element){
	while (!q.empty() && q.back().first < new_element)
    	q.pop_back();
	q.push_back({new_element, cnt_added});
	cnt_added++;
}

void remEl(){
	if (!q.empty() && q.front().second == cnt_removed) 
    	q.pop_front();
	cnt_removed++;
}

int fMin(){
	return q.front().first;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}
	
	cin >> r >> s;
	
	for(int i = 0; i < n; i++){
		q.clear();
		cnt_added = 0;
		cnt_removed = 0;
		
		for(int j = 0; j < m; j++){
			if(j < s-1){
				
				addEl(mat[i][j]);
				//cout << "H\n";
				
			} else if(j == s-1){
				
				addEl(mat[i][j]);
				solmat[i][j-s+1] = fMin();
				
				//cout << "Y\n";
				
			} else {
				
				addEl(mat[i][j]);
				remEl();
				
				solmat[i][j-s+1] = fMin();
				//cout << fMin() << '\n';
				
			}
		}
	}
	
	for(int i = 0; i < m-s+1; i++){
		
		q.clear();
		cnt_added = 0;
		cnt_removed = 0;
		
		for(int j = 0; j < n; j++){
			if(j < r-1){
				
				addEl(solmat[j][i]);
				
			} else if(j == r-1){
				
				addEl(solmat[j][i]);
				sol[j-r+1][i] = fMin(); 
				
			} else{
				
				addEl(solmat[j][i]);
				remEl();
				
				sol[j-r+1][i] = fMin();
				
			}
		}
	}
	
	//output
	for(int i = 0; i < n-r+1; i++){
		for(int j = 0; j < m-s+1; j++){
			cout << sol[i][j]  << ' ';
		} cout << '\n';
	}
}