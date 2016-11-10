PROJECT		=	test-libdict
BINDIR		?=	.
BUILDDIR	?=	build
NAME		=	$(BINDIR)/test-libdict

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g

BLACK		=	"\033[0;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[0;34m"
MAGENTA		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[0;37m"
END			=	"\033[0m"

FIND		=	find . -maxdepth 1 -printf "%f\n"

SRCEX		=
SRC			=	$(filter-out $(SRCEX), $(filter %.c, $(shell $(FIND) -type f)))
OBJECTS		=	$(addprefix $(BUILDDIR)/, $(SRC:%.c=%.o))

LIBDIRS		=	$(subst lib, , $(filter lib%, $(shell $(FIND))))
LIBS		=	$(addprefix $(BUILDDIR)/lib, $(addsuffix .a, $(LIBDIRS)))
LIBLINK		=	-ldict -lvect -lft

all: $(NAME)

$(BUILDDIR)/%.a: %
	@printf $(BLUE)$(PROJECT)$(END)'\t'
	BINDIR=$(CURDIR)/$(BUILDDIR) BUILDDIR=$(CURDIR)/$(BUILDDIR) \
		make --no-print-directory -C $<

$(BUILDDIR)/%.o: %.c
	@[ -d $(BUILDDIR) ] || mkdir $(BUILDDIR)
	@printf $(BLUE)$(PROJECT)$(END)'\t'
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBS)
	@printf $(BLUE)$(PROJECT)$(END)'\t'
	$(CC) $(CFLAGS) -L$(BUILDDIR) $(LIBLINK) $(OBJECTS) $(LIBLINK) -o $(NAME)
	@printf "OK\t"$(NAME)'\n'

.PHONY: clean sclean fclean re r

clean:
	@printf $(YELLOW)$(PROJECT)$(END)'\t'
	rm -rf $(BUILDDIR)

sclean:
	@printf $(YELLOW)$(PROJECT)$(END)'\t'
	rm -rf $(OBJECTS)

fclean: clean
	@printf $(YELLOW)$(PROJECT)$(END)'\t'
	rm -rf $(NAME)

r: sclean all

re: fclean all
