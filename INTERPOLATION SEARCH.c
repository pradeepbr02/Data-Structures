#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int a[MAX];

int
interpolation (int ele)
{
  int pos = 0;
  int low = 0;
  int high = MAX - 1;
  while (low <= high)
    {
      pos = low + ((ele - a[low]) / (a[high] - a[low])) * (high - low);
      if (a[pos] == ele)
	{
	  return pos;
	}
      else if (a[pos] > ele)
	{
	  high = pos - 1;
	}
      else
	{
	  low = pos + 1;
	}
    }
  return -1;

}

int
main ()
{
  int ele;
  int position;
  printf ("Enter the elements of the array\n");
  for (int i = 0; i < MAX; i++)
    {
      scanf ("%d", &a[i]);
    }
  printf ("Enter the element to search\n");
  scanf ("%d", &ele);
  position = interpolation (ele);
  printf ("The element is present in the position %d", position);
}
