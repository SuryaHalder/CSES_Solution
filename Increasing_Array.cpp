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
    /* Intuition:-
    keep a maxi(storing maxi value till that index);
    keep a count c, for keeping move count;
    if number at a index is greater thn maxi then makee maxi=a[ind]
    else c+=maxi-a[ind] so that number becomes equal to maxi and array is non-decreasing
    using long long because:
    10^9 1 1 1 1 1 1 1 1 ...
    so then c=(10^9)*(n-1)
    so overflow occurs for n>10 etc.
    */
	ll n;
	cin>>n;
	vll x(n);
	input(x);
	ll c=0;
	ll maxi=x[0];
	for(ll i=1;i<n;i++){
		if(x[i]<maxi){
			c+=(maxi-x[i]);
			x[i]=maxi;
		}
		else {
			maxi=x[i];
		}
	}
	cout<<c<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--) {
        // solve();
    // }
    solve();
    return 0;
}
