# Customer Support Dispatcher Agent

## Overview
The Customer Support Dispatcher Agent is a simulation of how AI could replace dispatcher agents in customer support centres.
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
To run the app on your system make sure to have a version of X11 Installed

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
