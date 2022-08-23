/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:29:42 by bburston          #+#    #+#             */
/*   Updated: 2022/06/13 17:54:20 by bburston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print	*start(void)
{
	t_print	*argnb;

	argnb = malloc(sizeof(t_print));
	if (argnb == NULL)
		return (NULL);
	argnb->counter = 0;
	return (argnb);
}

void	printcheck(const char character, t_print *argnb)
{
	if (character == 'c')
		chars(argnb);
	else if (character == 's')
		string(argnb);
	else if (character == 'p')
		pointer(argnb);
	else if (character == 'i' || character == 'd')
		ints(argnb);
	else if (character == 'u')
		unsignedint(argnb);
	else if (character == 'x' || character == 'X')
		hex(argnb, character);
	else if (character == '%')
	{
		ft_putchar_fd('%', 1);
		argnb->counter++;
	}
	else if (character != '\0')
	{
		write(1, &character, 1);
		argnb->counter++;
	}
}

int	ft_printf(const char *string, ...)
{
	t_print	*argnb;
	int		printcomplete;
	int		i;

	i = 0;
	argnb = start();
	printcomplete = 0;
	va_start(argnb->args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			printcheck(string[++i], argnb);
		else
		{
			ft_putchar_fd(string[i], 1);
			argnb->counter++;
		}
		if (string[i] != '\0')
			i++;
	}
	printcomplete = argnb->counter++;
	va_end(argnb->args);
	free(argnb);
	return (printcomplete);
}
