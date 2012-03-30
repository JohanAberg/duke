Duke - Install HOWTO
====================

Why Boost.Build ?
-----------------

Duke relies heavily on the Boost library, so instead of using one of
the many multiplatform build system available like Scons, CMake, Autotools
we're simply using Boost.Build, the build system embedded within Boost.

Boost.Build is powerful yet very expressive and terse. It's a weapon of
choice when building large pieces of code with a lot of dependencies.

An excellent introduction to Boost.Build can be found [here](http://www.highscore.de/cpp/boostbuild/)

And the official documentation is available [online](http://www.boost.org/boost-build2/doc/html/) 
or in your boost copy at $(BOOST_ROOT)/tools/build/index.html 


Setting up the build process
----------------------------

### Building the building tool (the build-ception...)  

* First grab Boost from the website ( http://www.boost.org/ )
* Uncompress the archive somewhere.
* Open a terminal and go to the boost root folder, then type 
    
    - Linux / MacOsX
    
            ./bootstrap.sh
    
    - Windows
    
            bootstrap.bat

    This will generate a 'b2' executable.



### Setting up environment variables  

In order to use Boost.Build you have to set the BOOST_ROOT environment variable.

- Linux / MacOSX

        export BOOST_ROOT=/your/path/to/boost/root


- Windows

        set BOOST_ROOT=C:\your\path\to\boost\root
    
*Note : You can add it to your ~/.bashrc, ~/.profile
or to your Windows environment to make it persistent.*



### Getting all external libraries  

Have a look at the ***config/README*** file.
     


Building
--------

* Choose the appropriate script depending on your platform  

    - Linux

            ./build-linux-gcc.sh

    - MacOSX

            ./build-osx-darwin.sh

    - Windows

            build-windows-mingw.bat


* Run it with one or more of the following command line arguments  

    --user-config=XXX  
        __Specifies the configuration file__  
        
    --help  
        __Display help message__  
        
    --clean  
        __Remove targets instead of building__  
        
    dist  
        __Full build & installation__  
        
    tests  
        __Build & run unit test suite__  
        
    debug -or- release  
        __Select the build variant ( debug is default )__  