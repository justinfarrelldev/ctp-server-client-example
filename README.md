# What is this?

This is an example client for the Open Call to Power Server.

The API this application calls is laid out [here](https://open-ctp-server.fly.dev/docs).

Right now, there is only a "Create Account" button - there are more endpoints created, I have just chosen not to implement them to get this out as fast as I can.

# Requirements to Build

You will need: 
- clang
- clang-tidy
- make
- pkg-config
- GTK 3
- libcurl
- json-c

The project uses the C11 standard.

# Building

Note that this has only been tested on Debian (Linux), so you may run into issues with other toolchains.

To grab all deps, you can run `make deps`. This will invoke `sudo apt install`, so be wary of this if you already have the dependencies on your system.

To build the application, simply run `make (linux | macos | windows)` depending on your OS. Note that this will also run clang-tidy to ensure that the application is still in a good state.

Once the application is built, you can run it with `make run`.