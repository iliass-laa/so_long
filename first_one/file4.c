#include "mylib.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			i++;
		}
	}
	return (i);
}

int	find_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	struct s_my	my1;

	my1.j = len;
	my1.i = 0;
	my1.x = 0;
	my1.s2len = ft_strlen(s2);
	my1.s1len = ft_strlen(s1);
	if (len > my1.s2len)
		my1.j = my1.s2len;
	my1.res = (char *)malloc(my1.j + my1.s1len + 1);
	if (!my1.res)
		return (free(s1), NULL);
	while (my1.i < my1.s1len)
	{
		my1.res[my1.i] = s1[my1.i];
		my1.i++;
	}
	while (my1.x < my1.j)
	{
		my1.res[my1.i + (my1.x)] = s2[my1.x];
		my1.x++;
	}
	my1.res[my1.x + my1.i] = 0;
	return (free(s1), my1.res);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*res;
	int		i;
	int		sublen;
	int		srclen;

	i = 0;
	srclen = ft_strlen(s);
	sublen = len;
	if (srclen <= start + len)
		sublen = srclen - start;
	if (sublen == 0 && srclen != 1)
		return (free(s), NULL);
	res = (char *)malloc((sublen + 1) * (sizeof(char)));
	if (!res)
		return (free(s), NULL);
	while (i < sublen)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (free(s), res);
}

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
		if (var->nlpos != BUFFER_SIZE)
		{
			var->res = ft_strjoin(var->res, var->zoom, var->nlpos + 1);
			if (!ft_strlen(var->res))
				return (freedom(&var->zoom, chyata, &var->res, 3), NULL);
			*chyata = ft_substr(var->zoom, var->nlpos + 1, var->len
					- (var->nlpos + 1));
			if (ft_strlen(*chyata) == 0)
				freedom(&var->zoom, chyata, &var->res, 1);
			return (var->res);
		}
		var->res = ft_strjoin(var->res, var->zoom, BUFFER_SIZE);
		if (!var->res)
			return (freedom(&var->zoom, chyata, &var->res, 3), NULL);
		(*var).readed = read(fd, var->zoom, BUFFER_SIZE);
		var->zoom[var->readed] = 0;
	}
	if (ft_strlen(var->res))
		return (freedom(&var->zoom, chyata, &var->res, 5), var->res);
	return (var->res);
}

char	*elso2(char *res, char **chyata, int nlpos, char *zoom)
{
	res = ft_strjoin(res, *chyata, nlpos + 1);
	if (!res)
		return (freedom(&zoom, chyata, &res, 2), NULL);
	*chyata = ft_substr(*chyata, nlpos + 1, ft_strlen(*chyata) - (nlpos + 1));
	if (!*chyata)
		freedom(&zoom, chyata, &res, 1);
	return (free(zoom), res);
}

char	*get_next_line(int fd)
{
	struct s_next	var;
	static char		*chyata;

	var.zoom = (char *)malloc(BUFFER_SIZE + 1);
	if (!var.zoom)
		return (freedom(&var.zoom, &chyata, &var.res, 1), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, var.zoom, 0) != 0)
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
	var.readed = read(fd, var.zoom, BUFFER_SIZE);
	var.zoom[var.readed] = 0;
	if (var.readed != 0)
		return (lecture2(&var, &chyata, fd));
	return (fabor(&var, &chyata, 2));
}


