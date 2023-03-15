#include<bits/stdc++.h>
using namespace std;
const long long inf = (long long) 1e18 + 10;
const int inf1 = (int) 1e9 + 10;
#define int long long
#define dbl long double
#define endl '\n'
#define sc second
#define fr first
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
const int maxn = -1;
 
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

void solve() {
    int n, c; cin >> n >> c;
    int ans = 0;
    //neste vetor de pares, temos: 
    //a[i].first = preço mínimo de teletransporte para i
    //a[i].second = preço de teletrasnporte saindo do 0
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = a[i].first + i + 1;
        a[i].first += min(i + 1, n - i);
    }
    sort(a.begin(), a.end(), cmp);

    vector<int> pref(1, 0);
    for (int i = 0; i < n; i++) {
        pref.pb(pref.back() + a[i].first);
    }

    for (int i = 0; i < n; i++) {
        int maximo = 0;
        int coins = c - a[i].second;

        //binary search to find the max pref < coins
        int lo = 0, hi = n;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int sum = pref[mid];

            //taken é a variável que indica quantos teletransportes peguei para este mid
            //esse +1 é do primeiro teletransporte que peguei
            int taken = mid + 1;

            //se i < mid, devo descontar o teletransporte a[i] que já peguei
            if (i < mid) {
                sum -= a[i].first;
                taken--;
            }

            if (sum <= coins) {
                maximo = max(maximo, taken);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        ans = max(ans, maximo);
    }
    cout << ans << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}