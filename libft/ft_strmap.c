/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:59:43 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/08 15:50:51 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s);
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	len = 0;
	while (s[len])
	{
		new_str[len] = f(s[len]);
		len++;
	}
	return (new_str);
}
