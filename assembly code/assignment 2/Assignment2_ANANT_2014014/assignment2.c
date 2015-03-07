int fibo(int a)
{
	if ((a==1)||(a==0)) {
		return 1;
	}
	else {
		return (fibo(a-1) + fibo(a-2));
	}
}

int main()
{
	int i;
	for (i=0; i<20; i++) {
		printf("%d\n", fibo(i));
	}
	return 0;
}