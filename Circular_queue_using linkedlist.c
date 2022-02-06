#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void
insert ()
{
  Node *new_node;
  int ele;
  new_node = (Node *) malloc (sizeof (Node));
  if (new_node == NULL)
    {
      printf ("No memory available\n");
      return;
    }
  printf ("Enter the element to be inserted\n");
  scanf ("%d", &ele);
  new_node->data = ele;
  new_node->next = NULL;
  if (front == NULL && rear == NULL)
    {
      rear = front = new_node;
      new_node->next = front;
      return;
    }
  else
    {
      rear->next = new_node;
      rear = new_node;
      new_node->next = front;
      return;
    }


}

void
delete ()
{
  if (front == NULL && rear == NULL)
    {
      printf ("No elements in the linked list\n");
      return;
    }
  Node *ptr = front;
  Node *preptr = front;
  while (ptr->next != front)
    {
      preptr = ptr;
      ptr = ptr->next;
    }
  preptr->next = front;
  preptr = rear;
  printf ("Element deleted is %d", ptr->data);
  free (ptr);
  printf ("\n");

}


void
display ()
{
  Node *ptr;
  if (front == NULL && rear == NULL)
    {
      printf ("No elements in the list to display\n");
      return;
    }
  ptr = front;
  while (ptr->next != front)
    {
      printf ("%d ", ptr->data);
      ptr = ptr->next;
    }
  printf ("%d", ptr->data);
  printf ("\n");
}


int
main ()
{
  int choice;
  while (1)
    {
      printf ("Enter the choice\n");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  insert ();
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
