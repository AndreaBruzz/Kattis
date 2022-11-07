// https://open.kattis.com/contests/ni7hn6/problems/carefulascent

#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

class Shield{
	public:
		double lb, ub;
		double f;
		
		Shield():lb{0},ub{0},f{0.0}{
		}
		
		void load(){cin>>lb>>ub>>f;}
		double delta(){return ub - lb;}
};

int main(){
	
	cout<<setprecision(11)<<fixed;
	double x,y;
	int n;
	cin>>x>>y;
	cin>>n;
	
	Shield v[n];
	for(int i=0; i<n; i++) v[i].load();
	
	double vx; //vy=1 quindi non creo una variabile inutile...
	double t = y, ts = 0.0, tf = 0.0, tnf;
	
	for (int i = 0; i < n; i++){
        ts   += v[i].delta();
        tf += (v[i].delta())*(v[i].f);
    }
    
    tnf = t - ts;
    vx = x / (tnf + tf);
    
    cout<<vx;
		
	return 0;
}
