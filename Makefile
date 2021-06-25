NAME = minishell
NAME_BONUS = minishell_bonus
CC = gcc
INCLUDE = -I include
HEADER = ./include/ft_minishell.h
FLAGS = -Wall -Wextra -Werror
PARSER = parser
COMMAND = command
SIGNALS = signals
CMD = cmd_manager
AUXILIARY_FUNCTIONS = auxiliary_functions
LIBA = libft
GNL = gnl
SRCS =	${AUXILIARY_FUNCTIONS}/additional_features.c \
		${AUXILIARY_FUNCTIONS}/additional_features2.c \
		${AUXILIARY_FUNCTIONS}/additional_features3.c \
		${AUXILIARY_FUNCTIONS}/additional_features4.c \
		${AUXILIARY_FUNCTIONS}/lists_for_execve.c \
		${AUXILIARY_FUNCTIONS}/array_of_strings.c \
		${CMD}/cmd_manager.c \
		${CMD}/reeder_from_term.c \
		${CMD}/reeder_from_term_utils.c \
		${CMD}/reeder_from_term_utils2.c \
		${CMD}/reed_from_term_for_double_less.c \
		${COMMAND}/builtin.c \
		${COMMAND}/command.c \
		${COMMAND}/errors.c \
		${COMMAND}/export.c \
		${COMMAND}/pape.c \
		${COMMAND}/redirect.c \
		${COMMAND}/execve.c \
		${COMMAND}/unset.c \
		${COMMAND}/utils_builin.c \
		${COMMAND}/utils_execve.c \
		${COMMAND}/stat_command.c \
		${COMMAND}/stat_command_utils.c \
		${COMMAND}/stat_command_utils2.c \
		${PARSER}/parser.c \
		${PARSER}/parser_utils.c \
		${PARSER}/parser_utils2.c \
		${PARSER}/parser_utils3.c \
		${PARSER}/parser_utils4.c \
		${PARSER}/parser_utils5.c \
		${PARSER}/parser_utils6.c \
		${PARSER}/parser_utils7.c \
		${PARSER}/parser_utils_add.c \
		${SIGNALS}/signal_manager.c \
		env.c \
		tmp.c \
		ft_clean.c \
		ft_maindup.c \
		path_env.c \
		ft_minishell.c

OBJS =		${SRCS:.c=.o}

%.o: %.c
	$(CC) -o $(FLAGS) ${INCLUDE} -c $<  -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			@make re -C libft	
			@cp $(LIBA)/libft.a ./$(NAME)
			@make re -C gnl	
			@cp $(GNL)/gnl.a ./$(NAME)
			gcc -o $(NAME) $(OBJS) ${LIBA}/libft.a ${GNL}/gnl.a ${INCLUDE} -ltermcap

bonus:		$(OBJS)
			@make re -C libft	
			@cp $(LIBA)/libft.a ./$(NAME)
			@make re -C gnl	
			@cp $(GNL)/gnl.a ./$(NAME)
			gcc -o $(NAME_BONUS) $(OBJS) ${LIBA}/libft.a ${GNL}/gnl.a ${INCLUDE} -ltermcap

test:	
	gcc -g ${INCLUDE} ${AUXILIARY_FUNCTIONS}/additional_features.c ${PARSER}/parser.c ${COMMAND}/command.c ${COMMAND}/stat_command.c ${SIGNALS}/signal_manager.c ft_minishell.c ${COMMAND}/execve.c \
	${CMD}/cmd_manager.c ./gnl/gnl.a ./libft/libft.a ${AUXILIARY_FUNCTIONS}/lists_for_execve.c ${CMD}/reeder_from_term.c -ltermcap ./libft/ft_putchar_fd.c ./libft/ft_isdigit.c \
	${AUXILIARY_FUNCTIONS}/array_of_strings.c  ${COMMAND}/export.c  \
	${AUXILIARY_FUNCTIONS}/additional_features2.c ${AUXILIARY_FUNCTIONS}/additional_features3.c ${AUXILIARY_FUNCTIONS}/additional_features4.c ${COMMAND}/stat_command_utils.c ${COMMAND}/stat_command_utils2.c \
	${COMMAND}/utils_builin.c ${COMMAND}/unset.c ./libft/ft_substr.c \
	${COMMAND}/utils_execve.c ${COMMAND}/redirect.c ${COMMAND}/errors.c ${COMMAND}/pape.c ${COMMAND}/builtin.c ft_clean.c \
	${CMD}/reed_from_term_for_double_less.c ${CMD}/reeder_from_term_utils.c ${CMD}/reeder_from_term_utils2.c ${PARSER}/parser_utils.c ${PARSER}/parser_utils2.c ${PARSER}/parser_utils3.c ${PARSER}/parser_utils4.c \
	${PARSER}/parser_utils_add.c ${PARSER}/parser_utils5.c ${PARSER}/parser_utils6.c ${PARSER}/parser_utils7.c tmp.c env.c path_env.c ft_maindup.c

test_file:
	gcc -g minishell_test.c

clean:
		rm -f $(OBJS)

bonus_clean:
		rm -f $(OBJS)

fclean:	
			rm -f $(OBJS) $(NAME)

fclean_bonus:
			rm -f $(OBJS) $(NAME)

re:			fclean all

.PHONY:
			all bonus bonus_clean fclean_bonus clean fclean re

