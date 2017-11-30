#ifndef rt_clu_h
# define rt_clu_h

# include <math.h>
# include <errno.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <signal.h>

# include "frameworks/SDL2.framework/Headers/SDL.h"
# include "frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "frameworks/SDL2_image.framework/Headers/SDL_image.h"

# include "libft.h"
# include "rt_clu_structs.h"
# include "libvector.h"

# define WIN_W				1303
# define WIN_H				733
# define MID_W      		640
# define MID_H      		360

# define F_WIDTH			(double)1024
# define F_HEIGHT			(double)648
# define FOV				60

# define OBJ_UNDEF			0
# define OBJ_SPHERE			1
# define OBJ_PLANE			2
# define OBJ_CYL			3
# define OBJ_CONE			4

# define MOVE_SPEED			(double)10.0
# define ROT_SPEED			(double)0.1
# define PITCH				e->camera.dir.y
# define YAW				e->camera.dir.x

# define _A					(0xff000000)
# define _R					(0x00ff0000)
# define _G					(0x0000ff00)
# define _B					(0x000000ff)

# define MAGIC				(0xBAADA555)

#endif
