/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        *****
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment: hw4, 8hangman.c
 *Description:the game hangman
 */

#include <stdio.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"

#define FNAME "wordlist.txt"
#define MAXWORDS 25

/****************FUNCTION PROTOTYPES****************************/
   int initialize (string wordarray[]);
   string randompick (string wordarray[], int size);
   char getinput (bool alpha[]);
   void makeempty (bool alpha[]);
   void include (bool alpha[], char input);
   bool memberof (bool alpha[], char input);
   void showset (bool alpha[]);
   void showmaskedword (string guessword, bool alpha[]);
   bool doesoccur (string guessword, char input);
   void showgame (string guessword, bool alpha[], int numerrors);
   bool fullyguessed (string guessword, bool alpha[]);
/***************************************************************/
int main(void) {

  /*-----------declare variables-------------------*/
            string wordarray[MAXWORDS], guessword;
            int size, numerrors, numwins, numlosses;
            char input, playagain;
            bool alpha[25], wins;
  /*-----------------------------------------------*/
       numwins = numlosses = 0;

   do {

  /*-----initialize variables-----*/
       numerrors = 0;
       input = '\0';
  /*------------------------------*/
    makeempty(alpha);
    size = initialize(wordarray);
    guessword = randompick(wordarray, size);

    showgame(guessword, alpha, numerrors);
    input = getinput(alpha);
    include(alpha, input);

/*GUESS UNTIL YOU'VE WON OR HAVE ACCUMULATED MORE THAN 8 ERRORS*/

    while ((numerrors < 8) && (!(fullyguessed(guessword, alpha)))) {
      if (doesoccur(guessword, input)) {
	showgame(guessword, alpha, numerrors);
        printf("GOOD GUESS\n\n");
        input = getinput(alpha);
                                       }
      else {
        numerrors++;
        showgame(guessword, alpha, numerrors);
        printf("Uh oh... TRY AGAIN\n\n");
        input = getinput(alpha);
           }
                                                                   }
/*IF YOU GUESSED THE WORD ADD 1 TO NUMBER OF WINS OTHERWISE ADD 1 TO NUMBER
 *OF LOSSES*/

    wins = (fullyguessed(guessword, alpha));

    if (wins) {
      printf ("\nCongradulations! You won!!!\n");
      printf ("You successfully guessed %s\n", guessword);
      numwins++;
      printf ("\nWins: %d, Losses: %d", numwins, numlosses);
              }
    else {
      printf("Looks like you've hung yourself...");
      numlosses++;
      printf ("\nWins: %d, Losses: %d\n", numwins, numlosses);
         }

/*PLAY AGAIN?*/

   printf("\nWould you like to play again? (y/n): ");
   fflush (stdin);
   playagain = getchar();

   }  while (playagain == 'y');

    printf("---------------------------------------------------\n");
    printf("|  Hangman v1.0 c.1999 OziHandicraft Productions  |\n");
    printf("---------------------------------------------------\n");

    return 0;
                      }
/*----------------------------------------------------------*/
/*----------------------FUNCTIONS---------------------------*/
/*----------------------------------------------------------*/

/*--------------------getinput------------------------------*/
char getinput (bool alpha[]) {

        char input;

  printf("Your guess? ");
  fflush (stdin);
  input = getchar();

  while(memberof(alpha, input)) {
    printf("\nYou have already guessed the letter %c", input);
    printf("\nTRY AGAIN");
    printf("\nEnter another letter: ");
    fflush (stdin);
    input = getchar();
                                }
  include (alpha, input);

  return input;
                             }
/*---------------------initialize---------------------------*/
int initialize (string wordarray[]) {

            FILE *inputfile;
            string word;
            int index, size;

  if((inputfile = fopen(FNAME, "r")) == NULL)
	printf("WORD FILE NOT FOUND %s\n", FNAME);

  index = 0;
  size = -1;

  while((word = ReadLine(inputfile)) != NULL)
   {
     wordarray[index] = word;
     index++;
     size++;
   }

   fclose(inputfile);

   return size;
                                     }
/*----------------------randompick------------------------------*/
string randompick (string wordarray[], int size) {

        string randomword;

   Randomize();
   return(randomword = wordarray[RandomInteger(0, size)]);
                                                 }
/*------------------makeempty-------------------------------*/
void makeempty (bool alpha[]) {

       int i;

 for (i=0; i<26; i++) {
   alpha[i] = FALSE;
                      }
                              }
/*--------------------memberof-------------------------------*/
bool memberof (bool alpha[], char input) {

   return alpha[input-'a'];
					 }
/*--------------------include--------------------------------*/
void include (bool alpha[], char input) {

   alpha[input-'a'] = TRUE;
					}
/*--------------------showset--------------------------------*/
void showset (bool alpha[]) {

         int i;

 printf ("{");
 for (i=0; i<26; i++) {
   if (alpha[i])
     printf ("%c", (char) (i+'a'));
                      }
   printf("}\n");
                            }
/*------------------doesOccur---------------------------------*/
bool doesoccur (string guessword, char input) {

       int i;

  for (i=0; i<(strlen(guessword)); i++) {
   if(IthChar(guessword, i) == input)
       return TRUE;
                                        }
       return FALSE;
                                              }
/*-----------------Showmaskedword-----------------------------*/
void showmaskedword (string guessword, bool alpha[]) {

                 int i;
                 char letter;

    printf("Word: ");
    for (i=0; i<(strlen(guessword)); i++) {
      letter = IthChar(guessword, i);

      if (memberof(alpha, letter))
        printf("%c", letter);
      else
         printf("-");
                                          }
                                                   }
/*---------------------showgame-------------------------------*/
void showgame (string guessword, bool alpha[], int numerrors) {

  showmaskedword(guessword, alpha);
  printf("           ");
  printf("Wrong: %d ", numerrors);
  showset(alpha);
                                                              }
/*------------------------fullyguessed------------------------*/
bool fullyguessed (string guessword, bool alpha[]) {

            int i;
            char letter;

 for (i=0; i<(strlen(guessword)); i++) {

    letter = IthChar (guessword, i);
    if (!(memberof(alpha, letter)))
        return FALSE;
                                       }
    return TRUE;
                                                   }
























