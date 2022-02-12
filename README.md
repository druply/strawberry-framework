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

You are welcome to add more app source files, just make sure the source files are inside the app/src folder.
and specify your prototype functions inside the app/inc/app_swc.hpp file.


add code to device/ folder
In this folder you can add your drivers and services for the application you are developing


##Configuring project

**taskinit** specifies the function that initialized your system, specify the name of your funciton the "call" and the header where it is located in "header" ad shown in the example.

"taskinit": {
    "call" : "InitEcu",
    "header" : "Ecu.hpp"
        
},
    
**rt-tasks** specifies the real time tasks, specify the number of the task, the name and the rate
The following example defines two tasks task0 and task1 that will run in two different threads.
**task0** contains two functions that will be called, "usonicsDrv" will be called every 1x the base time, "encodersDrv" will be called every 2x the base time
**task1** contains two functions that will be called, "lidarDrv" will be called every 2x the base time, "cameraDrv" will be called every 5x the base time

"rt-tasks": [
    {
        "task0" : "usonicsDrv",
        "rate" :  "1"            
    },
    {
        "task0" : "encodersDrv",
        "rate" :  "2"            
    },
    {
        "task1" : "lidarDrv",
        "rate" :  "2"            
    },
    {
        "task1" : "cameraDrv",
        "rate" :  "5"            
    }
]
    
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