/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:18:39 by ataibi            #+#    #+#             */
/*   Updated: 2016/04/18 15:57:58 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		index;

	index = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[index])
	{
		(*f)(index, &s[index]);
		index++;
	}
}
