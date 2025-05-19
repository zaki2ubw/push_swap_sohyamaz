/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:03:06 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/05/06 19:37:06 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef LOWHEX
#  define LOWHEX "0123456789abcdef"
#  define UPHEX "0123456789ABCDEF"
# endif

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	long			val;
	int				rank;
}	t_node;

typedef struct s_head
{
	t_node	*top_a;
	t_node	*top_b;
	int		target;
	int		flag;
}	t_head;

//ps_check_val.c
int		cv_isnumber(char c);
int		cv_check_number(char *str);
void	check_val(int argc, char **argv);

//ps_init_stracts.c
t_node	*is_add_firstnode(int argc, char **argv);
void	init_stracts(t_head *stacks, int argc, char **argv);

//ps_make_list.c
long	ml_add_val(char *origin);
int		ml_set_rank(int target, long val, int argc, char **argv);
int		ml_add_node(t_head *stacks, int argc, char **argv);
void	make_list(t_head *stacks, int argc, char **argv);

//ps_optimization.c
void	op_double_case(t_head *stacks);
void	op_triple_case(t_head *stacks);
void	op_quadruple_case(t_head *stacks);
void	op_quintuple_case(t_head *stacks);
void	ps_optimized_cmd(int argc, t_head *stacks);

//ps_opt_triple.c
void	op_print_triple(int num);
void	op_optimize_three(t_head *stacks, int num);

//ps_opt_quadruple.c
void	op_print_quadruple(int num);
void	op_optimize_four(t_head *stacks, int num);
int		op_set_quadnum(int num, t_head *stacks);

//ps_opt_quintuple
void	op_print_quintuple(int num);
void	op_optimize_five(t_head *stacks, int num);
int		op_set_quintnum(int num, t_head *stacks);

//push_swap.c
int		oc_set_range(t_head *stacks);
void	ps_operate_stack(t_head *stacks);
int		ps_operate_chank(t_head *stacks, int chank, int range);
void	ps_return_stack(t_head *stacks);
void	push_swap(t_head *stacks);
//Debug_func
//void	ps_print_list(t_head *stacks);

//ps_find_target.c
void	oc_push_target(t_head *stacks, int chank, int range);
void	ps_push_target(t_head *stacks);
int		oc_count_operate(t_head *stacks, t_node *current, int move, int border);
int		oc_compare_operate(t_head *stacks, int target, int operate, int rank);
int		oc_find_target(t_head *stacks, int chank, int listsize, int range);

//ps_operate_stacks.c
//int		oc_check_chank(int rank, int chank);
//int		oc_check_position(t_head *stacks, int move);
//int		oc_check_number(int rank, int chank, int operate, int range);
//int		oc_check_recieve(int rank, t_head *stacks, int operate);
//void	ps_push_target(t_head *stacks);
//int		oc_find_target(t_head *stacks, int chank, int listsize, int range);

//ps_prepare_stacks.c
void	oc_set_target(t_head *stacks, int move);
int		oc_check_rotate(t_head *stacks, int listsize);
int		ps_count_move(t_head *stacks, t_node *top, int direct);
int		ps_decide_direct(t_head *stacks, t_node *top);
void	ps_push_firstnode(t_head *stacks);

//ps_return_stacks.c
void	rs_return_target(t_head *stacks);
void	rs_rotate_target(t_head *stacks, int move);
int		rs_find_target(t_head *stacks);

//ps_cmd_push.c
t_node	*cut_node(t_head *stacks, int cmd);
void	put_node_a(t_head *stacks, t_node *target);
void	put_node_b(t_head *stacks, t_node *target);
int		push_a(t_head *stacks);
int		push_b(t_head *stacks);

//ps_cmd_swap.c
int		swap_a(t_head *stacks);
int		swap_b(t_head *stacks);

//ps_cmd_rotates.c
int		rotate_a(t_head *stacks);
int		rotate_b(t_head *stacks);
int		reverse_rotate_a(t_head *stacks);
int		reverse_rotate_b(t_head *stacks);

//ps_libft.c
int		ut_strlen(char *str);
void	*ut_calloc(size_t nmemb, size_t size);
void	ut_bzero(void *s, size_t n);

//ps_utils.c
int		ut_count_nodes(t_node *top);
t_node	*ut_create_node(int target, char *str, int argc, char **argv);
int		ut_issigned(char c);
long	ut_atoi(char *str);

//ps_exit.c
void	ut_free_all(t_head *stacks);
void	fa_free_list(t_node *list);
void	ut_error_exit(void);

//ps_prints.c
void	ps_select_print(int cmd);
void	ps_print_cmd(int cmd);
void	ps_print_special(int cmd);

//ft_printf.c
int		ft_printf(const char *format, ...);
void	init_variable(int *val1, int *val2, char *val3);
void	set_format(char typec, va_list args, int *len);

//format_number.c
void	put_dec(int *len, long long args);
void	put_hex(int *len, unsigned long long args, char typec);
void	setdec(int *len, long long args);
void	sethex(int *len, unsigned long long args, char typec);

//format_char.c
void	setchar(int *len, char args);
void	setstr(int *len, char *args);

#endif
