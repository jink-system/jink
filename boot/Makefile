include .config

AS=${JINK_CONFIG_COMPILER_AS}
ASFLAGS=
SRCDIR=./boot/
OBJDIR=./boot/
ASMSOURCES=$(wildcard $(SRCDIR)/*.s)
OBJECTS=$(patsubst $(SRCDIR)/%.s,$(OBJDIR)/%.o,$(ASMSOURCES))

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@$(AS) $(ASFLAGS) $< -o $@
	@echo "AS	$<	->	$@"

all: $(OBJECTS)

clean:
	@rm -f $(OBJDIR)/*.o
	@echo "boot/Makefile: directory clean!"
