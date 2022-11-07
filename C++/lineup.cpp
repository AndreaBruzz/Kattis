// https://open.kattis.com/contests/e4htpf/problems/lineup

#include <iostream>
using namespace std;

int main(){
	
	int N;
	cin>>N;
	
	string name[N];
	bool ord[2] {false, false}; //asc,desc
	
	for(int i=0; i<N; i++){
		cin>>name[i];
	}
	
	for(int i=0; i<N-1; i++){
		if(name[i].compare(name[i+1])>0) ord[1] = true;
		else if(name[i].compare(name[i+1])<0) ord[0] = true;			
	}
	
	if(ord[0] && ord[1]) cout<<"NEITHER";
	else if (ord[0]) cout<<"INCREASING";
	else cout<<"DECREASING";
	
	return 0;
}