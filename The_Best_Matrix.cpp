#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }
    
    // We'll try all 4 possibilities for (p,q) where p,q in {+1, -1}
    // Note: our matrix A is stored with 0-indexed arrays.
    // But the formula uses 1-indexing. So use (i+1) and (j+1) in the formula.
    ll best = N * M; // worst-case changes (change every cell).
    int choices[2] = {1, -1};
    
    for (int ip = 0; ip < 2; ip++) {
        for (int iq = 0; iq < 2; iq++) {
            int p = choices[ip], q = choices[iq];
            // For this pattern, count frequency of c candidates 
            unordered_map<ll, int> freq;
            int maxCount = 0;
            for (int i = 0; i < N; i++){
                for (int j = 0; j < M; j++){
                    // Using 1-index for formula: (i+1) and (j+1)
                    ll d = A[i][j] - (p * (i + 1) + q * (j + 1));
                    freq[d]++;
                    maxCount = max(maxCount, freq[d]);
                }
            }
            ll changes = (ll)N * M - maxCount;
            best = min(best, changes);
        }
    }
    
    cout << best << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
