# include <stdio.h>
# include <string.h>

int main(){
	int test;
	scanf("%d", &test);
	while(test--){
		char f[10], t[10], b[10], d[10], l[10], r[10];
		scanf("%s", f);
		scanf("%s", b);
		scanf("%s", l);
		scanf("%s", r);
		scanf("%s", t);
		scanf("%s", d);

// frt flt brt blt frd fld rbd lbd

		if(strcmp(f,r)==0 && strcmp(f,t) ==0)
			printf("YES\n");
		else if(strcmp(f,l)==0 && strcmp(f,t) ==0)
			printf("YES\n");
		else if(strcmp(b,t)==0 && strcmp(b,r) ==0)
			printf("YES\n");
		else if(strcmp(b,t)==0 && strcmp(b,l) ==0)
			printf("YES\n");
		else if(strcmp(f,r)==0 && strcmp(f,d) ==0)
			printf("YES\n");
		else if(strcmp(f,l)==0 && strcmp(f,d) ==0)
			printf("YES\n");
		else if(strcmp(r,b)==0 && strcmp(r,d) ==0)
			printf("YES\n");
		else if(strcmp(l,b)==0 && strcmp(l,b) ==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}