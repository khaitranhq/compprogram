#include <stdio.h>

long long k;
long long revr(long long k)
{
  long long kr = 0;
  int no[] = {3, 4, 7};
  while (k > 0)
  {
    int d = (k % 10);
    if (d == 6)
    {
      d = 9;
    }
    else
    {
      if (d == 9) d = 6;
    }
    for (int i = 0; i < 3; i++)
    {
      if (d == no[i])
        return -1;
    }

    kr = kr * 10 + d;
    k = k / 10;
  }
  return kr;
}

int prime(long long k)
{
  if (k == 1 || k == 0)
    return 0;
  if (k == 2)
    return 1;
  if (k % 2 == 0)
    return 0;
  for (long long d = 3; d*d <= k; d += 2)
  {
    if (k % d == 0)
      return 0;
  }
  return 1;
}

int main()
{
  long long n;
  scanf("%lld", &n);
  long long nr = revr(n);
  //printf("%lld %lld\n", n, nr);
  if (nr == -1)
  {
    printf("no\n");
    return 0;
  }

  if (prime(n) && prime(nr))
    printf("yes\n");
  else
    printf("no\n");
}



