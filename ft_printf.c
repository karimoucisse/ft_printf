
#include "./libft/libft.h"
#include "./headers/libftprintf.h"

int ft_printf(char *format, ...)
{
	va_list	args;
	int		i;
	int		j;
	int		len;
	char *str_args;

	i = 0;
	len = 0;
	j = 0;
	while(format[i])
	{
		if(format[i] == '%' && format[i + 1] != '%')
			len++;
		i++;
	}
	i = 0;
	str_args = malloc(sizeof(char) * (len + 1));
	while(format[i])
	{
		if(format[i + 1] && format[i] == '%')
		{
			str_args[j] = format[i + 1];
			j++;
		}
		i++;
	}
	str_args[j] = '\0';
	i = 0;
	if(len)
	{
		va_start(args, format);
		while (i < len)
		{
			// char *value = va_arg(args, char *);
			ft_handle_format(str_args[i], va_arg(args, char *));
			i++;
		}
		va_end(args);
	}
	else
		printf("%s", format);
	return 0;
}

// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer argument has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.
