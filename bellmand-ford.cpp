#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define tu tuple<ll, ll, ll>
#define rep(i, n) for(int i = 0; i < n; ++i)

// 0-indexed
vector<tu> adj;
vector<ll> dis;
int e, n, start, up = 1;
void bell(int st) {
    dis = vector<ll>(n, LONG_MAX);
    dis[st] = 0;
    while(up) {
        up = 0;
        for(const auto &[from, to, val] : adj) 
            if(dis[to] > dis[from] + val){
                dis[to] = dis[from] + val;
                up = 1;
            }
    }
}
int main(){
    cin.tie(0); 
    cin.sync_with_stdio(0);
    // N vertex E edges from start
    cin>> n >> e >> start;

    rep(i, e){
        int from, to, val;
        cin >> from >> to>> val;
        adj.emplace_back(from, to, val);
        adj.emplace_back(to, from, val);
    }

    bell(start);
    //output
    for(auto i : dis)
        cout << i << ' ';
    cout << '\n';
    
}
/*
3 3 2 
0 2 200
0 1 100
1 2 50

ANS : 150 50 0
*/