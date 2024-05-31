
// #include "libftprintf.h"
#include "libft.h"

int ft_printf(char *format, ...)
{
	va_list	ap;
	int	nb_args;
	char	*cur_arg;

	nb_args = 0;
	cur_arg = format;
	va_start(ap, format);
	while(cur_arg)
	{
		nb_args++;
		cur_arg = va_arg(ap, char *);
	}

	printf("%s\n", format);
	va_end(ap);
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
