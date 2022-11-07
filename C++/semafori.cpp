// https://open.kattis.com/contests/e4htpf/problems/semafori

#include <iostream>
using namespace std;

int main(){
    
    int N, L;
    cin>>N>>L;
    
    int D=0, R, G;
    int t=0, tmp, D_old=0;
    for(int i=0; i<N; i++){
    	cin>>D>>R>>G;
        t += D - D_old;
        tmp = t % (R+G);
        if(tmp<R) t += R-tmp;
        D_old = D;
    }
    if(D<L) t+= L-D;
    cout<<t;
    
    return 0;
}