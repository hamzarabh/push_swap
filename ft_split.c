#include <stdio.h>
#include <stdlib.h>
int count_word(char *str)
{
    int i;
    int count_word;
    count_word = 0;
    i = 0;
    while(str[i])
    {
        if( i == 0 && str[i] != ' ')
            count_word++;
        if((str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0'))
            count_word++;
        i++;
    }
    return (count_word);
}
char *ft_strdup(char *start, char *end)
{
    char *res;
    size_t len;
    size_t i;
    i = 0;
    len = end - start ;
    res = malloc(len + 1);
    if(!res)
        return(NULL);
    while(start != end)
    {
        res[i] = *start;
        start++;
        i++;
    }
    res[i] = '\0';
    return (res);
}

char *ft_hard_split(char **str,size_t len)
{
    size_t i;
    char **parts;
    char *start;
    start = NULL;
    parts = malloc(len + 1);
    if (!parts)
        return (NULL);
    i = 0;
    while((*str)[i])
    {
        if(str[i] != ' ' && (i == 0 || str[i-1] == ' ') && str[i] != '\0')
            start = str + i;
        i++;
    }
}
char **ft_split(char *str)
{
    int i;
    char *start
    i = 0;

    
}

int main()
{
    char *str;
    str ="hello world";
    printf("%s\n",ft_strdup(str,str+6));
    return (0);
}
