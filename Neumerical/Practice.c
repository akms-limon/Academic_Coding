#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int test;
    scanf("%d", &test);
    while (test--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int boy[n], girl[m];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &boy[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &girl[i]);
        }
        int boy_even = 0, boy_odd = 0, girl_even = 0, girl_odd = 0;
        for (int i = 0; i < n; i++)
        {
            if (boy[i] % 2 == 0)
            {
                boy_even=boy_even+1;
            }
            else
            {
                boy_odd=boy_odd+1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (girl[i] % 2 == 0)
            {
                girl_even++;
            }
            else
            {
                girl_odd++;
            }
        }
        int ans = 0;
        if (boy_even <= girl_even)
        {
            ans += boy_even;
        }
        else
        {
            ans += girl_even;
        }

        if (boy_odd <= girl_odd)
        {
            ans += boy_odd;
        }
        else
        {
            ans += girl_odd;
        }
        printf("%d\n", ans);
    }
    return 0;
}