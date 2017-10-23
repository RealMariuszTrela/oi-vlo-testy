#include <bits/stdc++.h>
using namespace std;
using pi=pair<int, int>;
#define st first
#define nd second
const int N=5e5+5, M=1e6;
int l[N], d[N], l1[N], d1[N];
vector<pi> g[N];
void dfs(int v, int p, int* t)
{
	for(auto i: g[v]) if(i.st!=p)
	{
		t[i.st]=t[v]+i.nd;
		dfs(i.st, v, t);
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	ifstream out;
	out.open(argv[1]);
	string s;
	out >> s;
	int n=1;
	while(1)
	{
		int a, b, w;
		out >> a >> b >> w;
		if(!out.good()) break;
		++n;
		assert(1<=w&&w<=M);
		assert(1<=a&&a<N&&1<=b&&b<N);
		g[a].push_back(pi(b, w));
		g[b].push_back(pi(a, w));
	}
	freopen(argv[3], "r", stdin);
	int nn;
	cin >> nn;
	for(int i=2; i<nn; ++i) cin >> d[i];
	for(int i=2; i<nn; ++i) cin >> l[i];
	string s1;
	freopen(argv[2], "r", stdin);
	cin >> s1;
	//cerr << s << s1 << " " << argv[0] << " " << argv[1] << " " << argv[2] << " " << argv[3] << "\n";
	assert(s==s1);
	if(s=="NIE")
	{
		assert(n==1);
		cout << "OK\n";
		return 0;
	}
	assert(n==nn);
	dfs(1, 0, d1);
	dfs(n, 0, l1);
	for(int i=2; i<n; ++i) assert(l1[i]==l[i]&&d1[i]==d[i]);
	cout << "OK\n";
}
