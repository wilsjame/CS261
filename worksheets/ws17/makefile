# define C compiler
CC = gcc

# define C header files
INCLUDES = 

# define C source files
SRCS = linkedListStack.c

# define C object files
#
# Suffix Replacement within a macro:
#   $(name:string1=string2)
#         for each word in 'name' replace
#         'string1' with 'string2'
# Replace suffix .c with .o in SRCS macro
OBJS = $(SRCS:.c=.o)

# define executable file name
MAIN = out

# define clean up
RM = -rm -rf

#
# The following part is generic; it can be used
# to build any executable just by changing the 
# definitions above and by deleting dependencies
# appended to the file from 'make depend'
#

# Avoid conflicts with file of the same name, clean
.PHONY: depend clean

all:	$(MAIN)
	@echo makefile working...

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

# Suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of prerequisite
# of the rule(a .c file) and $@: the name of the target
# of the rule (a .o file) 
# (see gnu make man section about automatic variables)
#
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depends needs it
