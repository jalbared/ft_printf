#include "ft_printf.h"

static unsigned int	ft_unsigned_len(unsigned long n, unsigned int base)
{
	unsigned long	l;

	l = 1;
	while (n > (base - 1))
	{
		n = n / base;
		l++;
	}
	return (l);
}

int	ft_putchar_n(char c, int n)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (n + 1);
}

int	ft_putstr_n(char *s, int n)
{
	int	l;

	if (!s)
		s = "(null)";
	l = 0;
	while (s[l])
		l++;
	if (write(1, s, l) == -1)
		return (-1);
	return (n + l);
}

int	ft_putint_n(int num, int n)
{
	if (num < 0)
	{
		if (num == -2147483648)
			return (n = ft_putstr_n("-2147483648", n));
		else
		{
			n = ft_putchar_n('-', n);
			if (n == -1)
				return (-1);
			num = -1 * num;
		}
	}
	n = ft_put_n((unsigned long)num, "0123456789", n);
	return (n);
}

int	ft_put_n(unsigned long num, char *base, int n)
{
	unsigned long	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (num < base_len && n != -1)
	{
		if (ft_putchar_n(base[num], n) == -1)
			return (-1);
	}
	else if (n != -1)
	{
		if (ft_put_n(num / base_len, base, n) == -1)
			return (-1);
		if (ft_putchar_n(base[num % base_len], n) == -1)
			return (-1);
	}
	if (n == -1)
		return (-1);
	return (n + ft_unsigned_len(num, base_len));
}
