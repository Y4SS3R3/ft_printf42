/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:33:20 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/30 15:50:28 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printadd(unsigned long long num)
{
	char	*base;
	char	tmp[16];
	int		i;
	int		count;

	base = "0123456789abcdef";
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

int	print_adress(void *adress)
{
	size_t				count;
	unsigned long long	num;

	count = 0;
	num = (unsigned long long)adress;
	count += print_char('0');
	count += print_char('x');
	count += printadd(num);
	return (count);
}
