// https://open.kattis.com/contests/e4htpf/problems/guessinggame

#include <iostream>
using namespace std;
int main(){
	
	int n;
	bool v[10];
	for(int i=0; i<10; i++) v[i] = true;
	string ans, x, y;
	
	cin>>n;
	while(n!=0){
		cin>>x>>y;
		ans = x + " " + y;
		if(ans=="too high"){
			for(int i=n-1; i<10; i++){
				v[i] = false;
			}
		} else if(ans=="too low"){
			for(int i=0; i<=n-1; i++){
				v[i] = false;
			}
		} else if(ans =="right on") {
			if(!v[n-1]){
				cout<<"Stan is dishonest"<<endl;
			} else {
				cout<<"Stan may be honest"<<endl;
			}
			for(int i=0; i<10; i++) v[i] = true;
		}
		cin>>n;
	}
	
	return 0;
}