#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	ifstream out, in, correct;
	out.open(argv[1]);
	in.open(argv[3]);
	correct.open(argv[2]);
	int resout, rescor;
	out >> resout;
	correct >> rescor;
	assert(resout==rescor);
	int n, k;
	in >> n >> k;
	vector<int> a(n+1), b(n+1);
	for(int i=1; i<=n; ++i) in >> a[i] >> b[i];
	int mxa=0, mnb=1e9;
	vector<int> v;
	while(1)
	{
		int x;
		out >> x;
		if(!out.good()) break;
		v.push_back(x);
	}
	assert(v.size()==k);
	for(int i: v)
	{
		mxa=max(mxa, a[i]);
		mnb=min(mnb, b[i]);
	}
	assert(mnb-mxa==rescor);
	printf("OK\n");
}
