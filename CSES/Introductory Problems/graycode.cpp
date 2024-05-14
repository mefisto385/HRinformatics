#include <bits/stdc++.h>
using namespace std;
 
vector<string> combs;
string x;
int n;
 
void mijenjajBit(int iPos){
  //cout << x << '\n';
  if (iPos < 0) 
  	return;
  
  //x[iPos] = (char)(!(((int) x[iPos])-48)+48);
  if (x[iPos] == '0'){
  	x[iPos]='1';
  } else {
  	x[iPos]='0';
  }
  cout << x << '\n';
  return mijenjajBit(iPos-1);
}
 
void mijenjajBit2(int iPos){
  //x[iPos] = (char)(!(((int) x[iPos])-48)+48);
  if (x[iPos] == '0'){
  	x[iPos]='1';
  } else {
  	x[iPos]='0';
  }
  cout << x << '\n';
  for(int i = 0; i < iPos; i++){
  	mijenjajBit2(i);
  }
}
 
 
int main(){
	cin >> n;
	for(int i = 0; i < n; i++) x+='0';
	/*mijenjajBit(0);
	cout << x;*/
	
	cout << x << '\n';
	for(int i = 0; i < n; i++){
		mijenjajBit2(i);
		//cout << x << '\n';
	}
}
 
