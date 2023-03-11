
NAME		=	No,_you_need_form_28B,_not_28C...

RM			=	rm -rf

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra
CFLAGS		+=	-std=c++98
CFLAGS		+=	-g3 -MMD

SRCS		=	Bureaucrat.cpp \
				Form.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				main.cpp

OBJS_DIR	=	objs

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o:%.cpp
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean
				make all

.PHONY:			all clean fclean re