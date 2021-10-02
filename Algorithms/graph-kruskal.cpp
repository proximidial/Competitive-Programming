#include<bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define ordered_set tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update> 

#define ll long long
#define ull unsigned ll
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vs vector<string>
#define vvi vector<vi>
#define vvll vector<vll>
#define ff first
#define ss second
#define pb push_back
#define vpi vector<pi>
#define vpll vector<pll>
#define umap unordered_map
#define uset unordered_set
#define all(x) x.begin(),x.end()
#define fr(i,j,n) for(int i=j;i<n;++i)
#define rfr(i,j,n) for(int i=j; i>=n;--i)
#define MOD 1000000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX  
#define mp make_pair
#define endl "\n"
#define sz  size()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<int> parent, rk;
void make_set(int i){
    parent[i] = i;
    rk[i] = 0;
}

int find_set(int i){
    if(i != parent[i]){
        parent[i] = find_set(parent[i]);
    }
    return parent[i];
}

void union_set(int a ,int b){
    int pa = find_set(a);
    int pb = find_set(b);
    if(pa == pb){
        return;
    }
    if(rk[a] < rk[b]){
        swap(a,b);
    }
    parent[b] = a;
    if(rk[a] == rk[b]){
        rk[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;
int cost = 0;
vector<Edge> result;

void kruskal(){
    parent.resize(n);
    rk.resize(n);
    fr(i,0,n){
        make_set(i);
    }
    sort(all(edges));
    for(auto e : edges){
        if(find_set(e.v) != find_set(e.u)){
            cost += e.weight;
            result.pb(e);
            union_set(e.u,e.v);
        }
    }
}

void solve(){

}

void pre() {
    int t = 1;
    // cin>>t;
    fr(i,0,t){
        // cout<<"Case #"<<i+1<<": ";
        solve();
        // cout<<solve()<<endl;
    }
}

int main() {
	fastIO; 

	auto start = clock();

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	pre();

	double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;

	return 0; 
	
}
