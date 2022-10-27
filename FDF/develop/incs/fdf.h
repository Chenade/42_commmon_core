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

#define HEIGHT 1600
#define WIDTH 1200

#define COLOR_RED 0x00FF0000
#define COLOR_WHITE 0x00FFFFFF

typedef struct  s_pattern
{
    unsigned char magic[PATTERN_SIZE];
    int byte_color;
}           t_pattern;

typedef struct s_color
{
    int r;
    int g;
    int b;
    int rgb;
} t_color;

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

typedef struct s_img2
{
    char *p;
    t_pattern pattern;
    int w;
    int h;
} t_img2;

typedef struct s_data
{
    void *win_ptr;
    void *mlx_ptr;
    t_img img;
    char *buf;
    int size;
    int w;
    int h;
    int byte_off;

    t_img2 curr_img;
    t_img2 *images;
    int num_img;
    int h_off;

    int map_h;
    int map_w;
    char **map;
    // int w_off;
    // int h_off;
} t_data;

// main.c
void img_pix_put(t_data *d, int x, int y, int color);
int getpixelcolor(t_img *img, int x, int y);
int encode_rgb(t_color c);
int getImgNum(t_data *d);
int fillImage(t_data *d);
void draw_all_img(t_data *d);
void draw_img(t_data *d, int w_off, int h_off, t_img2 *img);
int render_frame(t_data *d);
char *searchPatterns(t_data *d, char *buf);
char *searchPattern(t_data *d, char *buf, const unsigned char *pattern, int n);
int getNextImg(t_data *d);
int fdf(char *filename);;

//mlx_setup.c
int init_mlx(t_data *d, char *name);
int handle_keypress(int keysym, t_data *data);
int handle_exit(t_data *data);

//helper.c
long int findSize(char file_name[]);
void print_img_data(t_img *i);
int print_info(char *name);

// general.c
void free_data(t_data *d);
void print_err(const char *err_msg, t_data *d);
int check_filename(const char *name);
int read_file(t_data *d, char *name);

#endif