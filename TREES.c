#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *root = NULL;

void
inorder (Node * root)
{
  if (root == NULL)
    {
      return;
    }
  inorder (root->left);
  printf ("%d ", root->data);
  inorder (root->right);
}


void
preorder (Node * root)
{
  if (root == NULL)
    {
      return;
    }
  printf ("%d ", root->data);
  preorder (root->left);
  preorder (root->right);
}


void
postorder (Node * root)
{
  if (root == NULL)
    {
      return;
    }
  postorder (root->right);
  postorder (root->left);
  printf ("%d ", root->data);
}

Node *
insert (Node * root, int ele)
{
  if (root == NULL)
    {
      Node *ptr = (Node *) malloc (sizeof (Node));
      ptr->data = ele;
      ptr->left = NULL;
      ptr->right = NULL;
      return ptr;

    }
  if (ele < root->data)
    {
      root->left = insert (root->left, ele);
    }
  else if (ele > root->data)
    {
      root->right = insert (root->right, ele);
    }
  return root;
}

int
main ()
{
  Node *root = NULL;
  char A[10];
  while (1)
    {

      printf ("Do you want to insert an element\n");
      scanf ("%s", A);
      if (A[0] == 'y')
	{
	  int ele;
	  printf ("Enter the element to be inserted\n");
	  scanf ("%d", &ele);
	  root = insert (root, ele);
	}
      else if (A[0] == 'n')
	{
	  printf ("The inorder traversal is ");
	  inorder (root);
	  printf ("\n");
	  printf ("The preorder traversal is ");
	  preorder (root);
	  printf ("\n");
	  printf ("The postorder traversal is");
	  postorder (root);
	  break;
	}

    }
}

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *
insert (Node * root, int ele)
{
  if (root == NULL)
    {
      root = (Node *) malloc (sizeof (Node));
      root->data = ele;
      root->left = NULL;
      root->right = NULL;
      return root;
    }
  if (ele < root->data)
    {
      root->left = insert (root->left, ele);

    }
  else
    {
      root->right = insert (root->right, ele);

    }
  return root;
}

void
path (Node * root, int a[], int c)
{
  if (root == NULL)
    {
      return;
    }
  a[c] = root->data;
  c++;

  if (root->left == NULL && root->right == NULL)
    {
      for (int i = 0; i < c; i++)
	{
	  printf ("%d ", a[i]);

	}
      printf ("\n");
    }
  else
    {
      path (root->left, a, c);
      path (root->right, a, c);
    }

}

void
display (Node * root)
{
  if (root == NULL)
    {
      return;
    }
  display (root->left);
  printf ("%d ", root->data);
  display (root->right);
  return;
}

int
main ()
{
  Node *root = NULL;
  char A[10];
  int ele;
  int a[5];
  while (1)
    {
      printf ("Enter the element to insert\n");
      scanf ("%d", &ele);
      root = insert (root, ele);
      printf ("Do you want to insert the element\n");
      scanf ("%s", A);
      if (A[0] == 'n' || A[0] == 'N')
	{
	  printf ("The elements in the tree are\n");
	  display (root);
	  printf ("\n");
	  printf ("The path from root to leaf is \n");
	  path (root, a, 0);

	}
    }
}

