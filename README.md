# Customer Support Dispatcher Agent

![Desktop App View](images/admin-view2.png)
For more in-app photos take a look at the images in the root directory.

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
The project runs a simulation of a Customer Support Centre from a Banking Institution.  
The admin starts the platform and configures the day's department and agent configuration - modelling a dynamic work environment.  
The admin distributes the agent terminals opened, and keeps track of the overall department performance metrics on his monitor.  
The clients can now start creating inquiries. They will be set to a pending state and in just a few miliseconds the AI Dispatcher classifies them to the most appropiate department.
There the agent with the smallest workload (least number of inquiries) will recieve it and will be placed on his duty list based on urgency (highest urgency first).  
After completion the agent closes the ticket and moves on with the tasks.  
The admin sees all data at each stage and can see a bar / pie chart of the departments with the most completed inquiries.

## Project Structure
The app follows Layered Architecture standards and is structured in 4 main parts. Besides those there are some util functions and configuration files.

1. **Domain**:  
This folder defines the models of the fictive Bank Institution (the modules are highly reusable for different cases).
  
- Agent - the customer support agent - characterized by its ID and Department.  
- AIModel - the AI model - allows making requests to the Groq API to get the necessary inquiry classification data - Department and UrgencyLevel.  
- Department - the enumeration of departments available in the institution.  
- Inquiry - the client issued inquiry - characterized by its ID, Issuer User, Description, Status, Assigned Agent, Assigned Department, Assigned UrgencyLevel.  
- InquiryStatus - the enumeration of statues of an inquiry - Pending = awaiting AI classification, Processing = awaiting agent action, Completed.  
- UrgencyLevel - the enumeration of urgency levels an inquiry can take (Low, Medium, High, Critical).
- User - the identification data provided by the client in the inquiry issuing form - Username, First and Last Name, E-mail, Phone Number

2. **Repository**:  
This folder defines the Repository of the Instititution, with getters and setters for data.

The inquiries are held by processing status in the following data structures:  
- Pending - Vector
- Processing - Unordered Map of Key Department and Value Unordered MultiMap of Key Agent and Values Inquiries.
- Completed - Vector

**Note**: All getters return constant iterators over the data structures to protect the underlying data, and provide a uniform way of accessing it - **Iterator Design Patten**.

3. **Controller**:  
This folder defines the Controller of the Institution methods. It mediates the interactions between the views and the models.  
The controller defines methods for creating and processing new inquiries, but also getting repository data in the required order.

7. **Gui**:  
This folder defines the Graphical User Interface of the Institution's Platform.

- **Client View** - the form where clients create new inquiries
- **Configuration View** - the admin controller to start up the system by setting the number of agents in each department.
- **Controller View** - the admin panel to see the **Statistics View** = graphical representations (charts) of department performance along the **Inquiries Views** = raw data from the system.
- **Department View** - the agent panel, where inquiries are redirected to the worker from the assigned department with the smallest workload (least number of inquiries).
  
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
