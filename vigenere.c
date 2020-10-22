#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
//I have to check that there is an argv[1] before I try to use it...
    if (argv[1] == NULL)
    {
        printf("Please introduce ONE key word\n");
        return 1;
    }
    if (argc != 2) //in case the user puts more than one key
    {
        printf("Please introduce ONE key word\n");
        return 1;
    }

    for (int check = 0; check < strlen(argv[1]); check++) //make sure it IS an alpha
    {
        if (!isalpha(argv[1][check]))
        {
            printf("Please introduce only an alphabetic key\n");
            return 1;
        }
    }

    string plaintext = get_string("Plaintext: "); //get user input
    string key = argv[1];
    int vector = 0;
    int place = 0;
    int letra = 0;
    int ciphertext;

    //for each character of the string if its alphabetical preserve case, shift caracter by key
    printf("ciphertext: ");
    while (vector != strlen(plaintext))
    {
        if (isalpha(plaintext[vector])) //aka is a letter
        {
            if (isupper(plaintext[vector]))
            {
                if (isupper(key[letra]))//Check if the key is upper or not is crucial also
                {
                    ciphertext = ((plaintext[vector] + key[letra] - 130) % 26 + 65);
                    printf("%c", ciphertext);
                    vector++;
                    place++;
                    letra = (place % strlen(key)); //make sure place != strlen(key)
                    // The keys place shouldn't move unless there is a letter
                }
                else
                {
                    ciphertext = ((plaintext[vector] + key[letra] - 162) % 26 + 65);
                    printf("%c", ciphertext);
                    vector++;
                    place++;
                    letra = (place % strlen(key));
                }
            }
            else
            {
                //cypher the letter
                if (isupper(key[letra]))
                {
                    ciphertext = ((plaintext[vector] + key[letra] - 162) % 26 + 97);
                    printf("%c", ciphertext);
                    vector++;
                    place++;
                    letra = (place % strlen(key));
                }
                else
                {
                    ciphertext = ((plaintext[vector] + key[letra] - 194) % 26 + 97);
                    printf("%c", ciphertext);
                    vector++;
                    place++;
                    letra = (place % strlen(key));
                }
            }
        }
        else
        {
            printf("%c", plaintext[vector]); //keep moving the vector of the plaintext but not the keys place
            vector++;
        }
    }
    printf("\n");
    return 0;
}