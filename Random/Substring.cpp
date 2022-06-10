#include<bits/stdc++.h>
using namespace std;

void SubString(string ip,string op){
	if(ip.empty()){
		cout<<op<<endl;
		return;
	}
	SubString(ip.substr(1),op);
	SubString(ip.substr(1),op+ip[0]);
}

int main(){
	string ip="abc";
	string op="";
	SubString(ip,op);
	return 0;
}