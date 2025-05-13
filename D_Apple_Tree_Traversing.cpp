
/*
	Author : SURYA HALDER

    
    "I'm so lost in this problem, I might need a GPS to find my way out."
	"My love I know you are reading my code to get a path out of your errors, just like your presence in my life is a path out my errors,
	so please talk instead of ignoring me"
	"I may die today but for sure will be reborn tommorow like the phoenix"...
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long int
#define ff first
#define ss second
#define inf INT_MAX
#define sz size()
#define rtn return
#define rnt return
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define pb push_back
#define endl '\n'
#define maxheap priority_queue<int> //max heap
#define minheap priority_queue <int, vector<int>, greater<int>> //min heap
#define loop(i,a,b) for(int i=a;i<b;i++)     //for loop from a(included)->b(excluded)
#define roop(i,b,a) for(int i=b;i>=a;i--)    //rev. for loop from b(included)->a(inluded)
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
void inp(vector<T>& v) {
    for (auto& x : v) {
        cin >> x;
    }
}
template<typename T>
void out(const vector<T>& v) {
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

int dr[]={-1,0,1,0}; //up,left,down,right
int dc[]={0,-1,0,1};
bool in(int i,int j,int n,int m){
    rtn (i>=0 && i<n && j>=0 && j<m);
}
int depth[150005];
bool del[150005];
int par[150005];
vector<pair<int,int>> collect;
vector<int> adj[150005];
vector<array<int,3>> ans;
void dfs(int u,int p){
    depth[u]=depth[p]+1;
    par[u]=p;
    collect.pb({depth[u],u});
    for(auto it:adj[u]){
        if(it!=p && !del[it]){
            dfs(it,u);
        }
    }
    
}

void dia(int s){
    collect.clear();
    dfs(s,0);
    sortD(collect);
    int d1=collect[0].ff;
    int u=collect[0].ss;
    collect.clear();
    dfs(u,0);
    sortD(collect);
    int d2=collect[0].ff;
    int v=collect[0].ss;
    collect.clear();
    int x=max({u,v});
    collect.clear();
    dfs(x,0);
    sortD(collect);
    int d=collect[0].ff;
    int y=collect[0].ss;
    vector<int> path;
    for(int i=y;i!=0;i=par[i]){
        path.pb(i);
    }
    reverse(path.begin(),path.end());
    for(auto it:path){
        del[it]=true;
    }
    ans.pb({d,x,y});
    for(auto it:path){
        for(int nx:adj[it]){
            if(!del[nx]){
                dia(nx);
            }
        }
    }
}

void solve() {
    /*Your code here */
    int n;
    cin>>n;
    ans.clear();
    for(int i=1;i<=n;i++){
        adj[i].clear();
        del[i]=false;
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // for(int i=1;i<=n;i++){
    //     if(!del[i]){
    //         dia(i);
    //     }
    // }
    dia(1);
    sortD(ans);
    for(auto it:ans){
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<" ";
    }
    cout<<endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //==============Multi testcase==============//
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    //==============comment till here==============//
    
    //==============ATCODER ALERT..don't forget to uncomment below==============//
    
    //solve();
    return 0;
}
