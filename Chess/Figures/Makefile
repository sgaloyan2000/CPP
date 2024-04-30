CC = g++
CFLAGS = -Wall -Wextra -std=c++11

SRCS = figures.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = chess_game

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
