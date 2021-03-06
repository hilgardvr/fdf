/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:50:27 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/02 15:30:56 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	new_str = (char *)malloc(size + 1);
	if (new_str == NULL)
		return (NULL);
	ft_bzero((void *)new_str, size);
	new_str[size] = '\0';
	return (new_str);
}
