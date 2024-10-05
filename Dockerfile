FROM debian:stable

# Install the required packages.
RUN apt-get update
RUN apt-get -y install frotz inform6-compiler

# Create the user to run the compiler and frotz as.
RUN useradd -ms /bin/bash vts

# From here on run as the VTS user.
USER vts