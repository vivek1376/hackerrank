/* https://www.hackerrank.com/challenges/candies 
   ACCEPTED */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMCHILDREN 100000

int main()
{
    int N,i,j;
	long long int totalCandies;
	
    int *rating=(int *)malloc((NUMCHILDREN+1)*sizeof(int));
    int *candies=(int *)malloc((NUMCHILDREN+1)*sizeof(int));
	//return 0;//d
    scanf("%d",&N);
	//candies[0]=1;//d
	//return 0;//d
	
	for(i=0;i<N;i++)
		scanf("%d",&rating[i]);
	
	for(i=0;i<N;i++)
		candies[i]=1;
    
	//return 0;//d
	
	
	for(i=1;i<N;i++)
	{
		if(rating[i]>rating[i-1])
			if(candies[i]<=candies[i-1])
				candies[i]=candies[i-1]+1;
	}
	
	for(i=N-2;i>=0;i--)
	{
		if(rating[i]>rating[i+1])
			if(candies[i]<=candies[i+1])
				candies[i]=candies[i+1]+1;
	}
	
	for(i=0,totalCandies=0;i<N;i++)
		totalCandies+=candies[i];
	
	printf("%lld",totalCandies);
	
	return 0;
}
