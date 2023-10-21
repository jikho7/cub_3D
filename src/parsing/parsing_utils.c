# include <cub3d.h>

void is_map_valid(t_parse **info);
void ft_fill(char **tab, t_f_fill size, t_f_fill current, char to_fill);
void  flood_fill(char **tab, t_f_fill size, t_f_fill begin);
void is_map_valid(t_parse **info);
void strtrim_matrice(t_parse info, int i);

void init_matrice(t_matrice *matrice)
{
    matrice->height = 0;
    matrice->width = 0;
}

void matrice_size(t_parse **map, t_matrice *matrice)
{
    t_parse *tmp;
    int i;

    tmp = *map;
    while (tmp->next != NULL)
    {
        //printf("%s\n", tmp->content);
        strtrim_matrice(*tmp, i);
        i = 0;
        if (tmp->next != NULL && tmp->content[i] != ' ' && tmp->content[i] != '\t' && tmp->content[i] != '1' && tmp->content[i] != '0')
        {
           // printf("> %s\n", tmp->content);
            tmp = tmp->next;
            i = 0;
        }
        if (tmp->next != NULL && (tmp->content[i] == ' ' || tmp->content[i] == '1' || tmp->content[i] == '0'))
        {
           // printf(">> %s\n", tmp->content);
            while (tmp->content[i])
                i++;
            if (matrice->width < i - 1)
                matrice->width = i - 1;
            tmp = tmp->next;
            matrice->height++;
        }
    }
}

void strtrim_matrice(t_parse info, int i)
{
    (void)i;
	char sign[] = {'\n'};
	t_parse cpy;

	cpy = info;
	cpy.content = ft_strtrim(cpy.content, sign);
}

char** create_matrice(t_parse **info, t_matrice *matrice)
{
    t_parse *tmp;
    int i;
    int j;
    char **tab;

    tab = ft_calloc(sizeof(char *), matrice->height);
    tmp = *info;
    j = 0;
    while (tmp->next != NULL)
    {
        i = 0;
        while (tmp->content[i])
        {
            if (tmp->content[i] != '1' && tmp->content[i] != '0' && tmp->content[i] != '\n' && tmp->content[i] != '\t' && tmp->content[i] == ' ')
            {   
                tmp = tmp->next;
                break;
            }
            if (tmp->content[i] == ' ' || tmp->content[i] == '0' || tmp->content[i] == '1')
            {
                tab[j][i] = tmp->content[i];
            }

            i++;
        }
    }
    return (tab);
}
//         // char** new;

//         // new = malloc(sizeof(char*) * size.y);
//         // for (int i = 0; i < size.y; ++i)
//         // {
//         //         new[i] = malloc(size.x + 1);
//         //         for (int j = 0; j < size.x; ++j)
//         //                 new[i][j] = zone[i][j];
//         //         new[i][size.x] = '\0';
//         // }

//         // return new;
// }

// int main(void)
// {
//     t_f_fill size = {8, 5};
//     char *zone[] = {
//             "11111111",
//             "10001001",
//             "10010001",
//             "10110001",
//             "11100001",
//     };

//     char**  area = make_area(zone, size);
//     for (int i = 0; i < size.y; ++i)
//             printf("%s\n", area[i]);
//     printf("\n");

//     t_f_fill begin = {7, 4};
//     flood_fill(area, size, begin);
//     for (int i = 0; i < size.y; ++i)
//             printf("%s\n", area[i]);
//     return (0);
// }

void  flood_fill(char **tab, t_f_fill size, t_f_fill begin)
{
    ft_fill(tab, size, begin, tab[begin.y][begin.x]);
}

void ft_fill(char **tab, t_f_fill size, t_f_fill current, char to_fill)
{
    if(current.x < 0 || current.x >= size.x  || current.y < 0
        || current.y >= size.y || tab[current.y][current.x] != to_fill)
        return ;
    tab[current.y][current.x] = 'F';
    ft_fill(tab, size, (t_f_fill){current.x + 1, current.y}, to_fill); 
    ft_fill(tab, size, (t_f_fill){current.x - 1, current.y}, to_fill); 
    ft_fill(tab, size, (t_f_fill){current.x, current.y + 1}, to_fill); 
    ft_fill(tab, size, (t_f_fill){current.x, current.y - 1}, to_fill); 
}