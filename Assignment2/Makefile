CC = gcc
CFLAGS = -Wall -I./include -g
SRCS = src/main.c src/album.c src/logs.c src/playlist.c src/song.c
OBJS = $(SRCS:.c=.o)
TARGET = musicapp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
