#ifndef RETROMFA
#define RETROMFA

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
#define NB_PATTERN 2
#define PATTERN_SIZE 4

#define HEIGHT 800
#define WIDTH 800



typedef struct  s_pattern
{
    unsigned char magic[PATTERN_SIZE];
    int byte_color;
}           t_pattern;

const t_pattern patterns[NB_PATTERN] = {(t_pattern){{0, 6, 16, 0}, 2}, (t_pattern){{0, 4, 16, 0}, 3}};
//const t_pattern patterns[NB_PATTERN] = {(t_pattern){{0, 4, 16, 0}, 3}, (t_pattern){{0, 6, 16, 0}, 2}};

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
    // int w_off;
    // int h_off;
} t_data;

void *ft_print_memory(void *addr, unsigned int size);
char *searchPattern(t_data *d, char *buf, const unsigned char *pattern, int n);
char *searchPatterns(t_data *d, char *buf);
int getNextImg(t_data *d);
void draw_img(t_data *d, int w_off, int h_off, t_img2 *img);

#endif