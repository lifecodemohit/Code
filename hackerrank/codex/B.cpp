/*
Author : lifecodemohit
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

int cnt[10000005];

long long mod = 1e9+7;

void sieve() {
	for (int i = 1; i <= 1e7; i++)
		cnt[i] = 1;
	for (int i = 2; i <= 1e7; i++) {
		for (int j = i; j <= 1e7; j += i)
			cnt[j]++;
	}
}

long long pow_mod(long long x, long long e) {
	if (e == 0)	return 1;
	if (e == 1)	return x%mod;
	long long res = pow_mod(x, e/2);
	res = (res * res) % mod;
	if (e & 1)
		res = (res * x) % mod;
	return res;
}

int main()
{
	sieve();
	int a, b, n, ctr = 0;
	cin >> a >> b >> n;
	for (int i = a; i <= b; i++) {
		if (cnt[i] == n)
			ctr++;
	}
	cout << pow_mod(ctr, (b-a+1)-ctr)<< endl;
	return 0;
}