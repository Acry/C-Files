define colorecho
      @tput setaf 2
      @echo $1
      @tput sgr0
endef

CFLAGS   = -Wall -Wextra -no-pie -mtune=native

LDFLAGS  = -lm

TARGETS =  read_file1 read_file2 in_functions

.PHONY: all
all: $(TARGETS)

# read file to array and print to standard out
read_file1: read_file1.c 
	@cc $(CFLAGS) -o $@ $< $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

# read file from argument and print to standard out
read_file2: read_file2.c 
	@cc $(CFLAGS) -o $@ $< $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

# use arrays via functions
in_functions: in_functions.c 
	@cc $(CFLAGS) -o $@ $< $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

.PHONY: clean
clean:
	@rm $(TARGETS) 2>/dev/null || true
	$(call colorecho,"It is clean now.")

# $<	first dependency
# $@	target name
# $+	list of all dependencies
# $^	list of all unique dependencies

# Compile on save
# while inotifywait -e close_write ./anim.c; do date +%X; make > /dev/null; done
