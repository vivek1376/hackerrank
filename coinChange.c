#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


int main()
{
    int N, M, C[51], i, j, k, coins[51] = {0}, coin, m;

    long long int ways[251][51] = {{0}}; /* ways[Value][Coins] */

    scanf ("%d %d", &N, &M);	/* N is value */

    /* list of coins */
    for (i = 0; i < M; i++)
    {
        scanf ("%d", &coin);
	// printf ("coin: %d\n", coin); //d
        coins[coin] = 1;
    }

    /* initialise */
    for (i = 0; i <= M; i++)
        ways[0][i] = 1;

    /* for every value of coin, Ci<=50 */

    //    for (i = 50, m = 0; i >= 0 && coins[i]; i--)
    for (i = 1, m = 0; i <= 50; i++)
    {
	if(!coins[i])
	    continue;
	
	//printf("inside\n");//d
        m++;
	//printf("i: %d\n",i);//d
	/* every value upto N */
        for (j = 1; j <= N; j++)
        {
            ways[j][m] = ways[j][m - 1] +
                         ( (j - i) >= 0 ? ways[j - i][m] : 0);

	    // printf("ways[%d][%d]: %d\n",j,m,ways[j][m]);//d
        }
    }

    /*    for (i = 1; i <= N; i++)
        {

            for (j = 1; j < 50 && coins[j]; j++)
            {
                putchar ('^'); //d
                if ( (i - j) >= 0)
                    ways[i] += (ways[i - j]);
            }
        }*/

    printf ("%lld\n", ways[N][M]);

    return 0;
}
