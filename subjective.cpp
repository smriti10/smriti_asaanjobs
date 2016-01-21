
1) Help Sheeba out     10 marks

Sheeba was asked by a Recruiter to write down 100 numbers (1-100) randomly 

but making sure that no number is repeated twice. At the end, the Recruiter found 

out that Sheeba had done her work perfectly, but committed just one mistake of 

repeating a number twice. Recruiter asked Sheeba that she recruiter her only 

under one condition! If Sheeba is able to find out the only number which she is 

repeated in an optimised manner.

Can you write a pseudocode, which can help Sheeba to find out the number which 

got repeated twice?

solution:

#include <stdio.h>
#include <stdlib.h>
 
void printRepeating(int arr[], int size)
{
  int i;
  printf("The repeating element is: \n");
  for (i = 0; i < size; i++)
  {
    if (arr[abs(arr[i])] >= 0)
      arr[abs(arr[i])] = -arr[abs(arr[i])];
    else
      printf(" %d ", abs(arr[i]));
  }
}


Closest to zero     20 Marks

This problem is also called minimum absolute sum pair. You are given an array of integers, 

containing both +ve and -ve numbers. You need to find the two elements such that their sum is 

closest to zero. eg. Array [15, 5, -20, 30, -45] Output should be 15, -20.

Note: We want the sum to be closest to zero not minimum. The minimum in the above example 

would be (-20, -45), but that is incorrect.


solution:
1) Sort all the elements of the input array.
2) Use two index variables l and r to traverse from left and right ends respectively. Initialize l as 0 and r as n-1.
3) sum = a[l] + a[r]
4) If sum is -ve, then l++
5) If sum is +ve, then r–
6) Keep track of abs min sum.
7) Repeat steps 3, 4, 5 and 6 while l < r Implementation

# include <stdio.h>
# include <math.h>
# include <limits.h>
 
void quickSort(int *, int, int);
 

void minAbsSumPair(int arr[], int n)
{

  int sum, min_sum = INT_MAX;
 

  int l = 0, r = n-1;
 
  
  int min_l = l, min_r = n-1;
 
 
  if(n < 2)
  {
    printf("Invalid Input");
    return;
  }
 

  quickSort(arr, l, r);
 
  while(l < r)
  {
    sum = arr[l] + arr[r];
 
    
    if(abs(sum) < abs(min_sum))
    {
      min_sum = sum;
      min_l = l;
      min_r = r;
    }
    if(sum < 0)
      l++;
    else
      r--;
  }
 
  printf(" The two elements whose sum is minimum are %d and %d",
          arr[min_l], arr[min_r]);
}


void exchange(int *a, int *b)
{
  int temp;
  temp = *a;
  *a   = *b;
  *b   = temp;
}
 
int partition(int arr[], int si, int ei)
{
  int x = arr[ei];
  int i = (si - 1);
  int j;
 
  for (j = si; j <= ei - 1; j++)
  {
    if(arr[j] <= x)
    {
      i++;
      exchange(&arr[i], &arr[j]);
    }
  }
 
  exchange (&arr[i + 1], &arr[ei]);
  return (i + 1);
}

arr[] --> Array to be sorted
si  --> Starting index
ei  --> Ending index

void quickSort(int arr[], int si, int ei)
{
  int pi;    
  if(si < ei)
  {
    pi = partition(arr, si, ei);
    quickSort(arr, si, pi - 1);
    quickSort(arr, pi + 1, ei);
  }
}
 
