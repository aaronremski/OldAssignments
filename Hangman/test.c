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

void makeempty (bool alpha[]);
void include (bool alpha[], char input);
bool memberof (bool alpha[], char input);
void showset (bool alpha[]);


int main(void) {

  char input;
  bool alpha[25];

   input = 'z';

   makeempty(alpha);
   include(alpha, input);
 //  memberof(alpha, input);
   showset(alpha);

   return 0;
               }
/*------------------makeempty-------------------------------*/
void makeempty (bool alpha[]) {

 int i;

 for (i=0; i<26; i++) {
   alpha[i] = FALSE;
                      }
                              }
/*-------------------memberof-------------------------------*/
bool memberof (bool alpha[], char input) {

   return alpha[input-'a'];
					 }
/*-------------------include--------------------------------*/
void include (bool alpha[], char input) {

      alpha[input-'a'] = TRUE;
					}
/*-------------------showset--------------------------------*/
void showset (bool alpha[]) {

 int i;

 printf ("{");
 for (i=0; i<26; i++) {
   if (alpha[i]) printf ("%c", (char) (i+'a'));
                      }
   printf("}");
                            }
/*---------------------------------------------------------*/





