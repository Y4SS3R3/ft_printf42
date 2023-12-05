/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:31:27 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/24 16:16:10 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(char specifier, unsigned int num)
{
	char	*base;
	char	tmp[8];
	int		i;
	int		count;

	if (specifier == 'x')
		base = "0123456789abcdef";
	else if (specifier == 'X')
		base = "0123456789ABCDEF";
	i = 0;
	count = 0;
	if (num == 0)
		return (print_char('0'));
	while (num)
	{
		tmp[i] = base[num % 16];
		num /= 16;
		i++;
	}
	while (i--)
		count += print_char(tmp[i]);
	return (count);
}
