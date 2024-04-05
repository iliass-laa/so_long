/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:54:34 by ilaasri           #+#    #+#             */
/*   Updated: 2024/04/02 23:54:35 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	freedom(char **zoom, char **chyata, char **res, int howmany)
{
	if (howmany == 1 || howmany == 2 || howmany == 3)
	{
		free(*chyata);
		*chyata = NULL;
	}
	if (howmany == 2 || howmany == 3 || howmany == 5)
	{
		free(*zoom);
		*zoom = NULL;
	}
	if (howmany == 3)
	{
		free(*res);
		*res = NULL;
	}
}

char	*fabor(struct s_next *var, char **chyata, int whichone)
{
	if (whichone == 1)
	{
		var->res = ft_strjoin(var->res, *chyata, var->nlpos + 1);
		freedom(&var->zoom, chyata, &var->res, 1);
		return (var->res);
	}
	else
	{
		if (ft_strlen(var->res) != 0)
		{
			return (free(var->zoom), var->res);
		}
		else
		{
			return (freedom(&var->zoom, chyata, &var->res, 3), NULL);
		}
	}
}

char	*lecture2(struct s_next *var, char **chyata, int fd)
{
	while (var->readed)
	{
		var->nlpos = find_nl(var->zoom);
		var->len = ft_strlen(var->zoom);
		if (var->nlpos != 50)
		{
			var->res = ft_strjoin(var->res, var->zoom, var->nlpos);
			if (!ft_strlen(var->res))
				return (freedom(&var->zoom, chyata, &var->res, 3), NULL);
			*chyata = ft_substr(var->zoom, var->nlpos + 1, var->len
					- (var->nlpos + 1));
			if (ft_strlen(*chyata) == 0)
				freedom(&var->zoom, chyata, &var->res, 1);
			return (var->res);
		}
		var->res = ft_strjoin(var->res, var->zoom, 50);
		if (!var->res)
			return (freedom(&var->zoom, chyata, &var->res, 3), NULL);
		(*var).readed = read(fd, var->zoom, 50);
		var->zoom[var->readed] = 0;
	}
	if (ft_strlen(var->res))
		return (freedom(&var->zoom, chyata, &var->res, 5), var->res);
	return (var->res);
}

char	*elso2(char *res, char **chyata, int nlpos, char *zoom)
{
	res = ft_strjoin(res, *chyata, nlpos);
	if (!res)
		return (freedom(&zoom, chyata, &res, 2), NULL);
	*chyata = ft_substr(*chyata, nlpos + 1, ft_strlen(*chyata) - (nlpos + 1));
	if (!*chyata)
		freedom(&zoom, chyata, &res, 1);
	return (free(zoom), res);
}

char	*read_lines(int fd)
{
	struct s_next	var;
	static char		*chyata;

	var.zoom = (char *)malloc(50 + 1);
	if (!var.zoom)
		return (freedom(&var.zoom, &chyata, &var.res, 1), NULL);
	if (fd < 0 || read(fd, var.zoom, 0) != 0)
		return (freedom(&var.zoom, &chyata, &var.res, 2), NULL);
	var.res = NULL;
	if (ft_strlen(chyata))
	{
		var.nlpos = find_nl(chyata);
		var.len = ft_strlen(chyata);
		if (var.nlpos == var.len)
			var.res = fabor(&var, &chyata, 1);
		else
			return (elso2(var.res, &chyata, var.nlpos, var.zoom));
	}
	var.readed = read(fd, var.zoom, 50);
	var.zoom[var.readed] = 0;
	if (var.readed != 0)
		return (lecture2(&var, &chyata, fd));
	return (fabor(&var, &chyata, 2));
}
