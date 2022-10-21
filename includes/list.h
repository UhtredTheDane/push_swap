#include <stdlib.h>
#include <stddef.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

typedef struct s_duo
{
	int				value;
	int				index;
}	t_duo;

