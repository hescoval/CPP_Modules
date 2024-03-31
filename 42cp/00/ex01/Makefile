NAME = PhoneBook
COMPILER = c++
FLAGS = -Wall -Wextra -Werror --std=c++98
RM = rm -rf
OBJS = *.o
SRCS = srcs/*.cpp

all: $(NAME)

$(NAME): $(OBJS)
		$(COMPILER) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
		$(COMPILER) $(FLAGS) -c $(SRCS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean
		$(MAKE)