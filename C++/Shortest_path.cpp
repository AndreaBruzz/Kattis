#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define MAXN 20000

ll M,N,Q,S;
vector<pll> gr[MAXN];
bool used[MAXN];
int d[MAXN];

int main(){

    while(cin>>N>>M>>Q>>S){

        if(N==0) break;

        for(int i=0; i<N; i++){
            gr[i].clear();
            used[i] = false;
            d[i] = -1;
        }

        for(int i=0; i<M; i++){
            ll a,b,w;
            cin>>a>>b>>w;
            gr[a].push_back({b,w});
        }

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0,S});
        d[S] = 0;

        while(!pq.empty()){
            ll n = pq.top().second;
            pq.pop();

            if(used[n]) continue;
            used[n] = true;

            for(pll x: gr[n]){
                ll m = x.first, val = x.second;
                if(!used[m] && (d[m] == -1 || d[m]>d[n]+val)){
                    d[m] = d[n] + val;
                    pq.push({d[m], m});
                } 
            }
        }

        for(int i=0; i<Q; i++){
        ll x;
        cin>>x;

        if(d[x] == -1) cout<<"Impossible "<<endl;
        else cout<<d[x]<<endl;
    }

    }

    

    return 0;
}