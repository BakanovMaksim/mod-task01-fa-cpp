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

            if((str[index] >= 48) && (str[index] <= 57))
            {
                isNumber = true;
            }
        }
        else if ((str[index] != ' ') && inWord && (str[index] >= 48 && str[index] <= 57))
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
    bool isUpperSymbol = false;
    bool isLowerSymbol = true;

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

    double result = countSymbolsWords/count;

    return (result > 0.0) ? (result + 0.5) : (result - 0.5);
}