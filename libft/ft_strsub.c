/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 08:52:08 by ataibi            #+#    #+#             */
/*   Updated: 2016/04/18 15:57:21 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	int		index;

	index = 0;
	if (s)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[start] != '\0' && len > 0)
		{
			newstr[index] = s[start];
			len--;
			index++;
			start++;
		}
		newstr[index] = '\0';
		return (newstr);
	}
	else
		return (NULL);
}
