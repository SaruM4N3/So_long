
typedef struct s_coord
{
	int		pos_x;
	int		pos_y;
	int		target_x;
	int		target_y;
}			t_coord;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

enum colors 
{
	red = 0x00FF0000,
	green = 0x0000FF00,
	blue = 0x000000FF,
	cyan = 0x0000FFFF,
	yellow = 0x00FFFF00,
	magenta = 0x00FF00FF,
	orange = 0x00FF8000,
	grey = 0x00888888,
	white = 0xFFFFFFFF
};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_draw_line(t_data *data, t_coord *coord, int color);
void	my_mlx_draw_square(t_data *data, t_coord *coord, int size, int color);
