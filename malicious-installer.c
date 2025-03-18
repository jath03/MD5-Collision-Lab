#include <stdio.h>

static char URL[200] = "";


int main()
{
  int i;
  for (i=0; i<200; i++){
    printf("%x", URL[i]);
  }
  printf("\n");
}
