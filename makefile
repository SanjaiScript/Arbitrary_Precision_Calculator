TARGET := apc.exe
SRCS   := $(wildcard *.c)
OBJDIR := obj

OBJS   := $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(TARGET): $(OBJS)
	gcc -o $@ $^

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	gcc -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)