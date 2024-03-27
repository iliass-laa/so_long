#include "mylib.h"

int maplen(char *s)
{
    int i;
    int fd;
    char    *str;

    i = 0;
    fd = open(s, O_RDONLY);
    str = get_next_line(fd);
    if (str)
    {
        while (str)
        {
            free(str);
            str = get_next_line(fd);
            i++;
            
        }
    }
    close (fd);
    return (i);
}

int checkpath(char *path)
{
    int i;
    int j;
    int x;
    char    *s;

    s = ".ber";
    x = 0;
    i = ft_strlen(path);
    j = i - 4;
    while(s[x])
    {
        if (s[x] != path[j])
            return (0);
        x++;
        j++;
    }
    return (1);
}

int checkmap(char   **str)
{
    int x;
    int y;
    int p;
    int c;
    int e;

    p = 0;
    c = 0;
    e = 0;
    x = 0;
    y = 0;

    while(str[x])
    {
        y = 0;
        while (str[x][y])
        {
            if (str[x][y] == 'P')
                p+= 1;
            else if (str[x][y] == 67)
            { 
                c ++;
            }
               
            else if (str[x][y] == 'E')
                e+=1;
            else if (str[x][y] != 'P' & str[x][y] !=  'C' & str[x][y] != 'E' & str[x][y] !=  '1' & str[x][y] != '0' & str[x][y] != '\n')
                return (-1);
            if (str[x][y] == '\n' && str[x][y + 1] == '\n')
                return( -1);

            y++;
        }
        if (y <= 4)
        {
            // printf("y-1\n");
            return - 1;
        }
        // printf("")
        x++;
    }
    if (x <= 2)
        return - 1;
    if (c <= 0 || p != 1 || e != 1)
        return (-2);
    return (1);
}
int     success_path(char **s, int x, int y)
{
    int tot;
    int i;


    tot = 0;
    if (s[y][x] == '1' || s[y][x] == 'V')
        return (0);
    if (s[y][x] == 'C')
        tot += 1;
    s[y][x] = 'V';
    tot += success_path(s,  x + 1, y);
    tot += success_path(s, x, y + 1);
    tot += success_path(s, x - 1, y);
    tot += success_path(s, x, y - 1);
    return (tot);
}

char    **mapy (char *path)
{
    char    **res ;
    int     i;
    int     map_len;
    int     fd;

    i = 0;
    map_len = maplen(path);
    res  = (char **)malloc(sizeof(char *) * (map_len  + 1));
    if (!res)
        return (NULL);
    fd = open(path , O_RDONLY);
    while(i < map_len)
    {
        res[i] = get_next_line(fd);
        if (!res[i])
        {
            while (i >= 0)
                free(res[i --]);
            return (free(res), NULL);
        } 
        i++;
    }
    res[i] = 0;
    close(fd);
    if (checkmap(res) < 0)
        return(NULL);
    return(res);
}
