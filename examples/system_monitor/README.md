#system monitor example

This example show how to monitor the system and how to set a fault to stop the system.

see app/src/app_swc1.cpp
This file contains the following:

static int ctr = 0, ctr2 = 0;
ctr++;

if(ctr == 150) {
    except = sys_Restart;
    SetSystemException(except);
    ctr = 0;
    ctr2++;

    if(ctr2 == 10) {
        except = sys_Taskoverrun;
        SetSystemException(except);
    }
}

this app has two counters, one is increased every cycle.
the system is configured to run every 10ms

so every 1.5s the condition will be met, and the system will be set to restart.

once 10 restarts have happened then the system will set a fault "sys_Taskoverrun"  this will stop the system.


##Configuring project

The system is configure to run every 10ms as base time
sys_logger is enabled for both system and debug.
sys_timer is disabled since we are not measuring the runtime.

{
    "base-time" : "10",
    
    "sys-logger" : {
        "debug" : "on",
        "system" : "on"
    },
    "sys-timer" : "off"    
}

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