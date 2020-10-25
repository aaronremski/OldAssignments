#include <stdio.h>
#include <stdlib.h>

// *************************
// Some type definitions
// *************************

typedef
struct node {
  int coef;
  int exp;
  struct node * next;
} 
nodeStruct;

typedef nodeStruct* nodePtr;
typedef nodePtr polynomial;

// *************************
// Prototypes
// *************************

nodePtr makeNode      (int c, int e, nodePtr p);
polynomial readPoly   (int);
void writePoly        (polynomial);
void writeNode        (nodePtr p);

// *************************
// main
// *************************

int main (void) 
{

  polynomial p1;
  int d;

  while (1) {
    printf ("Enter a degree (enter 0 to stop): ");
    fflush(stdin);
    scanf ("%d", &d);
    if (d==0) break;
    printf ("Enter %d coefs: ", d+1);
    p1 = readPoly(d);
    writePoly(p1);
    printf ("\n");
  }
  return 0;
}

// write your definitions for
//
//     makeNode
//     readPoly
//     writePoly
//     writeNode

