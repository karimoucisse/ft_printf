
#include "./libft/libft.h"

int ft_printf(char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while(format[i])
	{
		if(format[i] == '%' && format[i + 1] != '%')
			len++;
		i++;
	}
	if(len)
	{
		va_start(args, format);
		while (len > 0)
		{
			char *value = va_arg(args, char *);
			printf("s= %s\n", value);
			len--;
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
