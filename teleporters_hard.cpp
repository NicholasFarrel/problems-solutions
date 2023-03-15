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
 
//data structure that will help to solve the problem
struct teleport
{
    int value;
    int index;
    bool porzero;
};

bool compareByValue(const teleport &a, const teleport &b) {
    return a.value < b.value;
}

int first_appear(vector<teleport> tele, int low, int high) {

}

void solve() {
    int n, c; cin >> n >> c;
    int ans = 0;

    //vetor de objetos de teletransporte
    vector<teleport> tele(2 * n + 1);

    //inicializando os objetos de teletransporte
    int cur;
    for (int i = 1; i < n + 1; i++) {
        cin >> cur;
        tele[i] = {cur + i, i, true};
        tele[i + 1] = {cur + n - i + 1, i, false};
    }

    //ordenar objetos de teletransporte por valor
    sort(tele.begin(), tele.end(), compareByValue);

    //achar o primeiro menor valor andando a partir do 0
    cur = 1;
    while (true && cur <= 2*n){
        if (tele[cur].porzero) {
            if (c >= tele[cur].value) {
                c -= tele[cur].value;
                ans++;
                cur++;
                tele.erase(tele.begin() + cur);
            }
            break;
        }
    }

    while (tele.begin() != tele.end() && c >= tele[1].value) {
        //tira o valor do teletransporte e incrementa a resposta
        c -= tele[1].value;
        ans++;
        //value that needs to be removed
        int valueRemove;
        int indexRemove = tele[cur].index;
        if (tele[cur].porzero) {
            valueRemove = tele[cur].value + n - 2 * cur + 1;
        }
        else {
            valueRemove = tele[cur].value + 2 * cur - n - 1;
        }
        //apaga o teletransporte que acabamos de usar
        tele.erase(tele.begin() + 1);

        //binary search to find the value to remove

    }

}
 
int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}