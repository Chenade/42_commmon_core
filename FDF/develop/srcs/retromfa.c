#include "retromfa.h"
#include "libft.h"

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

void free_data(t_data *d)
{
    if (d->win_ptr)
        mlx_destroy_window(d->mlx_ptr, d->win_ptr);
    if (d->img.mlx_img)
        mlx_destroy_image(d->mlx_ptr, d->img.mlx_img);
    mlx_destroy_display(d->mlx_ptr);
    free(d->mlx_ptr);
    free(d->buf);
    free(d->images);
}

void print_err(const char *err_msg, t_data *d)
{
    fprintf(stderr, "%s\n", err_msg);
    free_data(d);
    exit(EXIT_FAILURE);
}

int handle_exit(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    data->win_ptr = NULL;
    return (0);
}

void img_pix_put(t_data *d, int x, int y, int color)
{
    char *pixel;
    if (y >= 0 && y < HEIGHT)
    {
        pixel = d->img.addr + (y * d->img.line_len + x * (d->img.bpp / 8));
        *(unsigned int *)pixel = color;
    }
}

int getpixelcolor(t_img *img, int x, int y)
{
    return (*(unsigned int *)(img->addr + x * (img->bpp / 8) + y * img->line_len));
}

int encode_rgb(t_color c)
{
    return (c.r << 16 | c.g << 8 | c.b);
}
int getImgNum(t_data *d)
{
    int i = 0;

    while (1)
    {
        t_img2 *img = &d->curr_img;

        char *tmp = searchPatterns(d, (img->p + 1));
        if (!tmp)
            break;
        img->p = tmp;
        i++;
    }
    return (i);
}

int fillImage(t_data *d)
{
    int i = 0;

    while (getNextImg(d))
    {
        d->images[i] = d->curr_img;
        i++;
    }
    return (i);
}

void draw_all_img(t_data *d)
{
    static int h_max;
    int w_off = 0;
    int h_off = 0;
    int i = 0;
    while (i < d->num_img)
    {
        t_img2 *img = d->images + i;
        if (img->h > h_max)
            h_max = img->h;
        if (w_off + img->w > WIDTH)
        {
            w_off = 0;
            h_off += h_max + 20;
            h_max = 0;
        }
        if (h_off + d->h_off > HEIGHT)
            break;
        draw_img(d, w_off, h_off, img);
        w_off += img->w + 20;
        i++;
    }
}

void draw_img(t_data *d, int w_off, int h_off, t_img2 *img)
{
    // for (int i = 0; i < d->h ; ++i)
    // {
    //     for (int j = 0; j < d->w; ++j)
    //     {
    //         int color = *(unsigned int *)(d->buf + j * 3 + i * d->w * 3 + d->byte_off);
    //         img_pix_put(d, j, i, color);
    //     }
    // }
    for (int i = 0; i < img->h; ++i)
    {
        for (int j = 0; j < img->w; ++j)
        {
            if (img->pattern.byte_color == 2)
            {
                unsigned short color = *(unsigned short *)(img->p + j * 2 + i * img->w * 2);
                int r = color >> 10;
                int g = (color >> 5) & 0x1f;
                int b = color & 0x1f;

                r <<= 3;
                g <<= 3;
                b <<= 3;

                img_pix_put(d, j + w_off, i + h_off + d->h_off, encode_rgb((t_color){r, g, b, 0}));
            }
            else
                img_pix_put(d, j + w_off, i + h_off + d->h_off, *(unsigned int *)(img->p + j * 3 + i * (img->w + img->w % 2) * 3));
        }
    }
}

int render_frame(t_data *d)
{
    // bzero(d->img.addr, d->img.line_len * HEIGHT);
    //  draw_all_img(d/);
    // draw_img(d, 0, 0);

    if (d->win_ptr == NULL)
        return (1);
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.mlx_img, 0, 0);
    // img_pix_put(d, 10, 10, encode_rgb((t_color){255, 255, 255, 0}));
    return (0);
}

int handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
    // else if (keysym == XK_Right)
    //     data->w++;
    // else if (keysym == XK_Left)
    //     data->w--;
    else if (keysym == XK_Up)
    {
        // data->h++;
        data->h_off += 10;
        bzero(data->img.addr, data->img.line_len * HEIGHT);
        draw_all_img(data);
    }
    else if (keysym == XK_Down)
    {
        // data->h--;
        data->h_off -= 10;
        bzero(data->img.addr, data->img.line_len * HEIGHT);
        draw_all_img(data);
    }
    // else if (keysym == XK_a)
    // {
    //     data->byte_off--;
    // }
    // else if (keysym == XK_d)
    // {
    //     data->byte_off++;
    // }
    // else if (keysym == XK_p)
    // {
    //     if (!getNextImg(data))
    //         return (mlx_loop_end(data->mlx_ptr));
    // }
    return (0);
}

void print_img_data(t_img *i)
{
    printf("bit per pixel %d\n", i->bpp);
    printf("endian %d\n", i->endian);
    printf("line_len %d\n", i->line_len);
}
// void print_title(int fd)
// {
//     int x;
//     read(fd, &x, 4); // mfa magic number
//     printf("x %d\n", x);
//     read(fd, &x, 4); // mfa magic number
//     printf("x %d\n", x);
//     read(fd, &x, 4); // mfa magic number
//     printf("x %d\n", x);
//     read(fd, &x, 4); // mfa magic number
//     printf("x %d\n", x);

//     {
//         int title_len;
//         read(fd, &title_len, 4);
//         char *title = malloc(title_len + 1);
//         title[title_len] = 0;
//         read(fd, title, title_len);
//         printf("title - len %d : %s\n", title_len, title);
//         free(title);
//     }

