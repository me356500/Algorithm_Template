#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long

#define vl vector<ll>
#define vvl vector<vector<ll>>

#define pii pair<int, int>
#define rep(i, n) for(int i = 0; i < n; ++i)

// 1.
static bool cmp(const pii &a, const pii &b) {
    // [val , id]
    // return larger val with smaller id
    if(a.first < b.first)
        return 1;
    else if (a.first > b.first)
        return 0;
    return a.second > b.second;
}
// 2.
bool cmp2(pii a, pii b) {
    if(a.first < b.first)
        return 1;
    else if (a.first > b.first)
        return 0;
    return a.second > b.second;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // calling decltype
    priority_queue<pii, vector<pii>, decltype(&cmp)> pq1(&cmp);

    // 2. function
    priority_queue<pii, vector<pii>, function<bool(pii, pii)>> pq2(cmp2);

    // 3. lambda
    auto cmp3 = [] (pii &a, pii &b) -> bool {
        if(a.first < b.first)
            return 1;
        else if (a.first > b.first)
            return 0;
        return a.second > b.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp3)> pq3(cmp3);


}