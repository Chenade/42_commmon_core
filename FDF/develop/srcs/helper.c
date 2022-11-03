#include "fdf.h"

long int findSize(char file_name[])
{
    // opening the file in read mode
    FILE *fp = fopen(file_name, "r");

    // checking if the file exist or not
    if (fp == NULL)
    {
        printf("File Not Found!\n");
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    // calculating the size of the file
    long int res = ftell(fp);

    // closing the file
    fclose(fp);

    return res;
}

void print_img_data(t_img *i)
{
    printf("bit per pixel %d\n", i->bpp);
    printf("endian %d\n", i->endian);
    printf("line_len %d\n", i->line_len);
}

int print_info(char *name)
{
    long size = findSize(name);

    printf("size of file %ld bytes\n", size);

    return size;
}

int print_map(t_data *d, t_vector **map)
{
    int x;
    int y;

    y = -1;
    while (++y < d->map_h)
    {
        x = -1;
        while (++x < d->map_w)
        {
            ft_printf("(%d, %d, %d)  ", map[xy_to_x(d, x, y)]->x, map[xy_to_x(d, x, y)]->y, map[xy_to_x(d, x, y)]->z);
        }
        ft_printf("\n");
    }
    ft_printf("\n");
    return (0);
}

void		*ft_malloc(t_data *d, size_t size)
{
	void	*ptr;

	if (!(ptr = (void*)malloc(size)))
    {
        print_err("Error: Memory allocate failed", d);
		return (NULL);
    }
	ft_bzero(ptr, size);
	return (ptr);
}
