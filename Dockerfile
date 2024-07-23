# Use an official Ubuntu base image
FROM ubuntu:latest

# Set environment variables to avoid interactive prompts during build
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    qt6-base-dev \
    qt6-declarative-dev \
    libmysqlclient-dev && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory in the container
WORKDIR /app

# Copy the local source code to the container
COPY . /app

# Build the application
RUN mkdir -p build && cd build && \
    cmake .. && \
    cmake --build .

# Define the command to run your application
CMD ["./build/Customer_Support_Assistant"]
