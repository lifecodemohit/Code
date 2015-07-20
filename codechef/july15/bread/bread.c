#include <stdio.h>
int main(){
	int test;
	scanf("%d", &test);
	while(test--){
		long long int N, K, i;
		scanf("%lld %lld", &N, &K);
		long long int A[N];
		for(i=0; i<N; i++)
			scanf("%lld", &A[i]);
		long long int pack_finished = 1; //boolean variable
		long long int num_of_packs = 0;
		long long int left_in_current_pack = 0;


		for(i=0; i<N; i++){
			if (pack_finished==1){
				num_of_packs++;
				left_in_current_pack = K;
				pack_finished = 0;
			}
			if(A[i]<=left_in_current_pack){
				left_in_current_pack -= A[i];
				if(left_in_current_pack <=1){
					left_in_current_pack = 0;
					pack_finished = 1;
				}
				else{
					pack_finished = 0;
					left_in_current_pack-=1;
				}
			}
		
			// if A[i] > left_in_current_pack
			else{
				// finish the current pack
				if(pack_finished==0){
					A[i]-=left_in_current_pack;
					pack_finished = 1;
				}

				// number of fulll packs consumed
				long long int full_packs = 0;
				full_packs = A[i]/K;
				num_of_packs+=full_packs;
				A[i] -= full_packs*K;
				pack_finished = 1;

				// finishing the left demand
				if(A[i]>0){
					num_of_packs++;
					left_in_current_pack = K-A[i];					
					if(left_in_current_pack <=1){
						left_in_current_pack = 0;
						pack_finished = 1;
					}
					else{
						pack_finished = 0;
						left_in_current_pack-=1;
					}
				}
			}
			// printf("%d ", num_of_packs);				
		}
		printf("%lld\n", num_of_packs);
	}
	return 0;
}