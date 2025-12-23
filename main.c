int check_input(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        while(str[i] == ' ')
            i++;
        if(str[i] == '-' || str[i] == '+')
            i++;
        if(!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}
#include<stdio.h>
int main(int argc, char **argv)
{
    int i = 0;
  while(i < argc)
  {
    if(check_input(argv[i]) == 0)
        printf("Error !\n");
    i++;
  }
    return (0);
}