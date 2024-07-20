NAME = Zombie
COMPILER = c++ -g
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCDIR = cpp
SRCS = $(wildcard *.cpp)
OBJS = $(notdir $(SRCS:.cpp=.o))

all: $(NAME) clean

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