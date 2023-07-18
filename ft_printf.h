#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar_n(char c, int n);
int		ft_putstr_n(char *s, int n);
int		ft_putint_n(int num, int n);
int		ft_put_n(unsigned long num, char *base, int n);

#endif
