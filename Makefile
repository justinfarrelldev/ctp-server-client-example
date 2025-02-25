CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic
SRC = main.c
OUT = dist/ctp_client_example

all:
	mkdir -p dist
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

tidy:
	clang-tidy $(SRC) -- -std=c11 $(CFLAGS)

clean:
	rm -f $(OUT)

run:
	./dist/ctp_client_example
