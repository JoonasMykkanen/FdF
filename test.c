
#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa_hex(unsigned long long num)
{
	int		i;
	int		temp;
	char	*str;
	char	buf[17];

	i = 0;
	if (num == 0)
		return (0);
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			buf[i++] = (char)temp + 48;
		else
			buf[i++] = (char)temp + 87;
		num = num / 16;
	}
	temp = -1;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	while (--i >= 0)
		str[++temp] = buf[i];
	str[temp + 1] = '\0';
	return (str);
}

int convert_rgb(int r, int g, int b)
{
	int	hex;

	hex = (r<<16) | (g<<8) | b;
	printf("%d\n", hex);
	
    return (hex);
}

int	main(void)
{
	
	int x = convert_rgb(255, 255, 255);

	return (0);
}