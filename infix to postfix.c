

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int stack[100];
int top = -1;
void
push (char ch)
{
  if (top == -1)
    {
      top = 0;
      stack[top] = ch;
      return;
    }
  else
    {
      top = top + 1;
      stack[top] = ch;
    }
}

char
pop ()
{
  char ch;
  if (top == -1)
    {
      printf ("Stack underflow\n");
      exit (0);
    }
  else
    {
      ch = stack[top];
      top--;
      return ch;
    }
}

int
checkPrecedence (char ele)
{
  if (ele == '*' || ele == '/' || ele == '/')
    {
      return 1;
    }
  else if (ele == '+' || ele == '-')
    {
      return 0;
    }
  else
    {
      return -1;
    }
}

int
main ()
{
  char a[100];
  int i;
  printf ("Enter the infix expression\n");
  scanf ("%s", a);
  strcat (a, ")");
  printf ("The postfix expression is\n");
  while (a[i] != "/0")
    {
      if (isalnum (a[i]))
	{
	  printf ("%c", a[i]);
	}
      else if (a[i] == "(")
	{
	  push (a[i]);
	}
      else if (a[i] == ")")
	{
	  while (a[i] != "(" && top != -1)
	    {
	      printf ("%c", pop ());
	    }
	}
      else
	{
	  if (checkPrecedence (a[i]) > checkPrecedence (stack[top]))
	    {
	      push (a[i]);
	    }
	  else
	    {
	      while (top != 0)
		{
		  printf ("%c", pop ());

		}
	      push (a[i]);
	    }
	}
      i++;
    }
}
