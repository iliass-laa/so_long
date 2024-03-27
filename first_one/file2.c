#include "mylib.h"

char    *ft_strdup(char *s, int start, int length)
{
    char    *res;
    int     i;
    int     x;
    int     reslen;

    i = 0;
    reslen = length;
    x = (ft_strlen(s) - start);
    if (start == ft_strlen(s))
        return(NULL);
    if (x < reslen)
        reslen = x;
    res = (char *)malloc(reslen + 1);
    if (!res)
        return(NULL);
    while (i < reslen)
    {
        res[i] = s[start + i];
        i++;
    }
    res[i] = 0;
    return(res);
}

// char    *ft_strjoin(char    *s1, char   *s2, int size)
// {
//     char    *res;
//     int reslen;
//     int s1len;
//     int s2len;
//     int i = 0;
//     int j = 0;

//     s1len =  ft_strlen(s1);
//     s2len = ft_strlen(s2);
//     reslen = s1len + size;
//     if (size > s2len)
//         reslen = s1len + s2len;
//     res = (char *)malloc(reslen + 1);
//     if (!res)
//     {
//         //free(s1);
//         return(NULL);
//     }
//     while (i < s1len)
//     {
//         res[i] = s1[i];
//         i++;
//     }
//     while(i < reslen)
//     {
//         res[i] = s2[j];
//         i++;
//         j++;
//     }
//     res[i] = '\0';
//    // free(s1);
//     return(res);
// }

int     nlp_p(char *s)
{
    int i = 0;
    if (s)
    {
        while(s[i])
        {
            if (s[i] == '\n')
                return(i);
            i++;
        }
    }
    return (i);
}
char    *read_next_line(int x)
{
    static char *chayta;
    if (x < 0)
    {
        free(chayta);
        return (NULL);
    }
    char    *res;
    char    *zoom;
    int rd;
    int nlp;
    int chayta_len;

    res = NULL;
    chayta_len    = ft_strlen(chayta);
    if (chayta_len)
    {
        nlp = nlp_p(chayta);
        res = ft_strjoin(res, chayta, nlp + 1);
        chayta = ft_strdup(chayta, nlp + 1, chayta_len  - (nlp + 1));
    }
    zoom = (char *)malloc(11);
    rd = read(x, zoom, 10);
    zoom[10] = 0;
    while(rd)
    {
        nlp = nlp_p(zoom);
        if (nlp != 10)
        {
            res = ft_strjoin(res, zoom, nlp +1);
            chayta = ft_strdup(zoom, nlp+1, (10 - nlp+ 1));
            free(zoom);
            return (res);
        }
        res = ft_strjoin(res, zoom, rd);
        rd = read(x, zoom, 10);
        zoom[10] = 0; 
    }
    return (res);
}



// int main()
// {
//    // int fd= open("map.ber", O_RDONLY);
//     // char *line = read_next_line(fd);
//     // while (line)
//     // {
//     //     printf("%s", line);
//     //     line = read_next_line(fd); 
//     // }
//     // char **mp = mapy(fd);
//     // int i = 0;
//     // while(i < 8)
//     // {
//     //     printf("%s", mp[i]);
//     //     i++;
//     // }
//     printf("%d\n", maplen("map.ber"));
//    // printf("\n");
//     // printf("%s\n", line);
//     // line = read_next_line(fd);
//     //  printf("%s\n", line);
// }