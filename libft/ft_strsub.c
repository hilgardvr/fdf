/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:47:55 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/09 13:38:25 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	ctr;
	char	*new_str;

	ctr = 0;
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	ft_strncpy(new_str, &s[start], len);
	return (new_str);
}
