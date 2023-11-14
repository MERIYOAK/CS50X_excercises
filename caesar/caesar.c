#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])/*first enter an int key*/
{
     /*checks wether it has 2 rounds and a digit*/
     if(argc == 2 && isdigit(*argv[1]))
     {
         int key = atoi(argv[1]);  /*so here the key enters and converted to int*/
         string plaintext = get_string("plaintext:  ");/*get text*/
         printf("ciphertext: ");/*print out the cipher*/

         for (int i = 0; i < strlen(plaintext); i++)
             {
                if(plaintext[i] >= 'a' && plaintext[i] <= 'z')/*checks if it is a lowercase*/
                {
                    printf("%c", (((plaintext[i] - 'a') + key) % 26) + 'a');/*print out the lowercase with key*/
                }
                else if(plaintext[i] >= 'A' && plaintext[i] <= 'Z')/*checks if it is an uppercase*/
                {
                    printf("%c", (((plaintext[i] - 'A') + key) % 26) + 'A');/*print out the uppercase with key*/
                }
                else
                {
                    printf("%c", plaintext[i]);
                }
             }
             printf("\n");
             return 0;
     }
     else/* gives instruction*/
     {
        printf("usage: ./caesar key\n");
        return 1;
     }
}