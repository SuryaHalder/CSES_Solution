/*
	Author : SURYA HALDER
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long int
#define ff first
#define ss second
#define inf INT_MAX
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
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl


//==============Modular arithematic==============//
const int mod=1000000000+7; 
ll mod_pow(ll a,ll b){
    if(b==0) return 1;
    if(b%2){
        return a* mod_pow(a,b-1) %mod;
    }
    ll temp= mod_pow(a,b/2);
    return temp*temp %mod;
}
ll mod_mul(ll a,ll b){
    return ((a%mod) * (b%mod))%mod;
}
ll mod_add(ll a,ll b){
    return ((a%mod) + (b%mod))%mod;
}
ll mod_sub(ll a,ll b){
    return ((a%mod) - (b%mod))%mod;
}
ll mod_inv(ll a,ll b=mod-2){
    return mod_pow(a,b);
}
ll mod_div(ll a,ll b){
    int invb=mod_inv(b);
    return mod_mul(a,invb);
}
//==============End of Modular Arithematic==============//

//==============i/p and o/p==============//
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
//==============end of i/p and o/p==============//

//==============sorting==============//
template<typename T>
void sortA(vector<T>& v) {
    sort(v.begin(), v.end());
}

template<typename T>
void sortD(vector<T>& v) {
    sort(v.begin(), v.end(), greater<T>());
}
//==============End of sorting==============//
class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int leader(int v) {
        if (parent[v] == v) return v;
        return parent[v] = leader(parent[v]);  // Path compression
    }

    void merge(int u, int v) {
        u = leader(u);
        v = leader(v);
        if (u != v) {
            if (size[u] < size[v]) swap(u, v);  // Union by size
            parent[v] = u;
            size[u] += size[v];
        }
    }

    bool same(int u, int v) {
        return leader(u) == leader(v);
    }
};
void solve() {
    /*Your code here */
    /*Took help from AryanC code*/
    /*DSU implementation class taken from Chatgpt*/
    int n,m;
    cin>>n>>m;
    DSU d(n);
    vector<pair<int,int>> extra;
    set<int> ld;
    for(int i=0;i<n;i++) ld.insert(i);
    auto merge=[&](int u,int v){
    	u=d.leader(u);
    	v=d.leader(v);
    	ld.erase(u);
    	ld.erase(v);
    	d.merge(u,v);
    	int l=d.leader(u);
    	ld.insert(l);
    };
    for(int i=1;i<=m;i++){
    	int u,v;
    	cin>>u>>v;
    	u--;
    	v--;
    	if(d.same(u,v)){
    		extra.pb({i,v});
    		continue;
    	}
    	merge(u,v);
    }
    cout<<ld.size()-1<<endl;
    for(auto it:extra){
    	if(ld.size()==1) break;
    	int cable=it.ff;
    	int v=it.ss;
    	int connect=*ld.begin();
    	if(d.same(connect,v)){
    		connect=*ld.upper_bound(connect);
    	}
    	cout<<cable<<" "<<v+1<<" "<<connect+1<<endl;
    	merge(connect,v);
    }
    
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //==============Multi testcase==============//
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    //==============comment till here==============//
    
    //==============ATCODER ALERT..don't forget to uncomment below==============//
    
    //solve();
    return 0;
}
