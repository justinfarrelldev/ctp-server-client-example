# What is this?

This is an example client for the Open Call to Power Server.

The API this application calls is laid out [here](https://open-ctp-server.fly.dev/docs).

# Requirements to Build

You will need: 
- clang
- clang-tidy
- make

The project uses the C11 standard.

# Building

To build the application, simply run `make all`. Note that this will also run clang-tidy to ensure that the application is still in a good state.

Once the application is built, you can run it with `make run`.