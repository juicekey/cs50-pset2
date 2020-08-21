#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int main(void)
{
    float nw, nl, ns;
    nw = nl = ns = 0;
    //initialize counters
    
    string s = get_string("Gimme some text: ");
    float length = strlen(s);
    //get length of input
    
    for (int i = 0; i < length; i++)
        //iterate input until input length
    {
        if ((s[i] >= 97 && s[i] < 123) || (s[i] >= 65 && s[i] < 91))
        {
            nl++;
            //count letter
        }
        else if ((s[i] == 33) || (s[i] == 46) || (s[i] == 63))
        {
            nw++;
            ns++;
            //add words and sentences for end of sentence punctuation
        }
        else if (s[i] == 32)
        {
            nw++;
            //count new words from spaces
        }
        
    }
    nw = nw - ns + 1;
    //remove counts for spaces at end of sentence
    
    float L = (100 * nl) / nw;
    float S = (100 * ns) / nw;
    //letters and senteces per word
    
    int index = round((.0588 * L) - (.296 * S) - 15.8);
    // get coleman liau index
    
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    //print grade level

}