#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//sum squares m^2 + (m +1)^ 2 + ... + n^2
int sumSquaresIterative(int m, int n);
int sumSquaresRecursive(int m, int n);
int sumSquaresGoingDownRecursive(int m, int n);
void runAndCompare(int times);

//Factorial
int iterativeFactorial(int n);
int recursiveFactorial(int n);

int main()
{
  runAndCompare(100);

   printf("factorials : iterative %d , recursive %d\n",iterativeFactorial(8), recursiveFactorial(8));

  exit(0);
}

int recursiveFactorial(int n)
{
  if (n == 1)
  {
    return n;
  }
  else
  {
    return n * recursiveFactorial(n - 1);
  }
}

int iterativeFactorial(int n)
{
  int result = n;

  while (n > 1)
  {
    result *= --n;
  }

  return result;
}

void runAndCompare(int times)
{
  double totalIterative = 0;
  double totalRecursive = 0;
  double totalGDown = 0;

  clock_t begin;
  clock_t end;

  for (int i = 0; i < times; i++)
  {
    begin = clock();
    sumSquaresIterative(5, 10);
    end = clock();
    totalIterative += ((double)(end - begin) / CLOCKS_PER_SEC);

    begin = clock();
    sumSquaresRecursive(5, 10);
    end = clock();
    totalRecursive += ((double)(end - begin) / CLOCKS_PER_SEC);

    begin = clock();
    sumSquaresGoingDownRecursive(5, 10);
    end = clock();
    totalGDown += ((double)(end - begin) / CLOCKS_PER_SEC);
  }

  printf("AVGs: iterarive = %f, recursive = %f, gDown= %f\n", totalIterative / times, totalRecursive / times, totalGDown / times);
}

int sumSquaresGoingDownRecursive(int m, int n)
{
  if (m == n)
  {
    return m * n;
  }
  else
  {
    int middle = ((m + n) / 2);

    return sumSquaresGoingDownRecursive(m, middle) + sumSquaresGoingDownRecursive(++middle, n);
  }
}

int sumSquaresRecursive(int m, int n)
{
  int i = m;
  int sum = 0;

  if (i == n)
  {
    return sum + i * i;
  }
  else
  {
    return (i * i) + sumSquaresRecursive((i + 1), n);
  }
}

int sumSquaresIterative(int m, int n)
{
  int i = m;
  int sum = 0;

  while (i <= n)
  {
    sum += i * i;
    i++;
  }

  return sum;
}