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

bool compareByValue(const teleport &tele_a, const teleport &tele_b) {
    return tele_a.value < tele_b.value;
}

int binary_search_leftmost(const vector<teleport>& tele_vector, int x) {
    int low = 1;
    int high = tele_vector.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (tele_vector[mid].value == x) {
            result = mid;
            high = mid - 1;
        } else if (tele_vector[mid].value < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int valor_simetrico(const teleport &tele_obj, int n) {
    int valorSimetrico;
    int index = tele_obj.index;
    if (tele_obj.porzero) {
        valorSimetrico = tele_obj.value + n - 2 * index + 1;
    }
    else {
        valorSimetrico = tele_obj.value + 2 * index - n - 1;
    }
    return valorSimetrico;
}

void remover_simetricos(vector<teleport>& tele_vector, teleport &tele_obj, int posicao, int n) {
    int index = tele_obj.index;
    int valorSimetrico = valor_simetrico(tele_obj, n);

    //apaga o teletransporte tele_obj
    tele_vector.erase(tele_vector.begin() + posicao);

    //binary search to find the value to remove
    int i = binary_search_leftmost(tele_vector, valorSimetrico);

    // como podemos ter mais de um elemento no vetor com valor valueRemove
    // pegamos o índice mais a esquerda e procuramos o valor certo
    while(tele_vector[i].index != index) {
        i++;
    }

    // agora, basta remover ele da lista também
    tele_vector.erase(tele_vector.begin() + i);

}

void solve() {
    int n, c; cin >> n >> c;
    int ans = 0;

    //vetor de objetos de teletransporte
    vector<teleport> tele(2 * n + 1);

    //inicializando os objetos de teletransporte
    int cur;
    for (int i = 1; i <= n; i++) {
        cin >> cur;
        tele[i] = {cur + i, i, true};
        tele[n + i] = {cur + n - i + 1, i, false};
    }

    //ordenar objetos de teletransporte por valor
    sort(tele.begin(), tele.end(), compareByValue);

    //achar o primeiro menor valor andando a partir do 0
    cur = 1;
    while (cur <= 2*n){
        if (tele[cur].porzero) {
            cout << "achei" << endl;
            break;
        }
        cur++;
    }

    if (c >= tele[cur].value) {
        c -= tele[cur].value;
        ans++;
        //vamos deletar o objeto encontrado e seu simétrico
        remover_simetricos(tele, tele[cur], cur, n);

    } else {
        c = -1;
    }

    //loop que vai pegar o menor valor disponível, e realizar o teletransporte naquela casa
    while (tele.size() > 1 && c >= tele[1].value) {
        //tira o valor do teletransporte e incrementa a resposta
        c -= tele[1].value;
        ans++;
        remover_simetricos(tele, tele[1], 1, n);
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