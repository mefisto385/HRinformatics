#include <bits/stdc++.h>
using namespace std;

int r, c;
string rw;
string grid[1007];
long long gridd[1007][1007];
const long long M = 1e9+7;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);
	
	cin >> r >> c;
	
	for(int i = 0; i < r; i++){
		cin >> grid[i];
	}
	
	gridd[1][1] = 1;
	
	for(int col = 2; col < c+1; col++){
		if(grid[1-1][col-1] != '#') gridd[1][col] = gridd[1][col-1];
	}
	
	for(int row = 2; row < r+1; row++){
		for(int col = 1; col < c+1; col++){
			if(grid[row-1][col-1] != '#'){
				gridd[row][col] += (gridd[row][col-1]+gridd[row-1][col])%M;
			}
		}
	}
	
	cout << gridd[r][c];
}
