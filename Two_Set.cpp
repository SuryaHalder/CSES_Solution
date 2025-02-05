/*
	Author : SURYA HALDER
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long int
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
#define mod 1000000007

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
    /* if 1+2+3+...+n is even then possible else no*/
    ll n;
    cin>>n;
    ll s=n*(n+1)/2;
    //cout<<s<<endl;
    if(s%2==0) {
    	cout<<"YES"<<endl;
    	vector<ll> s1;
    	vector<ll> s2;
    	vector<bool> fg(0,n+1);
    	ll req=s/2;
    	for(ll i=n;i>=1;i--){
    		if(req>=i){
    			req-=i;
    			s1.pb(i);
    		}
    		else s2.pb(i);
    	}
    	cout<<s1.size()<<endl;
    	output(s1);
    	cout<<s2.size()<<endl;
    	output(s2);
    }
    else cout<<"NO"<<endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*Multi testcase*/
    // int t;
    // cin >> t;
    // while (t--) {
        // solve();
    // }
    /*comment till here*/
    solve();
    return 0;
}
