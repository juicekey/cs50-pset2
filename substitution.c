#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//int cipher(string key, string message);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("One argument");
        return 1;
    }
    //handle wrong number args
    
    else if (strlen(argv[1]) != 26)
    {
        printf("26 letters");
        return 1;
    }
    //handle wrong num characters
    
    else
    {
        string key = argv[1];
        
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            for (int j = 0; j < strlen(argv[1]); j++)
            {
                if ( (j != i) && ((argv[1][j] == argv[1][i]) || (argv[1][j] == (argv[1][i] + 32))))
                {
                    printf("Duplicate");
                    return 1;
                }
                //handle duplicates
            }
            if (isalpha(argv[1][i]) == 0)
            {
                printf("Letters only");
                return 1;
            }
            //handle non letters
            
            if (islower(key[i]) != 0)
            {
                key[i] = key[i] - 32;
            }
            

        }

            string message = get_string("plaintext: ");
            //printf("%lu", strlen(message));

            //cipher(key, message);
            
            ////////////////
            printf("ciphertext: ");
            int ciphertext[strlen(message)];
    
    for (int i = 0; i < strlen(message); i++)
    {
        if ( (message[i] > 64) && (message[i] < 91) )
        //upper
        {
            int index = (message[i] - 65);

            ciphertext[i] = (key[index]);
            //printf("%c", key[index]);

        }
        else if ( (message[i] > 96) && (message[i] < 123) )
        //lower
        {
            int index = (message[i] - 97);
            //printf("yah");
            ciphertext[i] = (key[index] + 32);

        }
        else
        {
            ciphertext[i] = message[i];
        }
        printf("%c", ciphertext[i]);

    }
    printf("\n");
    /////////////////
            
            
            
    }
    
}
/*
int cipher(string key, string message)
{
    int ciphertext[strlen(message)];
    
    for (int i = 0; i < strlen(message); i++)
    {
        if (isupper(message[i]) == true)
        {
            int index = (message[i] - 65);
            printf("yeet");
            ciphertext[i] = (key[index]);
            printf("%c", key[index]);

        }
        else if islower(message[i] == true)
        {
            int index = (message[i] - 97);
            printf("yah");
            ciphertext[i] = (key[index]);

        }
        printf("%c", ciphertext[i]);
    }
    //printf("ciphertext: %s\n", ciphertext);

    
}
*/