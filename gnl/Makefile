NAME = gnl.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = get_next_line.h
OPTION = -c -I. -D BUFFER_SIZE=42
SRCS = 	get_next_line.c \
		get_next_line_utils.c \
		get_next_line_utils2.c

OBJS = ${SRCS:.c=.o}

%.o: %.c ${HEADER}
		${CC} ${FLAGS} ${OPTION} $< -o $@

all:	${NAME}

${NAME}:	${OBJS}
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)
			@echo "gnl created"

clean:		
			rm -f $(OBJS)

fclean:		
			rm -f $(OBJS) $(NAME)

re:			fclean all

.PHONY:		
			all clean fclean re
