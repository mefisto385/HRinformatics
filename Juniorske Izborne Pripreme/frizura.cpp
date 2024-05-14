#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5+7;

int n, wn;
int vs[maxn];
int ve[maxn];
int tr[maxn*10];
vector<int> trx[maxn*10];

set<int> vpos[maxn];
unordered_map<int, int> compressed;
set<int> tmp;

ll query(int l, int r, int lx, int rx, int ind){
	if(l >= lx and r <= rx){
		return tr[ind];
	}
	
	if(r < lx or l > rx) return -1;
	
	return max(query(l, (l+r)/2, lx, rx, ind*2), 
				query((l+r)/2+1, r, lx, rx, ind*2+1));
}

vector<int> queryx(int l, int r, int lx, int rx, int ind){
	if(l >= lx and r <= rx){
		return trx[ind];
	}
	
	vector<int> ret;
	if(r < lx or l > rx) return ret;
	
	vector<int> ai = queryx(l, (l+r)/2, lx, rx, ind*2);
	vector<int> bi = queryx((l+r)/2+1, r, lx, rx, ind*2+1);
		
	bool eq = (ai.size() and bi.size() and ve[ai[0]] == ve[bi[0]]);
	
	if(eq or (ai.size() and !bi.size()) or (ai.size() and ve[ai[0]] > ve[bi[0]]))for(auto x : ai) ret.pb(x);
	if(eq or (bi.size() and !ai.size()) or (bi.size() and ve[bi[0]] > ve[ai[0]]))for(auto x : bi) ret.pb(x);
		
	return ret;
}

int solve(int lx, int rx){
	int ret = 1;
	if(lx > rx) return 0;
	
	//int mn = query(0, wn-1, lx, rx, 1);
	
	int lpos = lx;
	bool mi = true;
	vector<int> indxs = queryx(0, wn-1, lx, rx, 1);
	
	for(auto i : indxs){
		if(ve[i] != vs[i]) mi = false;
		ret += solve(lpos, i-1);
		lpos = i+1;
	}
    
    if(mi) ret--;
	
	ret += solve(lpos, rx);
	
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> vs[i];
		
	for(int i = 0; i < n; i++){
		cin >> ve[i];
		tmp.insert(ve[i]);
		
		if(ve[i] > vs[i]){
			cout << -1 << '\n';
			return 0;
		}
	}
	
	int t = 1;
	for(auto i = tmp.begin(); i != tmp.end(); i++){
		compressed[*i] = t;
		t++;
	}
	
	for(int i = 0; i < n; i++) vpos[compressed[ve[i]]].insert(i);
	
	wn = 2;
	while(wn < n){
		wn*=2;
	}
	
	for(int i = n; i < wn; i++) tr[i + wn] = -1;
	for(int i = 0; i < n; i++) tr[i + wn] = ve[i];
	
	for(int i = wn-1; i >= 1; i--) tr[i] = max(tr[i*2+1], tr[i*2]);
	
	vector<int> emp;
	//cout << "BOK";
	for(int i = n; i < wn; i++) trx[i+wn] = emp;
	for(int i = 0; i < n; i++) {
		vector<int> e; e.pb(i);
		trx[i+wn] = e;
	}
	
	for(int i = wn-1; i >= 1; i--){
		int a = tr[i*2+1];
		int b = tr[i*2];
		
		if(a == b){
			
			for(auto xi : trx[i*2]) trx[i].pb(xi);
			for(auto xi : trx[i*2+1]) trx[i].pb(xi);
			
		} else if(a > b){
			trx[i] = trx[i*2+1];
		} else {
			trx[i] = trx[i*2];
		}
	}

	cout << solve(0, n-1);
}
