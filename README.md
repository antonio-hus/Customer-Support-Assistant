# Customer Support Dispatcher Agent

## Overview
The Customer Support Dispatcher Agent simulates the automation of dispatcher tasks within customer support centers using AI. 
Inside the desktop app you will see a Bank Customer Support Platform that leverages LLama3 8B Model (LLM from Meta) to assign the correct department and urgency to each request.
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

2. Set your `GROQ_API_KEY` environment variable:
    - Open a terminal or command prompt.
    - Execute the following command, replacing `YOUR_API_KEY_HERE` with your actual GROQ API key:
      ```sh
      export GROQ_API_KEY="YOUR_API_KEY_HERE"
      ```
    - On Windows, use `set` instead of `export`:
      ```sh
      set GROQ_API_KEY="YOUR_API_KEY_HERE"
      ```

3. Build and start the Docker containers:
    ```sh
    docker build -t customer_service_app .
    docker run -e DISPLAY=host.docker.internal:0 -e GROQ_API_KEY -v /tmp/.X11-unix:/tmp/.X11-unix customer_service_app
    ```

## Usage

## Project Structure
The app follows Layered Architecture standards and is structured in 4 main parts. Besides those there are some util functions and configuration files.

1. **Domain**:  
This folder includes the models of the fictive Bank Institution (the modules are highly reusable for different cases).  
Agent - the customer support agent - characterized by its ID and Department.  
AIModel - the AI model - allows making requests to the Groq API to get the necessary inquiry classification data - Department and UrgencyLevel.  
Department - the enumeration of departments available in the institution.  
Inquiry - the client issued inquiry - characterized by its ID, Issuer User, Description, Status, Assigned Agent, Assigned Department, Assigned UrgencyLevel.  
InquiryStatus - the enumeration of statues of an inquiry - Pending = awaiting AI classification, Processing = awaiting agent action, Completed.  
UrgencyLevel - the enumeration of urgency levels an inquiry can take (Low, Medium, High, Critical).
User - the identification data provided by the client in the inquiry issuing form - Username, First and Last Name, E-mail, Phone Number

3. **Repository**:
4. **Controller**:
5. **Gui**:
  
**Note:**  
Util functions include derived Table Models to allow updating data following the **MVC (Model-View-Controller) Design Pattern**.  
Moreover there is a headerfile that defines the base classes (Observer-Subject) of the **Observer Design Pattern**.  
They also include a time class for dealing with date timestamps.

## Technologies used
- **Qt Framework** - used to develop the Desktop Application in both backend and frontend.
- **C++** - used in pair with Qt Framework.
- **GROQ API** - used to get LLama3 8B Model responses to classify inquiries.
- **Docker** - containerization of the application.

## License
This project is a personal endeavor and is not intended for public use or distribution. All rights are reserved by the author.
