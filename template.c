/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        *************
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment:
 *Description:
 *
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "random.h"

int main(void)

{
    int randomnum;  /*variable declaration*/

    randomnum = random(0, 10);

    printf("\nRANDOM NUMBER GENERATED: %s", randomnum);


    return 0;
}


/*----------------------------------------------------------*/
/*----------------------FUNCTIONS---------------------------*/
/*----------------------------------------------------------*/

