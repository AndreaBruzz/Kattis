// https://open.kattis.com/problems/squarepegs

#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

int min(int a, int b){
	if(a<b){
		return a;
	} else {
		return b;
	}
}
int main(){
	
	int M,N,K;
	cin>>N>>M>>K;
	
	int plots[N];
	for(int i=0; i<N; i++) cin>>plots[i];
	
	priority_queue<int, vector<int>, greater<int> > circ;
	for(int i=0; i<M; i++){
		int tmp;
		cin>>tmp;
		circ.push(tmp);
	}
	
	priority_queue<double, vector<double>, greater<double> > sqr;
	int l;
	for(int i=0; i<K; i++){
		cin>>l;
		sqr.push(l*sqrt(2)/2);	
	} 
	
	sort(plots, plots+N);
	
	int cont = 0;
	int a,b,m;
	for(int i=0; i<N; i++){
		if(!circ.empty()) a = circ.top();
		else a = 101;
		if(!sqr.empty()) b = sqr.top();
		else b = 101;
		m = min(a,b);
		
		if(plots[i] > m){
			cont++;
			if(m==a) circ.pop();
			else sqr.pop();
		}
		
	}
	
	cout<<cont;
	return 0;
}
