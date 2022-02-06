#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int a[MAX], front = -1, rear = -1;

void
insert (int ele)
{
  if (front == -1 && rear == -1)
    {
      front = rear = 0;
      a[rear] = ele;
      return;
    }
  if (rear == MAX - 1)
    {
      printf ("QUEUE OVERFLOW\n");
      return;

    }
  else
    {
      rear = rear + 1;
      a[rear] = ele;
      return;
    }


}

void
delete ()
{
  if (front == -1 && rear == -1)
    {
      printf ("Queue underflow\n");
      return;
    }
  if (front == rear)
    {
      front = rear = -1;
      return;
    }
  else
    {
      front = front + 1;
    }

}

void
display ()
{
  int i;
  if (front == -1 && rear == -1)
    {
      printf ("Queue underflow\n");
      return;
    }
  for (i = front; i <= rear; i++)
    {
      printf ("%d ", a[i]);
    }
  printf ("\n");
}

int
main ()
{
  int choice;
  int ele;
  while (1)
    {
      printf ("Enter the choice\n");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:

	  printf ("Enter the element to be inserted\n");
	  scanf ("%d", &ele);
	  insert (ele);
	  break;

	case 2:
	  delete ();
	  break;

	case 3:
	  display ();
	  break;

	case 4:
	  printf ("Exit\n");
	  return 0;
	  break;
	}
    }
}
