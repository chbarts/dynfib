typedef unsigned long long int ulli;

ulli dynfib(ulli n)
{
    ulli prev = 0, cur = 1, new, i;

    if (0 == n)
        return 0;
    else {
        for (i = 0; i < (n - 1); i++) {
            new = prev + cur;
            prev = cur;
            cur = new;
        }
    }

    return cur;
}
