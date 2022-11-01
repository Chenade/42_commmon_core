#ifndef FDF
#define FDF

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mlx.h"
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
#include "libft.h"

#define NB_PATTERN 2
#define PATTERN_SIZE 4

#define WIDTH 1600
#define HEIGHT 1200

#define COLOR_BLACK 0x0000000
#define COLOR_RED 0x00FF0000
#define COLOR_WHITE 0x00FFFFFF

typedef struct s_color
{
    int r;
    int g;
    int b;
    int rgb;
} t_color;

typedef struct s_cord
{
    int x;
    int y;
    int z;
} t_cord;

typedef struct s_img
{
    void *mlx_img;
    char *addr;
    int bpp;
    int line_len;
    int endian;
    int w;
    int h;
} t_img;

typedef struct s_data
{
    void *win_ptr;
    void *mlx_ptr;
    t_img img;
    char *buf;
    int size;
    t_cord  *u;
    t_cord  *v;
    int w;
    int h;

    int map_h;
    int map_w;
    char **map;
    t_cord **map_3d;
    t_cord **map_2d;
    int line_length;
    int height;
    t_cord  *center;
    t_cord  *rotation;
} t_data;

// main.c
int fdf(char *filename);

//mlx_setup.c
int init_mlx(t_data *d, char *name);
int render_frame(t_data *d);
int handle_keypress(int keysym, t_data *data);
int handle_exit(t_data *data);

//helper.c
long int findSize(char file_name[]);
void print_img_data(t_img *i);
int print_info(char *name);
int print_map(t_data *d, t_cord **map);

// general.c
void free_cord_map(t_data *d);
void free_data(t_data *d);
void print_err(const char *err_msg, t_data *d);
int check_filename(const char *name, const char *ext);

// parse.c
int map_width(t_data *d, char **line);
int read_file(t_data *d, char *name);
int init_map(t_data *d);
int init_var(t_data *d);

// draw.c
void draw_maps(t_data *d);
int ft_matrix_rotate(t_data *d);

// tools.c
void img_pix_put(t_data *d, int x, int y, int color);
int getpixelcolor(t_img *img, int x, int y);
int encode_rgb(t_color c);
int xy_to_x(t_data *d, int x, int y);

#endif
