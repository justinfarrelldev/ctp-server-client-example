CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic
SRC = main.c
OUT = dist/ctp_client_example

deps:
	sudo apt-get update
	sudo apt-get install -y clang clang-tidy make

all:
	mkdir -p dist
	make tidy
	make build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

tidy:
	clang-tidy $(SRC) -- -std=c11 $(CFLAGS)

clean:
	rm -f $(OUT)

run:
	./dist/ctp_client_example
