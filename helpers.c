// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //X = Numerator; Y = Denominator
    int Y = (fraction[2] - 48); //they are in ascii value and we want them in "normal" value
    int X = (fraction [0] - 48);
    if ((Y > 0 && ((Y % 2) == 0)) && Y <= 8)
    {
        if (Y == 2) //that mean is a fourth of and of an eith there for we multiply for 4
        {
            X = X * 4;
            return X;
        }
        else if (Y == 4)
        {
            X = X * 2;
            return X;
        }
        return X;
    }
    else
    {
        return 1;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int n;
    switch (note[0]) //switch the values acording for the distance from a note A
    {
        case 'A':
            n = 0;
            break;
        case 'B':
            n = 2;
            break;
        case 'C':
            n = -9;
            break;
        case 'D':
            n = -7;
            break;
        case 'E':
            n = -5;
            break;
        case 'F':
            n = -4;
            break;
        case 'G':
            n = -2;
            break;
    }
    //now we change for the octave
    if (strlen(note) == 2) //In case it doesn't have a # or a b
    {
        if ((note[1] - 48) <= 4) //aka is below A4 and for how much
        {
            n = n + (12 * ((note[1] - 52)));
        }
        else if ((note[1] - 48) > 4) //aka is above A4 and for how much
        {
            n = n + (12 * (note[1] - 52));
        }
        else
        {
            n = 0;
        }
    }
    else if (strlen(note) == 3) //it has a # or a b
    {
        if ((note[2] - 48) < 4) //aka is below A4 and for how much
        {
            n = n + (12 * ((note[2] - 52)));
        }
        else if ((note[2] - 48) > 4) //aka is above A4 and for how much
        {
            n = n + (12 * (note[2] - 52));
        }
    }
    //now we add or substract if is a # or a b
    if (strlen(note) == 3)
    {
        if (note[1] == 35) // the ascii value of #
        {
            n = (n + 1);
        }
        else if (note[1] == 98) //ascii value of b
        {
            n = (n - 1);
        }
    }
    return round(pow(2, n / 12.0) * 440);
}

// Determines whether a string represents a rest
bool is_rest(string s) //see if the input is a rest or something else
{
    if (strlen(s) == 0) //intencionally blank aka rest
    {
        return true;
    }
    else //something else is either a typo or a note
    {
        return false;
    }
}