#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    //     || (argv[1] = "") 
    
    bool valid = true;
    // initialize for digit detector
    
    if (argv[1] == NULL)
    {
        printf("%s key", argv[0]);
        return 1;
        //take care of empty key
    }
    
    for (int h = 0; h < strlen(argv[1]); h++)
    {
        if (isdigit(argv[1][h]) == 0)
        {
            valid = false;
            //detect non digits
        }
    }
    
    
    if ((argc != 2) || (valid == false))
    {
        printf("%s key", argv[0]);
        return 1;
        //take care of non digits and too many keys
    }
    

    else
    
    {
    
    
    string p = get_string("plaintext: ");
    int key = atoi(argv[1]);
    int l = strlen(p);
    //convert key, string length
    
    printf("ciphertext: ");
    //print cipher text ahead
    
    for (int i = 0; i < l; i++)
    {
        if (isalpha(p[i]) == 0)
        {
            printf("%c", p[i]);
        }
        //print punctuation and spaces
        else if (isupper(p[i]) != 0)
        //upper
        {
            int alph = p[i] - 64;
            if (key < (91 - p[i]))
            {
                p[i] = p[i] + key;
                printf("%c", p[i]);
                //print cipher for small keys
            }
            else
            {
                alph = (key + alph)%26;
                p[i] = 64 + alph;
                printf("%c", p[i]);
                //print cipher for large keys
            }

        }
        else if (islower(p[i]) != 0)
        //lower
        {
            int alph = p[i] - 96;
            if (key < (123 - p[i]))
            {
                p[i] = p[i] + key;
                printf("%c", p[i]);
                //small keys
            }
            else
            {
                alph = (key + alph)%26;
                p[i] = 96 + alph;
                printf("%c", p[i]);
                // large keys
            }
        }

    }
    printf("\n");
    //new line
    }
}