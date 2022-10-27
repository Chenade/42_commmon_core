#include "fdf.h"
const t_pattern patterns[NB_PATTERN] = {(t_pattern){{0, 6, 16, 0}, 2}, (t_pattern){{0, 4, 16, 0}, 3}};

void img_pix_put(t_data *d, int x, int y, int color)
{
    char *pixel;
    ft_printf("\n!%d\n", color);
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

                img_pix_put(d, j + w_off, i + h_off + d->h_off, encode_rgb((t_color){255, 255, 255, 0}));
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
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    // img_pix_put(d, 10, 10, encode_rgb((t_color){255, 255, 255, 0}));
    return (0);
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

int fdf(char *filename)
{
    t_data d;

    ft_bzero(&d, sizeof(d));
    init_mlx(&d, filename);
    if(read_file(&d, filename))
        return (1);
    ft_printf("map height: %d, map width: %d\n", d.map_h, d.map_w);
    {
        img_pix_put(&d, 200, 200, encode_rgb((t_color){0, 0, 0, 0}));
        img_pix_put(&d, 200, 201, encode_rgb((t_color){0, 0, 0, 0}));
        img_pix_put(&d, 200, 202, encode_rgb((t_color){0, 0, 0, 0}));
        img_pix_put(&d, 200, 203, encode_rgb((t_color){0, 0, 0, 0}));
        img_pix_put(&d, 200, 204, encode_rgb((t_color){0, 0, 0, 0}));
        img_pix_put(&d, 200, 205, encode_rgb((t_color){0, 0, 0, 0}));
        // d.num_img = getImgNum(&d);
        // bzero(&d.curr_img, sizeof(t_img2));
        // d.curr_img.p = d.buf;
        // d.images = (t_img2 *)malloc(d.num_img * sizeof(t_img2));
        // fillImage(&d);
        // draw_all_img(&d);
        // print_img_data(&d.img);
    }
    mlx_loop_hook(d.mlx_ptr, render_frame, &d);
    mlx_hook(d.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &d);
    mlx_hook(d.win_ptr, ClientMessage,
             StructureNotifyMask, &handle_exit, &d);
    mlx_loop(d.mlx_ptr);
    free_data(&d);
    return (0);
}

int main(int argc, char **argv)
{
    int fd;
    int status;

    if (argc != 2 || !check_filename(argv[1]))
    {
        ft_printf("Error: Usage: ./fdf {filename}.fdf\n");
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0 || read(fd, 0, 0))
    {
        ft_printf("Error: Cannot open file.\n");
        return (1);
    }
    close (fd);
    status = fdf(argv[1]);
    return (status);
}