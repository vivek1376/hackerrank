#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

void mulStringNum (char *num1, char *num2, char *prod);
void stringAdd(char *num1, char *num2, char *res);

int main()
{
    int ww;
    ww = 12;
    ww = ww - (ww / 10) * 10;
    //printf("ww %d\n",ww);//d
    int A, B, N, i;
    //unsigned long long int fib = 0;

    //char sss[100];
    //stringAdd("1111","222131322",sss);//d
    //printf("sum: %s\n",sss);//d
    //return 0;

    char *prod=(char *)malloc(sizeof(char)*2200000);
    char *A_str=(char *)malloc(sizeof(char)*2200000);
    char *B_str=(char *)malloc(sizeof(char)*2200000);
    char *fib=(char *)malloc(sizeof(char)*2200000);
    
    //char prod[100], A_str[100], B_str[100], fib[100];		 /* size enough */
    memset (prod, 0, 2200000);		 /* zero out */
    memset (A_str, 0, 2200000);		 /* zero out */
    memset (B_str, 0, 2200000);		 /* zero out */
    memset (fib, 0, 2200000);		 /* zero out */
    
    //mulStringNum ("12300", "923", prod); //d

    //printf ("prod: %s\n", prod); //d
    //return 0;

    scanf ("%d %d %d", &A, &B, &N);
    A_str[0]=A+48;
    B_str[0]=B+48;
    
    if (N == 1)
        strcpy(fib,"0");

    if (N == 2)
	strcpy(fib,"1");

    N = N - 2;

    for (i = 0; i < N; i++)
    {
	//printf("i: %d\n",i+2);//d
	mulStringNum(B_str, B_str, prod);
	stringAdd(prod, A_str, fib);
        //fib = B * B + A;

	strcpy(A_str,B_str);
	strcpy(B_str,fib);
        //A = B;
        //B = fib;
    }

    printf ("%s", fib);
    return 0;
}

void stringAdd(char *num1, char *num2, char *res)
{
    int l1,l2,i,j,k,carry,p;
    char ch;

    l1=strlen(num1);
    l2=strlen(num2);

    char *sum=(char *)malloc(sizeof(char)*(MAX(l1,l2)+2));

    for(i=l1-1,j=l2-1,carry=0, p=0; i>=0 || j>=0 || carry>0; i--,j--,p++)
    {
	k=(i>=0?num1[i]-48:0)+
	    (j>=0?num2[j]-48:0)+carry;
	
	if(k>9)
	{
	    carry=k/10;
	    k=k-((k/10)*10);
	}
	else
	    carry=0;

	sum[p]=k+48;
    }

    sum[p]='\0';
    //printf("sum: %s\n",sum);//d
    
    /* reverse */
    for(i=0,j=p-1;i<j;i++,j--)
    {
	ch=sum[i];
	sum[i]=sum[j];
	sum[j]=ch;
    }
    
    strcpy(res,sum);
    free(sum);
}

void mulStringNum (char *num1, char *num2, char *prod)
{
    int l1, l2, i, j, k, m, n, carry, oldCarry, q, sCarry;
    char *intrmProd, *intrmSum, t;

    l1 = strlen (num1);
    l2 = strlen (num2);

    //printf ("<l1_l2> %d %d\n", l1, l2); //d
    intrmProd = (char *) malloc (sizeof (char) * (l1 + l2 + 2)); /* (l1+l2+2) size denote max size of
								    product. think 99*99[100*100] */
    intrmSum = (char *) malloc (sizeof (char) * (l1 + l2 + 2));
    
    memset (intrmSum, 0, sizeof (char) * (l1 + l2 + 2)); 

    /* iterate over each digit of the second multiplicand
       in the outer loop */
    for (i = 0; i < l2; i++)
    {
        k = i;
        carry = 0;
        memset (intrmProd, 0, sizeof (char) * (l1 + l2 + 2));
        /* each digit of upper multiplicand */
        for (j = 0; j < l1 || carry > 0; j++, k++)
        {
            m = (int) ( ( (l2 - 1 - i) >= 0 ? num2[l2 - 1 - i] - 48 : 0) *
			( (l1 - 1 - j) >= 0 ? num1[l1 - 1 - j] - 48 : 0)) + carry;

            if (m > 9)
            {
                carry = m / 10;
                m = m - ( (m / 10) * 10);
            }
            else
                carry = 0;
	    
	    intrmProd[k] = m;	/* number is stored in reverse */
        }

        /* after calculating intermediate product
           sum it to the previous intrmSum */
        for (j = 0, carry = 0; j < k || carry > 0; j++)
        {
            m = intrmSum[j] + intrmProd[j] + carry;

            if (m > 9)
            {
                carry = m / 10;
                m = m - ( (m / 10) * 10);
            }
            else
                carry = 0;

            intrmSum[j] = m;
        }
    }
    k=j;			/* k stores length of
				   product */

    /* now make them ASCII characters by 
       adding 48 */
    for (i = 0; i < k; i++)
	intrmSum[i] += 48;
    
    intrmSum[k]='\0';		/* null character */

    /* now reverse the digits */
    for (i = 0, j = k - 1; i < j; i++, j--)
    {
        t = intrmSum[i];
        intrmSum[i] = intrmSum[j];
        intrmSum[j] = t;
    }

    strcpy (prod, intrmSum);

    free(intrmProd);
    free(intrmSum);
}


