#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

typedef struct T_FORMAT
{
	char	*str;
	char	specifier;
	char	flags;
	int		min_len;
	// int		precision;
	// int		length;
}t_format;
// %[flags][width][.precision][length]specifier

int	ft_handle_format(char *str, char *flags, char specifier, int min_len);
int	ft_handle_flags(char *str, char *p);
int ft_handle_specifier(char *str, char *c);
#endif

