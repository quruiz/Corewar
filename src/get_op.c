/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_op.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/31 20:59:46 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/19 19:11:19 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/asm.h"

extern t_op	g_op_tab[17];

void		save_size_param(char type, int *size, unsigned char *byte, int i)
{
	if (type == T_REG)
	{
		*byte = *byte | (1 << (6 - (i * 2)));
		*size += 1;
	}
	if (type == T_DIR || type == T_LAB)
	{
		*byte = *byte | (2 << (6 - (i * 2)));
		*size += (type == T_DIR ? 2 : 4);
	}
	if (type == T_IND)
	{
		*byte = *byte | ((1 | 2) << (6 - (i * 2)));
		*size += 2;
	}
}

t_code		*create_struct_op(t_asm *env, t_code *tmp)
{
	t_code	*n;

	if (!(n = ft_memalloc(sizeof(t_code))))
		return (err_code(MEM_ERROR, NULL, env) ? 0 : NULL);
	n->type = 2;
	n->line_nb = env->line_nb;
	n->token = ft_strdup(g_op_tab[tmp->op].name);
	n->op = tmp->op;
	n->byte = tmp->byte;
	n->raw_params = tmp->raw_params;
	n->size = tmp->size;
	n->next = NULL;
	return (n);
}

t_code		*detect_param(t_asm *env, char **param, int op)
{
	int		i;
	t_code	tmp;

	i = 0;
	tmp.size = (g_op_tab[op].byte_param) + 1;
	tmp.op = op;
	while (i < g_op_tab[op].nb_param)
	{
		if (param[i][0] == 'r' && (g_op_tab[op].param[i] & T_REG))
			save_size_param(T_REG, &tmp.size, &tmp.byte, i);
		else if (param[i][0] == DIRECT_CHAR && (g_op_tab[op].param[i] & T_DIR))
			save_size_param((g_op_tab[op].dir_size ? 2 : 8), &tmp.size, &tmp.byte, i);
		else if ((ft_isdigit(param[i][0]) || param[i][0] == LABEL_CHAR) &&
			(g_op_tab[op].param[i] & T_IND))
			save_size_param(T_IND, &tmp.size, &tmp.byte, i);
		else
		{
			ft_freesplit(param);
			return (err_code(INVALID_PARAM, g_op_tab[op].name, env) ? 0 : NULL);
		}
		i++;
	}
	tmp.raw_params = param;
	return (create_struct_op(env, &tmp));
}

int			parse_op(t_asm *env, char *line, int cursor, int op_code)
{
	char	**param;
	t_code	*code;
	int		i;
	int		size;

	i = 0;
	while (!isprint(line[cursor]))
		cursor++;
	param = ft_strsplit_trim(line + cursor, SEPARATOR_CHAR);
	while (i < g_op_tab[op_code].nb_param)
	{
		if (param[i] && !ft_str_is_empty(param[i]))
			i++;
		else
		{
			ft_freesplit(param);
			return (err_code(INVALID_PARAM, g_op_tab[op_code].name, env));
		}
	}
	if (!(code = detect_param(env, param, op_code)))
		return (0);
	add_to_list(env, code);
	return (1);
}

int			get_op(t_asm *env, char *line)
{
	int cursor;
	int op;

	cursor = 0;
	op = 0;
	while (isalpha(line[cursor]))
		cursor++;
	while (op < 16)
	{
		if (ft_strnequ(line, g_op_tab[op].name, cursor))
			break ;
		op++;
	}
	if (op == 16)
		return (err_code(SYNTAX_ERROR, NULL, env));
	if (!parse_op(env, line, cursor, op))
		return (ft_free_line(&line, 0));
	return (ft_free_line(&line, 1));
}
