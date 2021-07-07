.PHONY: all clean fclean re

NAME=test

FLAGS=-Wall -Wextra -Werror -std=c++98

SRCS_MAIN=./map_test.cpp

OBJS_MAIN=$(SRCS_MAIN:%.cpp=%.o)

INCLUDES=./map_iterator.hpp ./map.hpp ../reverse_iterator.hpp

all: $(NAME)

$(NAME): $(OBJS_MAIN) $(INCLUDES)
	clang++ -o $(NAME) $(OBJS_MAIN)

%.o: %.c $(INCLUDES)
	clang++ -c $(FLAGS) -I$(INCLUDES) -o $@ $<

clean:
	/bin/rm -f $(OBJS_MAIN)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all