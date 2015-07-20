#include<stdio.h>
#define ll long long int
#define lli long int
ll n;
lli mat[24][10000008];
#define mod 1000000007
ll min(ll x1, ll y1)
{
	if(x1<y1)
		return x1;
	return y1;
}
ll max(ll x1, ll y1)
{
	if(x1>y1)
		return x1;
	return y1;
}
void poo()
{
	ll i, j;
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=0;i+(1<<j)-1<n;i++)	
		{
			if(mat[j-1][i]<=mat[j-1][i+(1<<(j-1))])
				mat[j][i]=mat[j-1][i];
			else
				mat[j][i]=mat[j-1][i+(1<<(j-1))];
		}
	}
}
int main()
{
	//std::ios_base::sync_with_stdio(false);
	
	ll k, q, i;
	scanf("%lld%lld%lld", &n, &k, &q);
	//cin>>n>>k>>q;
	ll a, b, c, d, e, f, r, s, t, m;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%ld", &a, &b, &c, &d, &e, &f, &r, &s, &t, &m, &mat[0][0]);
	//cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>arr[0];
	ll l1, la, lc, lm, d1, da, dc, dm;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &l1, &la, &lc, &lm, &d1, &da, &dc, &dm);
	//cin>>l1>>la>>lc>>lm>>d1>>da>>dc>>dm;
	ll prep=t;
	a=a%m;d=d%m;
	b=b%m;e=e%m;
	c=c%m;f=f%m;
	for(i=1;i<n;i++)
	{
		prep=(prep*t)%s;
		if(prep<=r)
			mat[0][i]=(a*mat[0][i-1]*mat[0][i-1] + b*mat[0][i-1] + c)%m;
		else
			mat[0][i]=(d*mat[0][i-1]*mat[0][i-1] + e*mat[0][i-1] + f)%m;
	}
	poo();
	ll x, y;
	ll ans1=0, ans2=1;
	for(i=1;i<=q;i++)
	{
		l1=((la*l1)%lm+lc)%lm;
		d1=((da*d1)%dm+dc)%dm;
		x=l1+1;
		y=min(x+k-1+d1, n);
		x--;
		y--;
		x=min(x, y);
		y=max(x, y);
		ll manish=31-__builtin_clz(y-x+1);
		ll minn=0;
		if(mat[manish][x]<=mat[manish][y-(1<<manish)+1])
			minn=mat[manish][x];
		else
			minn=mat[manish][y-(1<<manish)+1];
		ans1+=minn;
		ans2=(ans2*minn)%mod;
	}
	if(ans2<0)
		ans2=ans2+mod;
	printf("%lld %lld\n",ans1,ans2);
	//cout<<ans1<<" "<<ans2<<"\n";

	return 0;
} 
