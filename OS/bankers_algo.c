#include<stdio.h>
int
main ()
{
  int max[100][100], avail[100], need[100][100], f[100], alloc[100][100],
    ans[100], count = 0, n, m, i, j, k, flag = 0;
  printf ("Enter the number of processes\n");
  scanf ("%d", &n);
  printf ("Enter the number of resources\n");
  scanf ("%d", &m);
  printf ("Enter the maximum resources\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf ("%d", &max[i][j]);
  printf ("Enter the allocated resources\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      {
	scanf ("%d", &alloc[i][j]);
	need[i][j] = max[i][j] - alloc[i][j];
	f[i] = 0;
      }
      printf ("Enter the available resources\n");
    for (j = 0; j < m; j++)
	scanf ("%d", &avail[j]);
  for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
	{
	  if (f[i] == 0)
	    {
	      flag = 0;
	      for (j = 0; j < m; j++)
		{
		  if (need[i][j] > avail[j])
		    {
		      flag = 1;
		      break;
		    }
		}
	      if (flag == 0)
		{
		  ans[count++] = i;
		  for (int j = 0; j < m; j++)
		    avail[j] += alloc[i][j];
		  f[i] = 1;
		}
	    }
	}
    }
if(count!=n)printf("The sequence is unsafe\n");
else{
  printf ("Following is a safe sequence\n");
  for (int i = 0; i < n; i++)
    printf (" P%d ", ans[i]);
  }
  printf("\n");
}
