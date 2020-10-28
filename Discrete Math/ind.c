/*AUTHOR: Aaron Remski
 *COURSE: COT3100
 *PROGRAM: inductive proof
 */

#include <stdio.h>
#include <stdlib.h>

#define FNAME "evenproof.txt"    /*output filename*/

/*----------------FUNCTION PROTOTYPES------------------*/

void basecase (int j, FILE *outputfile);  
void induction (int j, FILE *outputfile); 

/*-----------------------------------------------------*/

int main (void) {
	
           FILE *outputfile;  /*pointer to FILE*/
           int n;

/*-------------------INITIALIZE FILE-------------------*/
    
     outputfile = fopen(FNAME, "w");
 
/*-----------------------------------------------------*/

   printf("-----------------------------------------------\n");  
   printf("| INDUCTIVE PROOF FOR 0+2+4+...+2N = (N)(N+1) |\n");
   printf("-----------------------------------------------\n\n");
   
   printf("Enter N to find poof for that number: ");
   scanf("%d", &n);

   basecase(0, outputfile);

   induction(n, outputfile);

   printf("FILE DONE\n");
   printf("Please refer to evenproof.txt for answer\n\n");
   printf("------------------------------------\n");
   printf("| THANK YOU FOR YOUR PARTICIPATION |\n");
   printf("------------------------------------\n");

	fclose(outputfile);

	return 0;

	}

/*-----------------Function definitions------------------------*/
void basecase (int j, FILE *outputfile) {

    int right, left;

    printf ("."); /*let user know program is thinking*/

    fprintf(outputfile, "---BASE CASE---\n\n");
    fprintf(outputfile, "Sum with j from %d to %d of 2j\n", j, j);
  left = 2 * j;
    fprintf(outputfile, "2(%d) = %d(%d + 1)\n", j, j, j);
  right = j * (j + 1);  
    fprintf(outputfile, "  %d  =  %d CHECK\n", left, right);
                                        }
/*-------------------------------------------------------------*/
void induction (int j, FILE *outputfile) {

     int i;

     fprintf(outputfile, "---INDUCTIVE PROOF---\n\n");

  for (i = 0; i <= j; i++) {

     printf (".");
     fprintf(outputfile, "Case j + 1 = %d\n", (i + 1));
     fprintf(outputfile, "Just by what the word sum means,\n");
     fprintf(outputfile, "we know that: \n\n");

     fprintf(outputfile, "the sum of the first %d + 1 even postive\n", i);
     fprintf(outputfile, "integers is the sum of the first %d even\n", i);
     fprintf(outputfile, "postive integers + 2(%d + 1)\n\n", i);     

     fprintf(outputfile, "By case %d,\n", i);
     fprintf(outputfile, "the sum of the first %d even positive\n", i);
     fprintf(outputfile, "integers is %d(%d + 1).\n\n", i, i);
     fprintf(outputfile, "So we can substitute in to get\n");

     fprintf(outputfile, "the sum of the first %d + 1 even positive\n", i);
     fprintf(outputfile, "integers is %d(%d + 1) + 2(%d + 1).\n\n", i,i,i);

     fprintf(outputfile, "Now just factor out (%d + 1) in back to get\n", i);
     fprintf(outputfile, "%d(%d + 1) + 2(%d + 1) = (%d + 1)(%d + 2)\n", i,i,i,i,i);
     fprintf(outputfile, "= (%d + 1)((%d + 1) + 1).\n\n", i, i);
   
     fprintf(outputfile, "Putting both together gives the sum of the first\n");
     fprintf(outputfile, "%d = %d + 1 even positive integers is\n", (i+1),i);
     fprintf(outputfile, "(%d + 1)((%d + 1) + 1).\n\n", i, i);

     fprintf(outputfile, "CHECK COMPLETE for %d\n\n\n", (i + 1)); 

                          }
     printf(".\n");
}
    

