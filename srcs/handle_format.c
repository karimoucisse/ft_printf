#include "../includes/libft.h"
int	ft_handle_format(char *str, char *flags, char specifier, int min_len)
{
	// printf("str = %s, spec = %c, flags= %s, len = %d\n", str, specifier, flags, min_len);
	if(specifier == 'c')
		ft_putchar_fd(str[0], 1);
	if(specifier == 's')
		write(1, str, min_len);
	// 	// %s Prints a string (as defined by the common C convention).
	// if(format == 'p')
	// 	// %p The void * pointer argument has to be printed in hexadecimal format.
	// if(format == 'd')
	// 	// %d Prints a decimal (base 10) number.
	// if(format == 'i')
	// 	// %i Prints an integer in base 10.
	// if(format == 'u')
	// 	// %u Prints an unsigned decimal (base 10) number.
	// if(format == 'x')
	// 	// %x Prints a number in hexadecimal (base 16) lowercase format.
	// if(format == 'X')
	// 	// %X Prints a number in hexadecimal (base 16) uppercase format.
	// if(format == '%')
	// 	// %% Prints a percent sign.

	return (0);
}

int	ft_handle_flags(char *str, char *p)
{
	char	*flags;
	int		i;
	int		len;
	char	*str_flags;

	flags = "-0.# +";
	len = 0;
	i = 0;
	while (str[i])
	{
		if(ft_strchr(flags, str[i]))
		{
			len++;
			i++;
		}
		else
			i = ft_strlen(str);
	}
	if (len == 0)
		return (0);
	str_flags = malloc(sizeof(char) * (len + 1));
	if(str_flags == NULL)
		return (0);
	i = 0;
	while (str[i] && i < len)
	{
		str_flags[i] = *ft_strchr(flags, str[i]);
		i++;
	}
	printf("fff = %s\n", str_flags);
	str_flags[i] = '\0';
	*p = *str_flags;
	return (len);
}

int ft_handle_specifier(char *str, char *c)
{
	char	*specifier;
	int		i;

	specifier = "cspdiuxX%";
	i = 0;
	if (ft_strchr(specifier, *str))
	{
		*c = *ft_strchr(specifier, str[i]);
		return (1);
	}
	return (0);
}
