/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:10:41 by ataibi            #+#    #+#             */
/*   Updated: 2016/04/18 14:38:51 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				index;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char*)s1;
	s2_cpy = (unsigned char*)s2;
	index = 0;
	while (s1_cpy[index] && s2_cpy[index] && s1_cpy[index] == s2_cpy[index])
		index++;
	return (s1_cpy[index] - s2_cpy[index]);
}
