NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g
SRCS = philo.c mutex_init.c creation_philos.c eat_think_sleep.c forks.c  get_time.c prog_init.c checks.c print_msg.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -lpthread

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all