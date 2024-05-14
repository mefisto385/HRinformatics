//CREDIT TO BORNAG & TARPENT
#include <bits/stdc++.h>
using namespace std;

const int maxn = 57;

int n, m, k;
char tab[maxn][maxn];
int contain[maxn][maxn];
char pieces[17][7][7];

void spread(int x, int y, int marker){
	contain[x][y] = marker;
	//cout << "BOK";
	
	int xOffset[] = {1, -1, 0, 0};
	int yOffset[] = {0, 0, -1, 1};
	
	for(int i = 0; i < 4; i++){
		int tx = x+xOffset[i];
		int ty = y+yOffset[i];
		
		if(min(tx, ty) >= 0 and tx < n and ty < m){
			if(contain[tx][ty] == 0 and tab[tx][ty] == '0') spread(tx, ty, marker);
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		string inx; cin >> inx;
		for(int j = 0; j < m; j++){
			tab[i][j] = inx[j];
		}
	}
	
	int components = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(contain[i][j] == 0 and tab[i][j] == '0'){
				++components;
				spread(i, j, components);
			}
		}
	}
	
	cin >> k;
	for(int i = 0; i < k; i++){
		string puzz[6];
		
		for(int j = 0; j < 5; j++){
			cin >> puzz[j];
		}
		
		int leftmost = 5;
		int topmost = 5;
		
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				if (puzz[j][k] == '1'){
					leftmost = min(k, leftmost);
					topmost = min(j, topmost);
				}
			}
		}
		
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				pieces[i][j][k] = '0';
			}
		}
		
		for(int j = topmost; j < 5; j++){
			for(int k = leftmost; k < 5; k++){
				pieces[i][j-topmost][k-leftmost] = puzz[j][k];
			}
		}
	}
	
	for(int i = 1; i <= components; i++){
		int leftmost = m;
		int topmost = n;
		int rightmost = 0;
		int downmost = 0;
		
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				if(contain[j][k] == i){
					leftmost = min(leftmost, k);
					topmost = min(topmost, j);
					rightmost = max(rightmost, k);
					downmost = max(downmost, j);
				}
			}
		}
		
		if(downmost-topmost > 4 or rightmost-leftmost > 4) continue;
		
		char tpz[6][6];
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				tpz[j][k] = '0';
			}
		}
		
		for(int j = topmost; j <= downmost; j++){
			for(int k = leftmost; k <= rightmost; k++){
				if(contain[j][k] == i) tpz[j-topmost][k-leftmost] = '1';
			}
		}
		
		//cout << leftmost << ' ' << rightmost << ' ' << topmost << ' ' << downmost << '\n';
		/*for(int j = 0; j < 5; j++){
			for(int k= 0; k < 5; k++){
				cout << tpz[j][k];
			} cout << '\n';
		} cout << '\n';*/
		
		for(int comp = 0; comp < k; comp++){
			bool right = true;
			
			for(int j = 0; j < 5; j++){
				for(int k = 0; k < 5; k++){
					if(tpz[j][k] != pieces[comp][j][k]){
						right = false;
					}
				}
			}
			
			if(right){
				for(int j = topmost; j <= downmost; j++){
					for(int k = leftmost; k <= rightmost; k++){
						if(contain[j][k] == i) tab[j][k] = '1';
					}
				}
				
				break;
			}
		}
	}
	//cout << components << '\n';
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << tab[i][j];
		} cout << '\n';
	}	
}
