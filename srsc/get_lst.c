/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 14:08:43 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/07/02 14:32:30 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"
#include "../libft/libft.h"

void				assign_new_lst(t_3d **temp_ptr, t_3d **lst_ptr, t_3d **new)
{
	if (*temp_ptr == NULL)
	{
		*lst_ptr = *new;
		*temp_ptr = *lst_ptr;
	}
}

t_3d				*nn(t_3d *new, int x, int y, int z)
{
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	return (new);
}

t_3d				*get_lst(const int fd, t_3d *lst_ptr)
{
	char			*line;
	char			**s_s;
	t_3d			*new;
	t_3d			*temp_ptr;
	t_ctr			ctr;

	temp_ptr = lst_ptr;
	ctr.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ctr.x = 0;
		s_s = ft_strsplit(line, ' ');
		while (s_s[ctr.x])
		{
			if ((new = (t_3d *)ft_memalloc(sizeof(t_3d))) == NULL)
				return (NULL);
			assign_new_lst(&temp_ptr, &lst_ptr, &new);
			new = nn(new, (ctr.x * G_S), (ctr.y * G_S), ft_atoi(s_s[ctr.x]));
			temp_ptr->next = new;
			temp_ptr = new;
			ctr.x++;
		}
		ctr.y++;
	}
	return (lst_ptr);
}
