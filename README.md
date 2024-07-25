# Customer Support Dispatcher Agent

## Overview
The Customer Support Dispatcher Agent simulates the automation of dispatcher tasks within customer support centers using AI. 
Inside the desktop app you will see a Bank Customer Support Platform that leverages LLama3 7B Model (LLM from Meta) to assign the correct department and urgency to each request.
Once classified the ticket can be picked up by the agent in just a few milliseconds, saving client's timme and company's money.

## Table of Contents
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Technologies Used](#technologies-used)
- [License](#license)

## Prerequisites
Before running the app on your system, ensure you have the following:

1. **X11**: An open-source windowing system for bitmap displays. X11 is required to display the graphical user interface of the application within a Docker container. To install X11:
    - **Linux**: Most Linux distributions come with X11 pre-installed. If not, you can install it using your package manager. For example, on Ubuntu:
        ```sh
        sudo apt-get update
        sudo apt-get install xorg
        ```
    - **macOS**: Install XQuartz, which is an open-source version of the X.Org X server that runs on macOS. Download and install it from [XQuartz official website](https://www.xquartz.org/).
    - **Windows**: Install an X11 server like Xming or VcXsrv. Download and install Xming from [Xming official website](https://sourceforge.net/projects/xming/) or VcXsrv from [VcXsrv official website](https://sourceforge.net/projects/vcxsrv/).

2. **Docker**: A platform that uses OS-level virtualization to deliver software in packages called containers. To install Docker:
    - **Linux**: Follow the instructions on the [Docker installation page for Linux](https://docs.docker.com/engine/install/#server).
    - **macOS**: Download and install Docker Desktop from [Docker Desktop for macOS](https://docs.docker.com/desktop/install/mac-install/).
    - **Windows**: Download and install Docker Desktop from [Docker Desktop for Windows](https://docs.docker.com/desktop/install/windows-install/).

3. **Git**: A version control system to clone the repository. To install Git:
    - **Linux**: Install Git using your package manager. For example, on Ubuntu:
        ```sh
        sudo apt-get update
        sudo apt-get install git
        ```
    - **macOS**: Install Git via Homebrew:
        ```sh
        brew install git
        ```
    - **Windows**: Download and install Git from [Git for Windows](https://gitforwindows.org/).

4. **Internet Connection**: Required to download the repository and Docker images.


## Installation
To run the desktop application locally, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/antonio-hus/Customer-Support-Assistant.git
    cd Customer-Support-Assistant
    ```

2. Build and start the Docker containers:
    ```sh
    docker build customer_service_app
    docker run -e DISPLAY=host.docker.internal:0 -v /tmp/.X11-unix:/tmp/.X11-unix customer_service_app
    ```


## License
This project is a personal endeavor and is not intended for public use or distribution. All rights are reserved by the author.
