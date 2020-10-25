/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        
 *Course:     cis3020 Intro to CIS Fall 1999         
 *Assignment: hw3, perfect.c
 *Description:returns all perfect numbers between 1 & 9999
 *            
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int factorsum (int checknum);                                                           
int main(void)

{
   int checknum;
    
   printf("\n");
   printf("HERE ARE THE PERFECT NUMBERS BETWEEN 1 & 9999\n");

   for (checknum = 2; checknum <= 9999; checknum++)
     {
         if (factorsum(checknum) == checknum)
	   printf("\n%d", checknum);
          
     }
        
    return 0;
}

/*----------------------------------------------------------*/
/*----------------------FUNCTIONS---------------------------*/
/*----------------------------------------------------------*/

/*factorsum function*/

int factorsum(int pchecknum)
  {
    int sum, divisor;  /*variable declaration*/

    sum = 0;
    divisor = 1;
    
    while (divisor < pchecknum) 
      {
	if ((pchecknum % divisor) == 0) {
        sum += divisor;
        }  

    divisor++; 
 
      }
    
    return (sum);

  }
        
              
           
	   
       
  
            
  



