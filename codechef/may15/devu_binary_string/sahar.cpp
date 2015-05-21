#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int t,n,k,cnt,ctr;
	scanf("%d",&t);
	//char str[100000];
	char lastBit;
	for(int tc=0;tc<t;tc++)
	{
		scanf("%d %d",&n,&k);
		char str[n];
		scanf("%s",str);
		//long long len=strlen(str);
		if(k!=1)
		{
			cnt=0;   //final count
			for(int i=0;i<n-k;i++)
			{
				ctr=0;  //temp count for k
				lastBit=str[i];
				for(int j=1;j<k+1;j++)
				{
					if(str[i+j]==lastBit)	
					{
						ctr++;
						if(ctr==k)
						{
							if(str[i+j+1]==lastBit)
							{
								if(str[i+j]=='0')
								{
									str[i+j]='1';
									cnt++;
									ctr=0;
									break;
								}
								else if(str[i+j]=='1')
								{
									str[i+j]='0';
									cnt++;
									ctr=0;
									break;
								}
							}
							else
							{
								if(str[i+((k/2))]=='0')
								{
									str[i+((k/2))]='1';
									cnt++;
									ctr=0;
									break;
								}
								else if(str[i+((k/2))]=='1')
								{
									str[i+((k/2))]='0';
									cnt++;
									ctr=0;
									break;
								}
							}
						}
					}
					else
					{
						ctr=0;
					}
					lastBit=str[i+j];
				}
			}
			printf("%d\n",cnt);
			printf("%s\n",str);
		}

		else 
		{
			ctr=0;
			cnt=0;
			lastBit=str[0];
			for(int i=1;str[i]!='\0';i++)
			{
				//printf("Original: %c\n",str[i]);
				if(str[i]==lastBit)
				{
					ctr++;
					if(ctr==1)
					{
						cnt++;
						if(str[i]=='0')
						{
							str[i]='1';
							//printf("flipped: %c\n",str[i]);
						}
						else if(str[i]=='1')
						{	
							str[i]='0';
							//printf("flipped: %c\n",str[i]);
						}
						ctr=0;
					}
				}
				else
				{
					ctr=0;
				}
				lastBit=str[i];
			}
			if(cnt>(n/2))
			{
				cnt=n-cnt;
				for(int j=0;str[j]!='\0';j++)
				{
					if(str[j]=='0')
						str[j]='1';
					else if(str[j]=='1')
						str[j]='0';
				}
			}
			printf("%d\n",cnt);
			printf("%s\n",str);
		}
		
	}
	return 0;
}