//     {
//         int something;
//         read(fd, &something, 4);
//         char *title = malloc(something + 1);
//         title[something] = 0;
//         read(fd, title, something);
//         printf("sub-title - len %d : %s\n", something, title);
//         free(title);
//     }
//     {
//         int something;
//         read(fd, &something, 4);
//         char *title = malloc(something + 1);
//         title[something] = 0;
//         read(fd, title, something);
//         printf("info - len %d : %s\n", something, title);
//         free(title);
//     }
// }

int print_info(char *name)
{
    long size = findSize(name);

    printf("size of file %ld bytes\n", size);

    return size;
}

char *searchPatterns(t_data *d, char *buf)
{
    for (int i = 0; i < NB_PATTERN; i++)
    {
        char *res = searchPattern(d, buf, patterns[i].magic, PATTERN_SIZE);
        if (res)
        {
            d->curr_img.pattern = patterns[i];

            return (res);
        }
    }
    return NULL;
}

char *searchPattern(t_data *d, char *buf, const unsigned char *pattern, int n)
{
    if (!buf)
        return 0;
    for (int i = 0; i < d->size - (d->curr_img.p - d->buf) - n; i++)
    {
        int j = 0;
        while (j < n && i + j < d->size && ((unsigned char *)(buf))[i + j] == pattern[j])
        {
            j++;
        }
        if (j == n && i - 1 > 0 && buf[i - 1] != 0 && i - 3 > 0 && buf[i - 3] != 0)
        {
            return (buf + i);
        }
    }
    return NULL;
}

int getNextImg(t_data *d)
{
    t_img2 *img = &d->curr_img;

    char *tmp = searchPatterns(d, (img->p + 1));

    if (!tmp)
        return (0);
    img->p = tmp;
    img->h = *(unsigned char *)(img->p - 1);
    img->w = *(unsigned char *)(img->p - 3);
    img->p += 17;
    return (1);
}
int check_mfa(const char *name)
{

    int x = strlen(name) - 3;
    if (strcmp(name + x, "mfa"))
        return (0);
    return (1);
}

int main(int argc, char **argv)
{

    if (argc != 2 || !check_mfa(argv[1]))
    {
        ft_printf("Error: Usage: ./retromfa {filename}.mfa\n");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0 || read(fd, 0, 0))
    {
        printf("Error: Cannot open file.");
        return 1;
    }

    t_data d;
    bzero(&d, sizeof(d));

    // print_title(fd);
    d.size = print_info(argv[1]);
    d.buf = (char *)malloc(d.size);
    bzero(d.buf, d.size);

    d.w = WIDTH;
    d.h = HEIGHT;

    {
        d.mlx_ptr = mlx_init();
        d.win_ptr = mlx_new_window(d.mlx_ptr, d.w, d.h, "retromfa");
        if (!d.win_ptr)
            print_err("Failed to launch window.", &d);
        d.img.mlx_img = mlx_new_image(d.mlx_ptr, d.w, d.h);
        if (!d.img.mlx_img)
            print_err("mlx new image error", &d);
        d.img.addr = mlx_get_data_addr(d.img.mlx_img, &d.img.bpp,
                                       &d.img.line_len, &d.img.endian);
    }
    d.curr_img.p = d.buf;
    size_t total = 0;
    while (1)
    {
        ssize_t c = read(fd, d.buf + total, d.size - total);
        if (c == -1)
        {
            printf("failed to read the file.");
            // free les trucs
            return (1);
        }
        if (c == 0)
            break;
        total += c;
    }
    // getNextImg(&d);

    // d.byte_off = d.p - d.buf;
    d.num_img = getImgNum(&d);
    bzero(&d.curr_img, sizeof(t_img2));
    d.curr_img.p = d.buf;
    printf("nb img %d\n", d.num_img);
    d.images = (t_img2 *)malloc(d.num_img * sizeof(t_img2));
    fillImage(&d);
    draw_all_img(&d);
    print_img_data(&d.img);

    mlx_loop_hook(d.mlx_ptr, render_frame, &d);
    mlx_hook(d.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &d);
    mlx_hook(d.win_ptr, ClientMessage,
             StructureNotifyMask, &handle_exit, &d);
    mlx_loop(d.mlx_ptr);
    free_data(&d);
    close(fd);
    return (0);
}

// size_t something;
// read(fd, &something, 4);
// printf("here something %u\n", something);
// read(fd, &something, 4);
// printf("here something %u\n", something);

// while(read(fd, &something, 4) > 0)
// {

//     printf("here something %u\n", something);
//     char *title = malloc(something + 1);
//     bzero(title, something + 1);
//     read(fd, title, something);
//     title[something] = 0;
//     printf("title %s\n", title);
//     free(title);
// }

// int fd2 = open("MFA/brown.mfa", O_RDONLY);
// test(fd2);

// int something = 0;
// int something2 = 0;
// read(fd, &something, 4);
// read(fd2, &something2, 4);
// printf("something %d\n", something);

// // print ^
// int same = 0;
// while (same < 14)
// {
//     read(fd, &something, 4);
//     read(fd2, &something2, 4);
//     //printf("fd something %d\n", something);
//     same++;
//     //printf("fd something2 %d\n", something2);
//     // char *title = malloc(something + 1);
//     // title[something] = 0;
//     // read(fd, title, something);
//     // printf("title %s\n", title);
// }
// printf("same %d\n", same);
// read(fd, &something, 4);
// printf("something %u\n", something);