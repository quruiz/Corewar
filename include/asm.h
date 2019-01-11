/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 16:14:38 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 18:04:48 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../libft/libft/libft.h"

typedef struct		s_asm
{
	char			*raw_file;
	char			**file;
	int				i;
	int				input_fd;
	int				output_fd;
	struct s_header	*header;
	struct s_champ	*champ;
}					t_asm;

typedef struct		s_champ
{
	int				type;
	char			*line;
	int				nb_line;
	struct s_label	*label;
	struct s_code	*code;
	struct s_code	*next;
}					t_champ;

typedef struct		s_label
{
	char			*label_name;
	off_t			cursor;
}					t_label;

typedef struct		s_code
{
	struct s_op		*op_tab;
	int				size;
	char			**params;
	unsigned char	*code;
}					t_code;

int					err_code(int code, char *msg);
int					read_file(t_asm **env, char **arg);
int					get_header(t_asm *env);

#endif