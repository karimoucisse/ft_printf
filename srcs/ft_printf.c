
#include "../includes/libft.h"
#include "../includes/printf.h"

int ft_printf(char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	char	*cur_arg;
	char	specifier;
	char	*flags;

	len = 0;
	i = 0;
	cur_arg = format;
	flags = NULL;
	va_start(args, format);
	while (format[i])
	{
		if(format[i] == '%' && format[i + 1])
		{
			cur_arg = va_arg(args, char*);
			// i += ft_handle_flags(&format[i + 1], flags);
			i += ft_handle_specifier(&format[i + 1], &specifier);
			ft_handle_format(cur_arg, flags, specifier, ft_strlen(cur_arg));
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return 0;
}

