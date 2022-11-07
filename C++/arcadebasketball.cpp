// https://open.kattis.com/contests/e4htpf/problems/competitivearcadebasketball

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,p,m;
	cin>>n>>p>>m;
	string name[n];
	int score[n];
	bool win[n];
	bool check = false;
	
	for(int i=0; i<n; i++){
		cin>>name[i];
		score[i]=0;
		win[i]=false;
	}
	
	sort(name, name+n, greater<string>());
	
	string a;
	int b;
	
	for(int i=0; i<m; i++){
		cin>>a>>b;
		int from=0, to=n;
		int mid;
		while(from!=to){
			mid = (from + to)/2;
			if(name[mid]==a) from=to;
			else if(a.compare(name[mid]) > 0) to = mid;
			else from = mid+1; 
		}
		score[mid] += b;
		
		if(score[mid] >= p && win[mid]==false){
			cout<<name[mid]<<" wins!"<<endl;
			win[mid] = true;
			check = true;
		}
	}
	
	if(!check) cout<<"No winner!";	

	
	return 0;
}
