#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// We use a DP for bounded subset sum where coins are small.
void processCoins(vector<bool> &dp, int coin, int freq, int limit) {
    // For each residue modulo coin, process the indices i = r, r+coin, r+2*coin, ...
    for (int r = 0; r < coin; r++) {
        int used = 0;
        for (int i = r; i <= limit; i += coin) {
            // If dp[i] is true, we can "refresh" our ability to use coins.
            if (dp[i]) {
                used = freq; // we have freq coins available from this position.
            } else if (used > 0) {
                // We can mark dp[i] true by using one coin from the "window"
                dp[i] = true;
                used--;
            } else {
                // Otherwise, dp[i] remains false.
            }
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        long long K;
        cin >> n >> K;
        
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }
        for (int i = 0; i < n; i++){
            cin >> B[i];
        }
        
        long long Smin = 0; // sum if we choose Option1 on every dial
        long long totDiff = 0; // total possible extra if we switch to Option2
        
        // We will store the differences in a frequency array for possible coin values: 1,3,5,7,9.
        // We'll use an array freq[10] (indices 0..9), but only odd indices matter.
        vector<int> freq(10, 0);
        
        for (int i = 0; i < n; i++){
            // Compute up and down moves (cyclic)
            int up = (B[i] - A[i] + 9) % 9;   // if B[i]>=A[i] then B[i]-A[i], else add 9.
            int down = (A[i] - B[i] + 9) % 9; // similarly.
            // minimal moves (Option1)
            int r = min(up, down);
            Smin += r;
            // Alternative option is 9 - r.
            int alternative = 9 - r;
            // Only if alternative is larger than r do we have a positive difference.
            int diff = alternative - r;
            totDiff += diff;
            if(diff > 0) {
                freq[diff]++; // diff is in {1,3,5,7,9}.
            }
        }
        
        // Let T be the extra moves we need after Smin.
        long long T = K - Smin;
        // If T is negative, not possible.
        if(T < 0) {
            cout << "NO\n";
            continue;
        }
        
        // We need to decide if there exists a subset of the coins (diff values) whose sum D
        // satisfies: D <= T and (T - D) is even.
        // Since extra wasted moves come in even increments, (T - D) must be even.
        
        // The maximum D we can achieve is totDiff.
        int limit = (T < totDiff ? T : totDiff);
        
        // dp[d] = true if we can achieve a sum d from the coins.
        vector<bool> dp(limit+1, false);
        dp[0] = true;
        
        // Process coin types: only odd values: 1,3,5,7,9.
        for (int coin = 1; coin <= 9; coin += 2) {
            if(freq[coin] > 0) {
                processCoins(dp, coin, freq[coin], limit);
            }
        }
        
        bool possible = false;
        // Check for any achievable sum D (0 <= D <= limit) such that (T - D) is even.
        for (int d = 0; d <= limit; d++){
            if(dp[d] && ((T - d) % 2 == 0)) {
                possible = true;
                break;
            }
        }
        
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
