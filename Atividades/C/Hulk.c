#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int n = 0;
    char comp1[14] = "I hate", comp2[14] = "I love";
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            printf(" %s", comp1);
        }
        else
        {
            printf(" %s", comp2);
        }
        if ((i + 1) == n)
        {
            printf(" it ");
        }
        else
        {
            printf(" that ");
        }
    }
    return 0;
}
