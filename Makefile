CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wno-error=unused-parameter -pedantic $(shell pkg-config --cflags gtk+-3.0 libcurl json-c)
SRC = $(shell find . -name '*.c')
OUT = dist/ctp_client_example

deps:
	sudo apt-get update
	sudo apt-get install -y clang clang-tidy make libgtk-3-dev pkg-config libcurl4-openssl-dev libjson-c-dev

all:
	mkdir -p dist
	make tidy
	make build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(shell pkg-config --libs gtk+-3.0 libcurl json-c)

tidy:
	clang-tidy $(SRC) -- -std=c11 $(CFLAGS)

clean:
	rm -f $(OUT)

run:
	./dist/ctp_client_example
