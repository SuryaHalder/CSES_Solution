/*
	Author : SURYA HALDER
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define pb push_back
#define endl '\n'
#define maxheap priority_queue<int> //max heap
#define minheap priority_queue <int, vector<int>, greater<int>> //min heap
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define reprev(i,a,b) for(int i=a;i>=b;i--)

template<typename T>
void input(vector<T>& v) {
    for (auto& x : v) {
        cin >> x;
    }
}

template<typename T>
void output(const vector<T>& v) {
    for (const auto& x : v) {
        cout << x << " ";
    }
    cout << '\n';
}

template<typename T>
void sortA(vector<T>& v) {
    sort(v.begin(), v.end());
}

template<typename T>
void sortD(vector<T>& v) {
    sort(v.begin(), v.end(), greater<T>());
}


void solve() {
    /*Your code here */
    /*
    	Got an intuition of pattern being followed
    	Used OEIS website to find a formula for pattern
    	https://oeis.org/search?q=0%2C6%2C28%2C96%2C252%2C550%2C1056%2C1848&language=english&go=Search
    	Credits: Book by Vaclav Kotesovec
    */
    /* wrong solution on prev submission: use ll i coz overflow is occuring*/
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
    	ll val=(i-1)*(i+4)*((i*i-3*i+4)/2);
    	cout<<val<<endl;
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*Multi testcase*/
    int t;
    cin >> t;
    // while (t--) {
        // solve();
    // }
    /*comment till here*/
    solve();
    return 0;
}
