#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
using ll = long long;
 
void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N; 
    ll X;
    cin >> N >> X;
    vector<ll> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    // Special case: X==1 means no change.
    unordered_map<ll, int> freq;
    for (ll a : A) {
        freq[a]++;
    }
    int baseAns = 0;
    for (auto &p : freq)
        baseAns = max(baseAns, p.second);
    if(X == 1) {
        cout << baseAns << "\n";
        return;
    }
    
    // We'll compute, for each candidate v,
    // the maximum contiguous "gain" using an online Kadane's algorithm.
    // For candidate v, an index i gives:
    //   +1 if A[i] == v/X (provided v % X == 0),
    //   -1 if A[i] == v,
    //   0 otherwise.
    // Since each index contributes to at most two candidates, we update those.
    unordered_map<ll, int> curr, bestGain;
    // Initialize bestGain to 0 for candidates we encounter.
    
    // Process indices from 0 to N-1
    for (int i = 0; i < N; i++){
        ll a = A[i];
        
        // Candidate that gets +1: v1 = a * X.
        ll v1 = a * X;
        // Update candidate v1:
        // Its contribution at index i is +1.
        // curr[v1] = max( 0, curr[v1] + 1 ).
        curr[v1] = max(0, curr[v1] + 1);
        bestGain[v1] = max(bestGain[v1], curr[v1]);
        
        // Candidate that gets -1: v2 = a.
        ll v2 = a;
        curr[v2] = max(0, curr[v2] - 1);
        bestGain[v2] = max(bestGain[v2], curr[v2]);
    }
    
    // Now, for each candidate v that we have seen (in bestGain),
    // the best possible final frequency if we target v is:
    // f(v) + bestGain[v]   (if we operate on a contiguous subarray)
    // We also consider not operating, which gives just f(v).
    int ans = baseAns;
    for (auto &p : bestGain) {
        ll v = p.first;
        int gain = p.second;
        int candidateFreq = (freq.count(v) ? freq[v] : 0) + gain;
        ans = max(ans, candidateFreq);
    }
    
    cout << ans << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
