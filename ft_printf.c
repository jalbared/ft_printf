#include "ft_printf.h"

static int	ft_printcases(va_list ap, const char *str, int n)
{
	if (*str == '%')
		n = ft_putchar_n('%', n);
	else if (*str == 'c')
		n = ft_putchar_n(va_arg(ap, int), n);
	else if (*str == 's')
		n = ft_putstr_n(va_arg(ap, char *), n);
	else if (*str == 'p')
	{
		n = ft_putstr_n("0x", n);
		if (n == -1)
			return (-1);
		n = ft_put_n((unsigned long)va_arg(ap, void *), "0123456789abcdef", n);
	}
	else if (*str == 'd' || *str == 'i')
		n = ft_putint_n(va_arg(ap, int), n);
	else if (*str == 'u')
		n = ft_put_n(va_arg(ap, unsigned int), "0123456789", n);
	else if (*str == 'x')
		n = ft_put_n(va_arg(ap, unsigned int), "0123456789abcdef", n);
	else if (*str == 'X')
		n = ft_put_n(va_arg(ap, unsigned int), "0123456789ABCDEF", n);
	return (n);
}

int	ft_printf(const char *str, ...)
{
	int		n;
	va_list	ap;

	va_start(ap, str);
	n = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			n = ft_printcases(ap, str, n);
		}
		else
			n = ft_putchar_n(*str, n);
		if (n == -1)
			return (-1);
		str++;
	}
	va_end(ap);
	return (n);
}
