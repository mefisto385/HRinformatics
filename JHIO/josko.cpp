//CREDIT TO BORNAG & TARPENT
#include<bits/stdc++.h>
using namespace std;

const long long inf = 1e9+7;

long long n, m, ai, bi, ti;
long long times[107];

long long dp[107][207];

long long dpindex[1001 * 107];

vector<long long> pnts;
vector<pair<long long, long long>> startend;

void upd(long long row){
	long long start = startend[row].first;
	long long end = startend[row].second;
	
	long long rstart;
	
	if(row == 0) rstart = dpindex[start]+1;
	else rstart = dpindex[start];
	
	//cout << start << ' ' << end << ' ' << dpindex[start] << ' ' << dpindex[end] << '\n';
	
	for(long long i = rstart; i < dpindex[end]+1; i++){
		
		long long mi = -1;
		for(mi = row-1; mi > -1; mi--){
			if(dp[mi][i] != inf) break;
		}
		
		//if(row==n-1) cout << mi << "x\n";
		
		long long a = dp[max(0ll, mi)][i];
		
		if(mi == -1) a = inf;
		
		long long b = dp[row][max(0ll, i-1)] + (pnts[i]-pnts[max(0ll, i-1)])*times[row];
		
		dp[row][i] = min(a, b);
		//cout << row << ' ' << i << ' ' << a << ' ' << b << '\n';
	}
}

void saveinfo(long long a, long long b, long long t, long long ind){
	times[ind] = t;
	if(!count(pnts.begin(), pnts.end(), a)) pnts.push_back(a);
	if(!count(pnts.begin(), pnts.end(), b)) pnts.push_back(b);
	startend.push_back({a, b});
}

int main(){
	cin >> n >> m;
	
	for(long long i = 0; i < n; i++){
		cin >> ai >> bi >> ti;
		saveinfo(ai, bi, ti, i);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2*n; j++) dp[i][j] = inf;
	}
	
	sort(pnts.begin(), pnts.end());
	
	for(long long i = 0; i < pnts.size(); i++){
		dpindex[pnts[i]] = i;
	}
	
	dp[0][dpindex[startend[0].first]] = 0;
	
	//cout << dpindex[startend[0].first] << '\n';
	
	for(long long i = 0; i < n; i++){
		upd(i);
	}
	
	cout << dp[n-1][dpindex[startend[startend.size()-1].second]];
	
	/*for(int i = 0; i < n; i++){
		for(int j = 0; j < 2*n; j++) if(dp[i][j] == 0) cout << "WHAT";
		cout << '\n';
	}*/
}
