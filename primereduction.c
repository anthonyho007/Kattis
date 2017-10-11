#include <stdio.h>
#include <math.h>

int sum_primeFactors(long long n) {
  long long sum = 0;
  while (n %2 == 0) {
    sum += 2;
    n /=2;
  }
  long long limit = sqrt(n);
  for ( int i = 3; i <= limit;  i = i+2) {
    while (n %i == 0) {
      sum += i;
      n = n/i;
    }
  }
  if ( n > 2) {
    sum += n;
  }
  return sum;
}

int main () {
 long long n;
 
 while ( scanf("%lld", &n) == 1 && n != 4 ) {
    int ctr = 1;
    long long target = n;
    long long sum =0;
    while ((sum = sum_primeFactors(target)) != target) {
      target = sum;
      ctr++;
    }
    printf("%lld %d\n", sum, ctr);
 }
 
 return 0;
}
