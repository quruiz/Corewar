/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 16:14:38 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 19:29:36 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../libft/libft/libft.h"

typedef struct		s_asm
{
	char			*name;
	int				input_fd;
	int				output_fd;
	int				error_line;
	struct s_header	*header;
	struct s_code	*code;
}					t_asm;

typedef struct		s_code
{
	int				type;
	char			*line;
	int				nb_line;
	struct s_label	*label;
	struct s_cmd	*cmd;
	struct s_code	*next;
}					t_code;

typedef struct		s_label
{
	char			*label_name;
	off_t			cursor;
}					t_label;

typedef struct		s_cmd
{
	struct s_op		*op_tab;
	int				size;
	char			**params;
	unsigned char	*code;
}					t_cmd;

int					err_code(int code, t_asm *env);
int					init_read(t_asm **env, char **arg);
int					get_header(t_asm *env, char *line);
void    			free_all(t_asm *env);

#endif