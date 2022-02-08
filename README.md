#strawberry-framework

**Strawberry Framework** is a tool that helps you deploy your appplications in ARM processors running linux, especially if you want to run your application in real time in a raspberry pi for example. This tool is the perfect solution to help you speed up your deployment.

##Adding code to your project

add code to the app/src/app_swc1.cpp
This file contains the following:

app_swc1_init:  Init function, this is called when the system is initialized, add your initialization code here.
rte_input_swc1: input reading, this funciton can be used to read signal from your lower layers(services, drivers)
rte_output_swc1: output writing, this funciton can be used to write output to yoru lower layers(services, drivers)
app_swc1: this is the main funciton for your app
app_swc1_deinit: this function is called when the system is deinitialized


add code to device/ folder
In this folder you can add your drivers and services for the application you are developing


##Configuring project

##to generate project:

**Execute the command**
sh generate.sh

This will generate the project using the configuration in the tasks.json file

##to build project:

mkdir build
cd build
cmake ..
make
./strawberry


##For release code:
mkdir Release
cd Release
cmake -DCMAKE_BUILD_TYPE=Release ..
make

##for debug code:
mkdir Debug
cd Debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make