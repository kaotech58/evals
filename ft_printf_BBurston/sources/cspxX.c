/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspxX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:35:58 by bburston          #+#    #+#             */
/*   Updated: 2022/06/13 17:05:32 by bburston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*numberlength(unsigned long number, int *length)
{
	char	*string;

	while (number >= 16)
	{
		number = number / 16;
		*length += 1;
	}
	string = (char *)malloc((*length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[*length] = '\0';
	return (string);
}

void	chars(t_print *argnb)
{
	ft_putchar_fd(va_arg(argnb->args, int), 1);
	argnb->counter++;
}

void	string(t_print *argnb)
{
	char	*string;
	int		length;

	string = va_arg(argnb->args, char *);
	if (string == NULL)
	{
		ft_putstr_fd("(null)", 1);
		argnb->counter += 6;
	}
	else
	{
		length = ft_strlen(string);
		ft_putstr_fd(string, 1);
		argnb->counter += length;
	}
}

void	pointer(t_print *argnb)
{
	int				length;
	char			*string;
	unsigned long	number;

	number = va_arg(argnb->args, unsigned long);
	length = 1;
	string = numberlength(number, &length);
	ft_putstr_fd("0x", 1);
	argnb->counter += 2;
	length--;
	while (length >= 0)
	{
		if (number % 16 < 10)
			string[length] = '0' + (number % 16);
		else
			string[length] = 'a' + (number % 16) - 10;
		number = number / 16;
		length--;
		argnb->counter++;
	}
	ft_putstr_fd(string, 1);
	free(string);
}

void	hex(t_print *argnb, char character)
{
	unsigned int	number;
	int				length;
	char			*string;

	number = va_arg(argnb->args, unsigned int);
	length = 1;
	string = numberlength(number, &length);
	length--;
	while (length >= 0)
	{
		if (number % 16 < 10)
			string[length] = '0' + (number % 16);
		else if (character == 'x')
			string[length] = 'a' - 10 + (number % 16);
		else if (character == 'X')
			string[length] = 'A' - 10 + (number % 16);
		number = number / 16;
		length--;
		argnb->counter++;
	}
	ft_putstr_fd(string, 1);
	free(string);
}
