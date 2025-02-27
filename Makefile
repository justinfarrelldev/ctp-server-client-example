CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wno-error=unused-parameter -pedantic $(shell pkg-config --cflags gtk+-3.0 libcurl json-c)
SRC = $(shell find . -name '*.c')

# Output names for different platforms
LINUX_OUT = dist/ctp_client_example
WIN_OUT = dist/ctp_client_example.exe
MAC_OUT = dist/ctp_client_example.app

deps:
	sudo apt-get update
	sudo apt-get install -y clang clang-tidy make libgtk-3-dev pkg-config libcurl4-openssl-dev libjson-c-dev mingw-w64

linux:
	mkdir -p dist
	make tidy
	$(CC) $(CFLAGS) $(SRC) -o $(LINUX_OUT) $(shell pkg-config --libs gtk+-3.0 libcurl json-c)

# Untested, let me know if you have issues
windows:
	mkdir -p dist
	make tidy
	x86_64-w64-mingw32-gcc $(SRC) -o $(WIN_OUT)

# Untested, let me know if you have issues
macos:
	mkdir -p dist
	make tidy
	$(CC) $(CFLAGS) -target x86_64-apple-darwin $(SRC) -o $(MAC_OUT) 

tidy:
	clang-tidy $(SRC) -- -std=c11 $(CFLAGS)

clean:
	rm -f $(LINUX_OUT) $(WIN_OUT) $(MAC_OUT)

run: 
	./$(LINUX_OUT)
