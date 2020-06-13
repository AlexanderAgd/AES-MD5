
CC := gcc
CFLAGS := -g -Wall
LDFLAGS = 
TARGET := test

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.c)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.c,%.o,$(SRCS))

all: $(TARGET) 
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -vf $(TARGET) *.o
	
.PHONY: all clean

