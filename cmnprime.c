#include<stdio.h>
#include<math.h>

int countPrimeFactors(int x)
{
    int res = 0;
    if (x % 2 == 0)
    {
        res++;
        while (x % 2 == 0)
            x = x / 2;
    }

    for (int i = 3; i <= sqrt(x); i = i + 2) {
        if (x % i == 0)
        {
            res++;
            while (x % i == 0)
                x = x / i;
        }
    }
    if (x > 2)
        res++;
    return res;
}

int Gcd(int a, int b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;
    if (a == b)
        return a;
    if (a > b)
        return Gcd(a-b, b);
    else
        return Gcd(a, b-a);
}

int countCommonPrimeFactors(int a, int b)
{
    int gcd=Gcd(a, b);
    return countPrimeFactors(gcd);
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int k=countCommonPrimeFactors(a, b);
    printf("%d",k);
    return 0;
    printf("some new change.");
}
