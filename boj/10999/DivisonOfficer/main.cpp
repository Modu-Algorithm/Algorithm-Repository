#include<iostream>
#include<vector>

using namespace std;

#define ll long long

class SEG_LAZY{
	//Segment Tree Item
	vector<ll> tree;
	//Lazied update value
	vector<ll> lazy;
	//Init tree leafs
	vector<ll> init_leaf;
	ll n;
	public:
	SEG_LAZY(int n){
		this -> n = n;
		tree.resize(4*n);
		lazy.resize(4*n);
	}
	//Init tree until reached the leaf.
	//Return the sum of the child as current node value.
	ll init(int node, int s, int e){
		if(s == e)	return tree[node] = init_leaf[s];
		int mid = (s + e) / 2;
		tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
		return tree[node];
	}

	void init(vector<ll> init_leaf){
		this -> init_leaf = init_leaf;
		init(1, 1, n);
	}
	// Propagate the lazy value to the child.
	void prop(int node, int s, int e){
		tree[node] += lazy[node] * (e - s + 1);
		if(s != e){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	// Update lazy value
	// Each step, propagate the pending lazy value
	ll update(int node, int l, int r, int s, int e, ll val){
		prop(node, s, e);
		// if s~e is out of range, return current node value.
		if(e < l || s > r) return tree[node];
		// if s~e is in l~r, update lazy value.
		if(l <= s && r >= e){
			lazy[node] += val;
			prop(node, s, e);
			return tree[node];
		}
		int mid = (s + e) / 2;
		// if s~e is not in l~r but partially overlapped, search child nodes.
		return tree[node] = 
		update(node*2, l, r, s, mid, val) + update(node*2+1, l, r, mid+1, e, val);
	}


	ll sum(int node, int l, int r, int s, int e){

		prop(node, s, e);

		if(e < l || s > r) return 0;
		if(l <= s && r >= e) return tree[node];
		int mid = (s + e) / 2;
		return sum(node*2, l, r, s, mid) + sum(node*2+1, l, r, mid+1, e);
	}


};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q, q2;
	cin >> n >> q >> q2;
	q += q2;
	SEG_LAZY seg(n);
	vector<ll> in;
	in.push_back(0);
	for(int i=0;i<n;i++){
		ll x;
		cin >> x;
		in.push_back(x);
	}
	seg.init(in);

	while(q--){
		int Q;
		cin >> Q;
		if(Q == 1){
			int x, y;
			long long v;
			cin >> x >> y >> v;
			seg.update(1, x, y, 1, n, v);
		}
		else{
			int x, y;
			cin >> x >> y;
			cout << seg.sum(1, x, y, 1, n) << "\n";
		}
	}
	return 0;
}