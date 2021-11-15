/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: an7onie77i <an7onie77i@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:01:22 by vantonie          #+#    #+#             */
/*   Updated: 2021/11/14 21:36:57 by an7onie77i       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_sort(const char *format, va_list ap, t_len *len)
{
	if (*format == 'c')
		ft_printf_c(va_arg(ap, int), len);
	else if (*format == 'd')
		ft_printf_d(va_arg(ap, int), len);
	else if (*format == 'i')
		ft_printf_i(va_arg(ap, int), len);
	else if (*format == 'p')
		ft_printf_p(va_arg(ap, void *), len);
	else if (*format == 's')
		ft_printf_s(va_arg(ap, char *), len);
	else if (*format == 'u')
		ft_printf_u(va_arg(ap, unsigned int), len);
	else if (*format == 'x')
		ft_printf_x(va_arg(ap, unsigned int), len);
	else if (*format == 'X')
		ft_printf_xu(va_arg(ap, unsigned int), len);
}

static int	ft_vfprintf(const char *format, va_list ap, t_len *len)
{
	len->i = 0;
	while (format[len->i] != '\0')
	{
		if (format[len->i] == '%')
		{
			len->i++;
			ft_printf_sort(&format[len->i], ap, len);
			len->i++;
		}
		else
		{
		ft_putchar_fd(format[len->i], 1);
		len->i++;
		len->len++;
		}
	}
	return(0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_len	*len;
	int		print_len;

	len = (void *) malloc(1 * sizeof(t_len));
	va_start(ap, format);
	ft_vfprintf(format, ap, len);
	va_end(ap);
	print_len = len->len;
	free(len);
	return(print_len);
}
