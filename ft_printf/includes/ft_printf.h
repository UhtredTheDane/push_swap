#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

size_t		char_recovery(va_list *it);
char	*ft_utoa(unsigned int n);
size_t		hexa_recovery(char c, va_list *it);
char	*hexa_convert(unsigned long n);
size_t		int_recovery(char c, va_list *it);
size_t		p_recovery(va_list *it);
size_t		str_recovery(va_list *it);
int		ft_printf(const char *format, ...);
#endif
