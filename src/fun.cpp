#include <fun.h>
#include <math.h>
#include <ctype.h>

unsigned int faStr1(const char *str)
{
    int index = 0;
    int count = 0;
    bool inWord = false;
    bool isNumber = false;

    while(str[index] != '\0')
    {
        if (str[index] != ' ' && !inWord)
        {
            inWord = true;

            if (isdigit(str[index]))
            {
                isNumber = true;
            }
        }
        else if ((str[index] != ' ') && inWord && isdigit(str[index]))
        {
            isNumber = true;
        }
        else if(str[index] == ' ')
        {
            if(!isNumber && inWord)
            {
                count++;
            }

            inWord = false;
            isNumber = false;
        }

        index++;
    }

    return count;
}
unsigned int faStr2(const char *str)
{
    int index = 0;
    int count = 0;
    bool inWord = false;
    isUpperSymbol = false;
    isLowerSymbol = true;

    while(str[index] != '\0')
    {
        if((str[index] != ' ') && !inWord)
        {
            inWord = true;

            if(('A' <= str[index]) && (str[index] <= 'Z'))
            {
                isUpperSymbol = true;
            }
        }
        else if((str[index] != ' ') && inWord && (('a' > str[index]) || (str[index] > 'z')))
        {
            isLowerSymbol = false;
        }
        else if(str[index] == ' ')
        {
            if(inWord && isUpperSymbol && isLowerSymbol)
            {
                count++;
            }

            inWord = false;
            isUpperSymbol = false;
            isLowerSymbol = true;
        }

        index++;
    }

    return count;
}
unsigned int faStr3(const char *str)
{
    int index = 0;
    int count = 0;
    int countSymbolsWords = 0;
    bool inWord = false;

    while(str[index] != '\0')
    {
        if ((str[index] != ' ') && !inWord)
        {
            inWord = true;
            countSymbolsWords++;
            count++;
        }
        else if ((str[index] != ' ') && inWord)
        {
            countSymbolsWords++;
        }
        else if ((str[index] == ' ') && inWord)
        {
            inWord = false;
        }

        index++;
    }

    return round(countSymbolsWords/count);
}