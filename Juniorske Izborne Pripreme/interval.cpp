//CREDITS TO BORNAG TARPENT
#include<bits/stdc++.h>
using namespace std;

char c;
long long p,d;
vector<pair<long long,int>> li;
string st;
long long zb(long long x, long long y){
	if(x<y){
		y-=1;
		long long tren = (x*10+y*10)/2;
		return(tren*(y-x+1)/10);
	}
	else{
		x-=1;
		long long tren = (x*10+y*10)/2;
		return(long long)(tren*(x-y+1)/10);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while(1){
		cin>>c;
		cin>>p;
	//	cout<<p;
		if(c=='('){
			li.push_back({p+1,1});
		}
		else{
			li.push_back({p,1});
		}
		cin>>c;
		cin>>d;
	//	cout<<d<<'d'
		cin>>c;
		if(c==')'){
			li.push_back({d,-1});
		}
		else{
			li.push_back({d+1,-1});
		}
		cin>>c;
		if(c!=','){
			break;
		}
	}
	getline(cin,st);
	int bro = 0;
	int od = 0;
	if(c=='('){
		od=1;
	}
	long long trb = 0;
	for(auto e: st){
	//	cout<<e<<' '<<bro<<' '<<'w'<<'\n';
		if(bro==0){
			if(e=='('){
				od=1;
			}
			else if(e=='['){
				od=0;
			}
			else if(e==','){
				li.push_back({trb+od,-1});
				bro=1;
				od=0;
				trb=0;
			}
			else{
				trb*=10;
				trb+=(int)e-48;
			}
		}
		else if(bro==1){
			if(e==')'){

				li.push_back({trb,1});
				bro=9;
				od=0;
				trb=0;
			}
			else if(e==']'){
				li.push_back({trb+1,1});
				bro=9;
				od=0;
				trb=0;
			}
			else{
				trb*=10;
				trb+=(int)e-48;
			}
		}
		else if(bro==9){
			bro=0;
			trb=0;
			od=0;
		}
	}
	sort(li.begin(),li.end());
	int tr = 0;
	long long p = 0;
	long long o = 0;
	for(auto e: li){
		if(tr==1){
			o+=zb((long long)e.first,p);
		}
		tr+=e.second;
		if(tr==1){
			p=e.first;
		}
	}
	cout<<o;
	return 0;
}
