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

// void print_img_data(t_img *i)
// {
//     printf("bit per pixel %d\n", i->bpp);
//     printf("endian %d\n", i->endian);
//     printf("line_len %d\n", i->line_len);
// }

int print_info(char *name)
{
    long size = findSize(name);

    printf("size of file %ld bytes\n", size);

    return size;
}
