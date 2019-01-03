/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 16:14:38 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/02 16:30:24 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../libft/libft/libft.h"

enum				e_type
{
	OPCODE,
	LABEL,
	COMMENT
};

typedef struct		s_asm
{
	char			*raw_file;
	char			**file;
	int				input_fd;
	int				output_fd;
	struct s_header	*header;
	struct s_code	*code;
}					t_asm;

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_code
{
	enum e_type		type;
	int				op_code;
	short			param_byte;				// octet de codage
	void			*params[4];				// parametres
	short			size;					// nombre d'octets de l'instruction
	int				nb_line;				// Numero de ligne
	char			*line;
	off_t			label_cursor;			// emplacement du label pour lseek 
	struct s_code	*next;
}					t_code;

int					err_code(int code, char *msg);
int					read_file(t_asm **env, char **arg);

#endif