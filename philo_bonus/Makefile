NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = get_time_bonus.c  sem_init_bonus.c  creation_philos_bonus.c eating_bonus.c prog_init_bonus.c forks_bonus.c ft_strlen_bonus.c free_all_bonus.c print_msg_bonus.c sleep_think_bonus.c  philo_bonus.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -lpthread
	rm -f ${OBJS}
clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
