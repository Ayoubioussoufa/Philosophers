NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = prog_init.c philo_bonus.c get_time_bonus.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)  -lpthread -lrt
	rm -f ${OBJS}
clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all