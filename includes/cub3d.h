#ifndef CUB_3D_H
# define CUB_3D_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../libs/libft/includes/libft.h"
# include "../libs/libft/includes/ft_printf.h"
# include "../libs/libft/includes/get_next_line.h"
# include "../libs/minilibx/mlx.h"
#include <fcntl.h>
#include <math.h>
#define tW 64
#define tH 64
#define	sH 1080
#define sW 1920

typedef	enum				e_error
{
	ERROR,
	ZBUFFER_ERROR,
	NB_ARG_ERROR,
	NB_ARG_ERROR_TOO_FEW,
	NB_ARG_ERROR_TOO_MANY,
	FILE_EXT_ERROR,
	SAVE_FLAG_ERROR,
	FILE_READ_ERROR,
	SCREEN_ERROR,
	ARGUMENT_ERROR,
	PATH_ERROR,
	UNKNOW_ARG,
	RGB_ERROR,
	OPEN_ERROR,
	WRITE_ERROR,
	FROM_LST_ERROR,
	MAP_ERROR,
	MAP_ERROR_WRONG_CHAR,
	MAP_ERROR_MANY_POS,
	MAP_ERROR_NO_POS,
	MAP_ERROR_NOT_CLOSED,
	MAP_ERROR_SAME_SIZE,
	MALLOC_ERROR,
	IMG_ERROR,
	IMG_ERROR_WEAPON_1,
	IMG_ERROR_WEAPON_2,
	IMG_ERROR_WEAPON_3,
	IMG_ERROR_WEAPON_4,
	IMG_ERROR_WEAPON_5,
	IMG_ERROR_ITEM,
	TEX_ERROR_N,
	TEX_ERROR_S,
	TEX_ERROR_W,
	TEX_ERROR_E,
	TEX_ERROR_SP,
	TEX_ERROR_SP1,
	TEX_ERROR_D,
	TEX_ERROR_B,
	TEX_ERROR_A,
	TEX_ERROR_T,
	TEX_ERROR_E1,
	TEX_ERROR_E2,
	TEX_ERROR_E3,
	TEX_ERROR_E4,
	TEX_ERROR_E5,
	TEX_ERROR_E6,
	TEX_ERROR_E7,
	TEX_ERROR_E8,
	TEX_ERROR_E9,
	TEX_ERROR_ENNEMY,
	MLX_ERROR,
	TEX_ERROR,
	PIXEL_ERROR,
	COLOR_ERROR,
	SUCCESS
}	                    t_error;

typedef struct s_map
{
  char  *n_tex;
  char  *s_tex;
  char  *w_tex;
  char  *e_tex;
  char  *map;
  int	color[2];
  int    **world;
  int	*arr;
  int    mW;
  int    mH;
  int	check;
}               t_map;

typedef struct	s_tex
{
	char	*path;
	void	*tex;
	void	*ptr;
	
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}				t_tex;

typedef struct	s_draw
{
	int		dStart;
	int		dEnd;
	int		mapX;
  int     mapY;
	int		stepX;
	int		stepY;
  int     side;
  int     texX;
  double     sDistX;
  double     sDistY;
  double  wallX;
  double  step;
  double texPos;
  double perpWallDist;
  int m_left;

}				t_draw;

typedef struct  s_pos {
    double pX;
    double pY;
    double dY;  //x and y start position
    double dX; //initial direction vector
    double plX; //the 2d raycaster version of camera plane
    double plY;
    int         mu;
    int         md;
    int         ml;
    int         mr;
    int         rr;
    int         rl;
    int         spd;
    void       *img;
    int        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    void        *mlx;
    void        *win;
    t_draw      draw;
    t_tex       tex[4];
    t_map       map;
    
    
}               t_pos;

void	ft_unset_mlx(t_pos *pos);
int			exit_game(t_pos *pos);
int			render_next_frame(t_pos *pos);
int		          ft_draw_wall(t_pos *pos, int x, int y);
int             key_hook(int keycode, t_pos *pos);
int             key_hook_rel(int keycode, t_pos *pos);
int			        ft_textures(t_pos *pos, int sides);
void            my_mlx_pixel_put(t_pos *pos, int x, int y, int color);
int             get_tex_color(t_tex *tex, int x, int y);
int		          create_trgb(int t, int r, int g, int b);
void			ft_draw(t_pos *pos, double *z_buffer);
void     		ft_rgb(int num, t_pos *pos, char *line);
void            ft_load_texture(t_pos *pos, char *line, int i);
void            ft_calculate_wall(double *_buffer, t_pos *pos, int x);
void            ft_rgb(int num, t_pos *pos, char *line);
void            ft_read_file(t_pos *pos, char **av);
void            ft_tex_num(t_pos *pos);
void            ft_move(t_pos *pos);
void            ft_rotate(t_pos *pos);

void	ft_print_aux(t_pos *pos);
void     exit_error(t_pos *pos);
#endif