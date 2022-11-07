// https://open.kattis.com/problems/dungeon


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<ll,3> Point;

Point dim, St, En;
ll d[40][40][40];
bool m[40][40][40];

ll& fd(Point& p){
    return d[p[0]][p[1]][p[2]];
}

bool& fm(Point &p){
    return m[p[0]][p[1]][p[2]];
}

int main(){

    while(true){
        cin>>dim[0]>>dim[1]>>dim[2];
        if(dim[0] == 0 && dim[1] == 0 && dim[2] == 0) break;

        for(int i=0; i<dim[0]; i++){
            for(int j=0; j<dim[1]; j++){
                string s;
                cin>>s;
                for(int k=0; k<dim[2]; k++){
                    d[i][j][k] = m[i][j][k] = 0;
                    if(s[k] == 'S') St = {i,j,k};
                    else if(s[k] == 'E') En = {i,j,k};
                    else if(s[k] == '#') m[i][j][k] = true;
                }
            }
        }

        queue<Point> q;
        q.push(St);
        fd(St) = 1;

        while(!q.empty()){
            Point p = q.front();
            q.pop();

            for(int i=0; i<3; i++){
                for(int j=-1; j<=1; j++){
                    Point np = p;
                    np[i] += j;

                    if(np[i]<0) continue;
                    if(np[i] >= dim[i]) continue;

                    if(!fm(np) && !fd(np)){
                        fd(np) = fd(p) + 1;
                        q.push(np);
                    }
                }
            }

        }

        if(fd(En)) cout<<"Escaped in "<<fd(En) - 1<<" minute(s)."<<endl;
        else cout<<"Trapped!"<<endl;
    }

    return 0;
}