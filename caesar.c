#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
  string Plaintext;
   if(argv[1] == NULL) //I have to check that there is an argv[1] before I try to use it...
    {
        printf("Please introduce a number\n");
        return 1;
    }
  int key = atoi(argv[1]);
  int vector = 0;
  int Cyphertext;



    if(key < 0)//argc is the one counting how many strings were introduced
    {
        printf("Error, please introduce only one line of command argument\n");
        return 1;
    }
    if (argc != 2) // This is adding to the first if, in case is more than 2 inputs
    {
        printf("Error, please introduce only one line of command argument\n");
        return 1;
    }

    else //Get users input
    {
        printf("Message:");
        Plaintext = get_string();
    }
    //for each character of the string if its alphabetical preserve case, shift caracter by key
    printf("ciphertext: ");
    while (vector != strlen(Plaintext))
    {
        if (isalpha(Plaintext[vector])) //aka is a letter
        {
         if (isupper(Plaintext[vector]))
            {
            Cyphertext = ((Plaintext[vector] + key - 65) % 26 + 65);
            printf("%c", Cyphertext);
            vector++;
            }
          else
           {//cypher the letter
            Cyphertext = ((Plaintext[vector] + key - 97) % 26 + 97);
            printf("%c", Cyphertext);
            vector++;
            }
        }
        else
        {
        printf("%c", Plaintext[vector]);
        vector++;
        }
    }
    printf("\n");
    return 0;
}