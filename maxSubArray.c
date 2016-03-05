#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define ARRAY_SIZE 100002

int main()
{
    int T, N, i, begin, end;
    int *A = (int *) malloc (sizeof (int) * ARRAY_SIZE);

    long long int subArrSum = 0, subSeqSum = -10000, subArrSumTemp = -10000, subSeqSumTemp = -10000;
    scanf ("%d", &T);

    while (T--)
    {
        scanf ("%d", &N);

        for (i = 0; i < N; i++)
        {
            scanf ("%d", &A[i]);
        }

        begin = end = subArrSumTemp = 0;
        subArrSum = LLONG_MIN;
        for (i = 0; i < N; i++)
        {
            subArrSumTemp += A[i];

            if (subArrSumTemp > subArrSum)
                subArrSum = subArrSumTemp;

            if (subArrSumTemp < 0)
            {
                begin = i;
                subArrSumTemp = 0;
                //subArrNeg=MAX(subArrNeg,A[i]);
            }

            //else if(subArrSumTemp>subArrSum)
            //subArrSum=subArrSumTemp;
        }
        printf ("%lld ", subArrSum);

        subSeqSumTemp = 0;
        subSeqSum = LLONG_MIN;
        for (i = 0; i < N; i++)
        {
            if (A[i] < 0)
            {
                if (A[i] > subSeqSum)
                    subSeqSum = A[i];
            }
            else
            {
                subSeqSumTemp += A[i];

                if (subSeqSumTemp > subSeqSum)
                    subSeqSum = subSeqSumTemp;
            }
        }
        printf ("%lld\n", subSeqSum);
    }

    /*
    while(T--)
    {
    scanf("%d",&N);

    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    //	    printf("%d\n",A[i]);//d
    }

    subArrSum=-10000;
    for(i=0;i<N;i++)
    {
    //	    printf("\n\nnew:\n");//d
        subArrSumTemp=0;
        for(j=i;j<N;j++)
        {
    //

    	subArrSumTemp=subArrSumTemp+A[j];
    	//printf("subarrtemp: %lld\tsubarrsum: %lld\n",subArrSumTemp,subArrSum);//d
    	if(subArrSumTemp>subArrSum)
    	{
    	    subArrSum=subArrSumTemp;
    	    //printf("cmp\n");//d
    	}
        }
    }
    //	printf("--subarrsum: %lld",subArrSum);
    printf("%lld",subArrSum);

    subSeqSum=-10000;
    for(i=0; i<N; i++)
    {
        subSeqSumTemp=0;

        for(j=i;j<N;j++)
        {
    	if(subSeqSumTemp+A[j]>subSeqSum)
    	{
    	    subSeqSumTemp+=A[j];
    	    subSeqSum=subSeqSumTemp;
    	}
    	//   subSeqSumTemp+=A[j];

    	//if(subSeqSumTemp>subSeqSum)
    	//  subSeqSum=subSeqSumTemp;
        }
    }
    printf(" %lld\n",subSeqSum);
    }*/

    return 0;
}
