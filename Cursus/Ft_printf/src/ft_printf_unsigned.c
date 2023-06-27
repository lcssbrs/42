#include "../ft_printf.h"

char	*ft_unsigneditoa(unsigned int n)
{
	char	*num;
	int		len;

	len = 1;
	unsigned int temp = n; 
	while(temp >= 10)
	{
		temp = temp / 10;
		len ++;
	}
	num = (char *)(malloc(sizeof(char) *(len + 1)));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len --;
	}
	return (num);
}

int	ft_printunsigned(int n)
{
	char	*num;
	int		len;

	num = ft_unsigneditoa((unsigned int)n);
	len = ft_printstr(num);
	free (num);
	return (len);
}
