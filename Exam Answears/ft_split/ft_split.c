#include <stdlib.h>

int is_delimiter(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (is_delimiter(*str))
            in_word = 0;
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
        str++;
    }
    return count;
}

char *extract_word(char *str)
{
    int len = 0;
    char *word;

    while (str[len] && !is_delimiter(str[len]))
        len++;
    
    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return NULL;
    
    for (int i = 0; i < len; i++)
        word[i] = str[i];
    word[len] = '\0';
    
    return word;
}

char **ft_split(char *str)
{
    int word_count = count_words(str);
    char **result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return NULL;

    int i = 0;
    while (*str)
    {
        while (*str && is_delimiter(*str))
            str++;
        if (*str)
        {
            result[i] = extract_word(str);
            if (!result[i])
            {
                // Free previously allocated memory if extraction fails
                while (i > 0)
                    free(result[--i]);
                free(result);
                return NULL;
            }
            i++;
            while (*str && !is_delimiter(*str))
                str++;
        }
    }
    result[i] = NULL;
    return result;
}

