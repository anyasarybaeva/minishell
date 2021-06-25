#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include <stdio.h>
# include <curses.h>
# include <termios.h> 
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <term.h>
# include <string.h>
# include <errno.h>
# define MAX_LINE       15
# define NEW_COMMAND    0
# define DIRECT_LINE    1
# define MORE           2
# define DOUBLE_MORE    3 
# define LESS           4
# define SEMICOLON      5
# define DOUBLE_LESS    6
# define WRONG_COMMAND  -1
# define WRONG_FILE     -2    
# define PERMISSION_DENIED -3
# define SYN_ERROR_TOK_NEW "minishell: syntax error \
near unexpected token `newline'\n"

pid_t				g_global_pid;
typedef struct s_env
{
	char			**env;
	char			**keys;
	char			**values;
	char			**env_lvl;
	int				exit_num;
	int				fd[2];
}					t_env;

typedef struct s_term_sistem
{
	int							stat_1;
	int							key;
	int							len;
	char						*str;
	char						*term_name;
	int							history_slider;
	char						*history_line;
	struct termios				termios_p_in;
	struct termios				termios_und;
}								t_term_sistem;

typedef struct s_command_and_flag
{
	char						*command_and_flags;
	char						*command;
	int							num_proc;
	int							pape;
	char						*flags;
	char						**array_flags;
	int							f_error;
	int							status_flag;
	struct s_command_and_flag	*next;
}								t_command_and_flag;

typedef struct s_minishell
{
	char						*file_history;
	int							onecovkey;
	int							doublecovkey;
	int							flag;
	t_command_and_flag			*head;
	t_term_sistem				*term;
	struct winsize				*win;
	char						*env_varianles;
	char						*name_varianled;
	char						*tmp;
	char						**path;
	t_env						*env;
	int							lvl;
	int							ret;
	int							pipe;
}								t_minishell;

typedef struct s_list_pid
{
	pid_t						*pid;
	int							size;
	struct s_list_pid			*next;
}								t_list_pid;
int								parser_commands(char *command, \
		t_minishell *all_command);
void							ft_putchar_fd(char c, int fd);
void							ft_putstr_fd(char *s, int fd);;
int								functions_launch(t_command_and_flag **head, \
	   	t_env *struct_env, int *lvl, t_minishell *all);
int								*stat_command(t_minishell *all_command);
char							**ft_split(char const *s, char c);
char							**find_path(void);
void							ft_lstadd_back(t_command_and_flag **lst, \
		t_command_and_flag *new);
t_command_and_flag				*ft_lstnew(char *command, int pape);
size_t							ft_strlen(const char *s);
char							*ft_strjoin(char const *s1, char const *s2);
char							*create_command(char *command, int i, int j, \
		int key);
int								get_next_line(int fd, char **line);
char							*create_cloth_cov(t_minishell *all_command, \
		char *command_and_flags);
char							*replacement(char *command, int	*i, \
		int j, t_minishell *all_command);
void							signal_manager(int sig);
char							*create_cislo_in_string(int lvl);
void							ft_lstadd_front(t_command_and_flag **lst, \
	   	t_command_and_flag *new);
int								find_slash_dot(char *line);
char							*ft_strdup(const char *s1);
char							*ft_itoa(int n);
int								ft_atoi(const char *str);
void							ft_pwd(char **env, int fd);
void							ft_env(t_command_and_flag	*all, \
		char	**env, int	fd);
int								ft_cd(t_command_and_flag	*all, char	**env);
int								ft_export(t_command_and_flag	*all, \
		int	fd, t_env	*struct_env);
int								ft_unset(t_command_and_flag	*all, \
		t_env	*struct_env);
void							ft_echo(t_command_and_flag	*all, int	fd);
int								ft_strncmp(const char	*s1, \
		const char	*s2, size_t	n);
char							*cmd_manager(t_minishell	*all_command);
int								return_settings_term(t_minishell	\
		*all_command);
int								ft_isdigit(int	c);
char							*ft_strnstr(const char	*haystack, \
		const char	*needle, size_t	len);
char							*term_from_double_less(t_minishell \
		*all_command); //conflict
char							*my_getenv(char	*name_env, t_minishell	\
		*all_command);
char							*replacement_2(char	*command, int	*i, \
		int	j, t_minishell	*all_command);
int								create_env_lvl(t_env	*env, int	lvl);
int								check_stat_file(t_command_and_flag	*command);
int								check_stat_command(t_minishell	*all_command, \
		t_command_and_flag	*command);
int								check_stat_file_with_path(t_command_and_flag	\
		*command);
int								check_stat_command_with_path(t_command_and_flag	\
		*command);
int								create_file(char	*path_and_command);
int								press_up(t_minishell	*all_command, \
		char	**command, int	*i, char	**tmp);
int								press_down(t_minishell *all_command, \
		char **command, int *i, char **tmp);
char							*reader_history_line(t_minishell	\
		*all_command, int	history_slider);
int								press_backspase(int	*i, char	**command);
int								press_control_c(char	**command);
int								create_term_win(t_minishell	*all_command);
int								ft_strlen_history(t_minishell	*all_command);
char							*reader_history_line(t_minishell	*all_command, \
		int	history_slider);
int								save_old_term(t_minishell	*all_command);
int								create_new_term(t_minishell	*all_command);
int								definition_history_line(t_minishell	*all_command, \
		int	*i);
int								ft_clear_command_from_kov(t_minishell	*all_command, \
		t_command_and_flag	*command);
int								ft_clear_flags_from_kov(t_minishell	\
		*all_command);
char							*create_command_with_env_variables(char	*command, \
		t_minishell	*all_command);
int								split_flags(t_command_and_flag	*one_command, \
		t_minishell	*all_command);
int								split_flags_utils5(t_command_and_flag	\
		*one_command, int	j);
int								parser_flags(t_minishell	*all_command, \
		t_command_and_flag	*one_command);
int								parser_flags_utils5(t_command_and_flag	\
		*one_command, int	*i, int	*j, int	*k);
int								parser_flags_utils6(t_command_and_flag	\
		*one_command, t_minishell	*all_command, int	k);
int								create_null_array_flags(t_command_and_flag	\
		*command);
int								parser_command(t_minishell	*all_command);
int								parser_commands_less(char	*command, int	*i, \
		int	*j, t_minishell	*all_command);
int								parser_commands_direct_line(char	*command, int	*i, \
		int	*j, t_minishell	*all_command);
int								parser_commands_more(char	*command, int	*i, \
		int	*j, t_minishell	*all_command);
int								create_list_command(char	*command, \
		t_minishell	*all_command, int	pipe);
int								ft_strcmp(const char	*s1, const char	*s2);
int								create_char_command(char	**command);
int								handler_the_signals(t_minishell	*all_command, \
		char	**command, int	*i);
int								handler_press(t_minishell	*all_command, \
		char	**command, int	*i, char	**tmp);
t_command_and_flag				*ft_create_elem(t_command_and_flag	*data);
void							ft_list_push_front(t_command_and_flag	**begin_list, \
		t_command_and_flag	*data);
void							ft_list_clear(t_command_and_flag	*command);
char							*reeder_from_term(t_minishell	*all_command);
int								ft_putchar(int	c);
void							free_array_of_strings(char	**array);
char							**new_array_add(char	**array, char	*str);
char							**new_array_rm(char	**array, int	index);
char							**ft_strdup_array_of_strings(char	**env);
int								ft_check_name(char	*name);
void							ft_putnbr_fd(int	n, int	fd);
int								ft_isalpha(int	c);
int								ft_isalnum(int	c);
int								main_dup(int argc, char	**argv, char	**env);
void							ft_list_push_second(t_command_and_flag	**begin_list, \
		t_command_and_flag	*data);
void							ft_double_less_print(t_command_and_flag	*all, \
		int	fd);
int								ft_export_pipe(t_command_and_flag	*all, \
		int	fd, t_env	*struct_env);
void							t_value_name(char	*str, int	*end_of_key, \
		int	*value);
void							redirect(t_command_and_flag	*all, int	*fd1, \
		int	*fd2);
t_command_and_flag				*redirect2(t_command_and_flag	*all);
t_command_and_flag				*ft_double_less(char	*split, \
		t_minishell *all_command);
void							free_tmp(t_command_and_flag	*tmp);
int								ft_exit(t_command_and_flag	*tmp, \
		t_env *struct_env);
void							ft_minishell_name(int	*lvl, \
		t_env	*struct_env);
void							export_errors(t_command_and_flag	*all, \
		t_env *env);
void							print_errors(pid_t	*pid, t_command_and_flag	*reverse_head, \
		int	size, t_env	*env);
int								**make_pipe(int	size);
void							number_of_pipes(int	*size, t_command_and_flag	**head1, \
		t_command_and_flag	**new_head, t_minishell *all);
void							check_build_in(t_command_and_flag	*all, \
		int	*pipe_1, int	fd1, t_env	*env);
void							check_build_in2(t_command_and_flag	*all, \
		int	*pipe_1, int	fd1, t_env	*env);
void							redirect_pipe(int	*pipe, int	where);
void							redirect_fd(int	fd, int	where);
void							close_pipe(int	*pipe);
void							free_find_fubction(int	**pipe, int	*pid);
void							print_command(t_minishell	*command_list);
t_env							*allocate_env(char	**env, int	lvl);
void							rebut(t_minishell	*all_command);
void							clear_malloc(t_minishell	*all_command, \
		t_env	*env);
t_env							*env_keys_values(t_env	*env1, \
		int	lvl, int	i);
t_env							*allocate_env(char	**env, int	lvl);
void							ft_value_name(char *str, \
		int *end_of_key, int *value);
int								find_path_from_new_env(t_minishell	\
*all_command);
int								main_dup(int argc, char **argv, char **env);
void							allocate(t_minishell *all_command);
int								changes_path_history(t_minishell *all_command, \
		int lvl);
int								crete_or_cheak_file_history(t_minishell *all_command, \
		int lvl);
void							create_signal_controller(void);
int								check_exit_num(char	*str);
int								exit_error(t_command_and_flag	*reverse_head, \
		t_env	*env);

#endif
