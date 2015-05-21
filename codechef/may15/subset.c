#include<stdio.h>
#include<math.h>
/*
void main()
{
	int no_of_element,no_of_subset,i,j,start,index,a[50],x, sum = 0;
	printf("Enter the size of main set :");
	scanf("%d",&no_of_element);
	printf("Enter the elements of main set :");
	for(x=0;x<no_of_element;x++)
		scanf("%d",&a[x]);

	printf("The subsets are :\n");
	
	for(no_of_subset=1;no_of_subset<=no_of_element;no_of_subset++){
		for(start=0;start<=no_of_element-no_of_subset;start++){
			if(no_of_subset==1)
				printf("%d\n",a[start]);
			else{
				index=start+no_of_subset-1;
				for(j=index;j<no_of_element;j++){
					for(i=start;i<index;i++)
						printf("%d ",a[i]);
					printf("%d\n",a[j]);
				}
			}
		}
	}
}
 */

void PrintSubsets(int source[], int n) 
{ 
	float z = n;
	int x = (int)pow((2),z);
	int currentSubset = x; 
	int tmp; 
	while(currentSubset){ 
		tmp = currentSubset; 
		int i;
		for(i = 0; i<n; i++){ 
			if (tmp & 1) 
			printf("%d ", source[i]); 
			tmp /= 2;
		} 
		printf("\n"); 
		currentSubset--; 
	} 
}
void main(){
	int source[3] = {1,2,3};
	PrintSubsets(source, 3);
}