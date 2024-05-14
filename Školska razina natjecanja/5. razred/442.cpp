//CREDIT TO BORNAG & TARPENT
#include<bits/stdc++.h>
using namespace std;

string red;
int pr;
int dr,tr;
int main(){
	getline(cin, red);
	for(int i = 0; i<red.size()-2; i++){
		
		if((int)red[i]-48+(int)red[i+1]-48+(int)red[i+2]-48==10){
			pr=(int)red[i]-48;
			dr=(int)red[i+1]-48;
			tr=(int)red[i+2]-48;
		}
	}
	cout<<pr<<' '<<dr<<' '<<tr;
	
}
