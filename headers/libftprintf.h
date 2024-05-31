#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

typedef struct T_FORMAT
{
	char	*format;
	char	*arg;
}t_format;

int	ft_handle_format(char	format, char	*arg);

#endif

