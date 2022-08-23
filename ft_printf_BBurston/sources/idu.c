/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:19:02 by bburston          #+#    #+#             */
/*   Updated: 2022/05/16 14:23:49 by bburston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numberlength(unsigned int number)
{
	int	length;

	length = 1;
	while (number > 9)
	{
		number = number / 10;
		length++;
	}
	return (length);
}

static char	*itoa(unsigned int number)
{
	char	*string;
	int		length;

	length = numberlength(number);
	string = (char *)malloc(length + 1 * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[length] = '\0';
	while (length > 0)
	{
		string[--length] = number % 10 + '0';
		number = number / 10;
	}
	return (string);
}

void	ints(t_print *argnb)
{
	char	*string;
	int		result;

	result = va_arg(argnb->args, int);
	string = ft_itoa(result);
	ft_putstr_fd(string, 1);
	argnb->counter += ft_strlen(string);
	free(string);
}

void	unsignedint(t_print *argnb)
{
	char			*string;
	unsigned int	result;

	result = va_arg(argnb->args, unsigned int);
	string = itoa(result);
	ft_putstr_fd(string, 1);
	argnb->counter += ft_strlen(string);
	free(string);
}
