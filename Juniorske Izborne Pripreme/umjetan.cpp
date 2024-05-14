//CREDIT TO BORNAG
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2007;

int sol[maxn][maxn];
int prepsol[maxn][maxn];
int mat[maxn][maxn];

int n, m;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
			
	for(int r = 0; r < n; r++){
		int s1 = -1;
		int s2 = -1;
		
		for(int i = r; i >= 0; i--){
			s1 = max(s1, mat[r][i]);
			s2 = max(s2, mat[i][r]);
			
			prepsol[r][i] = s1;
			prepsol[i][r] = s2;
		}
	}
	
	for(int l = 0; l < n; l++){
		int sl = -1;
		for(int r = l; r < n; r++){
			sl = max(sl, max(prepsol[l][r], prepsol[r][l]));
			sol[l][r] = sl;
		}
	}
	
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		
		cout << sol[a-1][b-1] << '\n';
	}
}
