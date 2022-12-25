#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long

#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define rep(i, n) for(int i = 0; i < n; ++i)

#define xd x + d[k].first
#define yd y + d[k].second

int m, n;
pair<int, int> d[4];
int check(int i, int j) {
    return (i < m && i > -1 && j < n && j > -1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[0] = {0, 1}, d[1] = {0, -1}, d[2] = {1, 0}, d[3] = {-1, 0};
    int i, j;
    for(int k = 0; k < 4; ++k) {
                //cout << i + d[k].first << " " << j + d[k].second << endl;
        if(check(i + d[k].first, j + d[k].second)) {
        
        }
    }


}