/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bburston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:27:46 by bburston          #+#    #+#             */
/*   Updated: 2022/06/13 17:07:09 by bburston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_print
{
	va_list	args;
	int		counter;
}	t_print;

void	chars(t_print *argnb);
void	string(t_print *argnb);
void	pointer(t_print *argnb);
void	hex(t_print *argnb, char character);
void	ints(t_print *argnb);
void	unsignedint(t_print *argnb);
int		ft_printf(const char *string, ...);

#endif
