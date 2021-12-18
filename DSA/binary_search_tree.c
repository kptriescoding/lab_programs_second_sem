#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int ele;
  struct node *left, *right;
} Node;
Node *insertbt (Node * root, int ele);
Node *maxlefttree (Node * root);
Node *deletebt (Node * root, int ele);
void preorder (Node * root);
void inorder (Node * root);
void postorder (Node * root);
int
main ()
{
  Node *root = NULL;
  int ch, n, ele;
  while (ch != 6)
    {
      printf
	("What would you like to do \n1.Insertion \n2.Deletion \n3.Preorder Traversal\n4.Inorder Traversal\n5.Postorder Traversal\n6.Quit\n");
      scanf ("%d", &ch);
      switch (ch)
	{
	case 1:
	  printf ("How many elements do you want to insert\n");
	  scanf ("%d", &n);
	  printf ("Enter the elements to be inserted\n");
	  for (int i = 0; i < n; i++)
	    {
	      scanf ("%d", &ele);
	      root = insertbt (root, ele);
	    }
	    printf("Insertion Succesfull\n");
	  break;
	case 2:
	  printf ("How many elements do you want to delete\n");
	  scanf ("%d", &n);
	  printf ("Enter the elements to be deleted\n");
	  for (int i = 0; i < n; i++)
	    {
	      scanf ("%d", &ele);
	      root = deletebt (root, ele);
	      if (root == NULL)
	    printf ("Tree is empty\n");
	    }
	  break;
	case 3:
	  if (root == NULL)
	    printf ("Tree is empty\n");
	  else
	    {
	      printf ("The preorder transversal is\n");
	      preorder (root);
	      printf("\n");
	    }
	  break;
	case 4:
	  if (root == NULL)
	    printf ("Tree is empty\n");
	  else
	    {
	      printf ("The inorder transversal is\n");
	      inorder (root);
	      printf("\n");
	    }
	  break;
	case 5:
	  if (root == NULL)
	    printf ("Tree is empty\n");
	  else
	    {
	      printf ("The postorder transversal is\n");
	      postorder (root);
	      printf("\n");
	    }
	  break;
	case 6:
	  break;
	default:
	  printf ("Invalid input please TRY Again!!!\n");
	}
    }
  printf ("Exited Succesfully\n");
}

Node *
insertbt (Node * root, int ele)
{
  Node *newnode = (Node *) malloc (sizeof (Node));
  if (root == NULL)
    {
      newnode->ele = ele;
      newnode->left = NULL;
      newnode->right = NULL;
      root = newnode;
      return newnode;
    }
  else
    {
      if (root->ele > ele)
	root->left = insertbt (root->left, ele);
      else
	root->right = insertbt (root->right, ele);
    }
  return root;
}

Node *
maxleftsubtree (Node * root)
{
  if (root != NULL)
  while (root->right)
  root=root->right;
  return root;
}

Node *
deletebt (Node * root, int ele)
{
  if (root == NULL)
    {
      printf ("Element Not found\n");
      return root;
    }
  else
    {
      if (root->ele > ele)
	root->left = deletebt (root->left, ele);
      else if (root->ele < ele)
	root->right = deletebt (root->right, ele);
      else
	{ 
	Node*temp;
	  if (root->left == NULL)
	    {
	      temp=root;
	      root = root->right;
	      free(temp);
	      printf("Deletion Successfull\n");
	    }
	  else if (root->right == NULL)
	    {
	      temp=root;
	      root = root->left;
	      free(temp);
	      printf("Deletion Successfull\n");
	    }
	  else
	    {
	      Node *largest = maxleftsubtree (root->left);
	      Node *deletenode = root;
	      deletenode->ele = largest->ele;
	      deletenode->left = deletebt (deletenode->left, largest->ele);
	    }
	}
    }
    return root;
}

void
preorder (Node * root)
{
  if (root != NULL)
    {
      printf (" %d ", root->ele);
      preorder (root->left);
      preorder (root->right);
    }
}

void
inorder (Node * root)
{
  if (root != NULL)
    {
      inorder (root->left);
      printf (" %d ", root->ele);
      inorder (root->right);
    }
}

void
postorder (Node * root)
{
  if (root != NULL)
    {
      postorder (root->left);
      postorder (root->right);
      printf (" %d ", root->ele);
    }
}

