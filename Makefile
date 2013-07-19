CFLAGS = -I. -Wall -g
LDFLAGS  = 
LIBS     =  

ifeq ($(OSTYPE),linux)
EXE =
else
EXE = .exe
endif

PRJECT_NAME=string_match

all: $(PRJECT_NAME)$(EXE)

CC=gcc

.c.o: 
	@echo [CC]: $<
	@$(CC) $(CFLAGS) -c $< -o $@

%.out:
	@echo [OUT]: $^
	@$(CC) $(CFLAGS) $^ $(LDFLAGS)  -o $@

%.exe:
	@echo [EXE]: $^
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(sources) $(LIBS)

%.a:
	@echo [AR]: $@
	@ar rcs $@ $^

%.d: %.c
	@echo [DEP]: $<
	@$(SHELL) -ec '$(CC) -MM -MQ $*.o $(CFLAGS) $< > $@'


sources = string_util.c brute_force.c rabin_karp.c string_match.c

ifneq ($(MAKECMDGOALS),mrproper)
ifneq ($(MAKECMDGOALS),clean)
-include $(sources:.c=.d)
endif
endif

$(PRJECT_NAME)$(EXE): $(sources:.c=.o)

.PHONY: clean mrproper
clean:
	rm -f *.o *.out, *$(EXE)

mrproper: clean
	rm -f *.d
