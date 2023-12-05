/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:33:55 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/28 21:45:17 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_case(char specifier, va_list args)
{
	size_t	count;

	if (specifier == 'c')
		count = print_char(va_arg(args, int));
	else if (specifier == 's')
		count = print_string(va_arg(args, char *));
	else if (specifier == 'i' || specifier == 'd')
		count = print_sinteger(va_arg(args, int));
	else if (specifier == 'x')
		count = print_hex('x', va_arg(args, unsigned int));
	else if (specifier == 'X')
		count = print_hex('X', va_arg(args, unsigned int));
	else if (specifier == 'p')
		count = print_adress(va_arg(args, void *));
	else if (specifier == 'u')
		count = print_unsigned(va_arg(args, unsigned int));
	else if (specifier == '%')
		count = print_char('%');
	else
		count = print_char(specifier);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	count;
	va_list	args;

	i = 0;
	count = 0;
	if (write(1, "tjriba", 0) == -1)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			else
				count += print_case(format[i], args);
		}
		else
			count += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
