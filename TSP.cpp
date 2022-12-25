#include<bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)

// vertices edges colors
int n, m ,k;
// vertex color , ans
int ver[20];
int adj[20][20];
int dp[(1 << 20)][20];

inline int solve(int colormask, int pos) {


    if (~dp[colormask][pos])
        return dp[colormask][pos];
     
    // visited all color
    if (!(__builtin_popcount(colormask) ^ k ))
        return dp[colormask][pos] = 0;

    int minStep = 1e9;
    int tmp = colormask;
    colormask |= (1 << ver[pos]);

    rep(i, n) {
        
        // check color visted or not
        if (!(colormask & ( 1 << ver[i]))) {

            minStep = min(minStep, adj[pos][i] + solve(colormask, i));
        } 
    }
  

    return dp[tmp][pos] = minStep;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m >> k;
    // dummy nodes

    // Initialize edges / ver / dp
    memset(dp, -1 , sizeof(dp));
    memset(adj, 0x3f, sizeof(adj));

    // Input 
    rep(i, n) {
        int temp;
        cin >> temp;
        ver[i] = temp - 1;
        adj[i][i] = 0;
    }

    rep(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        --x;
        --y;
        adj[x][y] = w;
        adj[y][x] = w;
    }

    // Given Graph may not be Complete Graph
    // Use Floyd-Warshall make graph complete to meet the TSP requirement
    rep(x, n)
        rep(i, n)
            rep(j, n) 
                adj[i][j] = min(adj[i][j], adj[i][x] + adj[x][j]);
  
    // TSP of dummy vertex can get min TSP from any start or end 
    int ans = 2e9;
    rep(i, n)
        ans = min(ans, solve((1 << ver[i]), i));
    
    cout << ans;
    return 0;
}