long ft_atol(char *a_num)
{
	int i;
	long res;
	int sign;
	sign = 1;
	i = 0;
	res = 0;
	if(a_num[i] == '-')
	{
		sign = -1;
		i++;
	}
	while(a_num[i])
	{
		res = (res * 10) + (a_num[i] - '0');
		i++;
	}
	return (res * sign);
}
int count_digit(char *str)
{
	int i;
	int count;
	count = 0;
	i = 0;
	if(str[i] == '-' || str[i] =='+')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	while(str[i])
	{
		i++ ;
		const++ ;
	}
	return (count);
}

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

	if(count_digit(str) > 10)
		return (0);
	if(ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (0);
    return (1);
}
#include<stdio.h>
int main(int argc, char **argv)
{
	int i ;
	i= 1;
  while(i < argc)
  {
    if(check_input(argv[i]) == 0)
        printf("Error\n");
    i++;
  }
//printf("%ld",ft_atol("0"));
    return (0);
}
