# STUNTMAN - An open source STUN server
Version 1.2.16

April 7, 2020

## About the fork 

This is a fork of [stunserver](https://github.com/jselbie/stunserver) from
John Selbie with the following changes:

* CMake support
* Boost is optional (when building with CMake)
  * The CRC 32 implementation of boost has been replaced with a modified version of [Simple CRC32](http://home.thep.lu.se/~bjorn/crc/) by Björn Samuelsson
  * Smart pointers have been replaced with C++11 smart pointers
* clang-format has been used to format the changed source files. 
  Although I have tried to create a formatting configuration close to the original style
  there are some white space changes.
* The README has been converted into a markdown file and is no longer formatted with the custom pretty printer.
* Some other minor changes on the documentation resource generation and usage.

To build with CMake install OpenSSL (see below) and run:

```
mkdir build
cd build
cmake ..
cmake --build .
```

### Optional Boost

Boost is only required if the CMake option `with_configfile_support` is set to `ON`.
If the option is set to `OFF` (which is the default) the server application
can not be configured with a JSON file (command line options are still possible).

### Why this fork

The changes make it easier to use STUNTMAN as a dependency in other projects (e.g. as an [external project](https://cmake.org/cmake/help/latest/module/ExternalProject.html?highlight=externalproject) 
 with CMake).

## Features:

  * Compliant with the latest RFCs including 5389, 5769, and 5780. Also includes
  backwards compatibility for RFC 3489.

  * Supports both UDP and TCP on both IPv4 and IPv6.

  * Client test app provided.

  * Stun server can operate in "full" mode as well as "basic" mode. Basic mode
  configures the server to listen on one port and respond to STUN binding
  requests. Full mode configures the service to listen on two different IP
  address interfaces (if available) and provide NAT behaviour and filtering
  detection support for clients.

  * Support for running a full mode STUN service on an Amazon EC2 instance. Run
  "stunserver --help" for visit www.stunprotocol.org on how to configure this
  mode.

  * Open source Apache license. See LICENSE file fore more details.

## Known issues:

  * TLS mode has yet to be implemented.

  * Server does not honour the stun padding attribute. If someone really wants
  this support, let me know and I will consider adding it.

  * By default, the stun server operates in an open mode without performing
  authentication. All the code for authentication, challenge-response, message
  hashing, and message integrity attributes are fully coded. HMAC/SHA1/MD5
  hashing code for generating and validating the message integrity attribute
  has been implemented and tested. However, the code for validating a user name
  or looking up a password is outside the scope of this release. Instead,
  hooks are provided for implementers to write their own code to validate a
  user name, fetch a password, and allow/deny a request. Details of writing
  your own authentication provider code are described in the file
  "server/sampleauthprovider.h".

  * Dependency checking is not implemented in the Makefile. So if you need to
  recompile, I recommend "make clean" from the root to precede any subsequent
  "make" call.

  * If you run an instance of stunserver locally, you may observe that
  "stunclient localhost" may not successfully work. This is because the server
  is not listening on the loop-back adapter when running in full mode. The
  workaround is to specify the actual IP address that the server is listening
  on. Type "ifconfig" to discover your IP address (e.g. 10.11.12.13) followed
  by "stunclient 10.11.12.13"

## Testing:

  * Fedora 15 with gcc/g++ 4.6.0
  * Fedora 17 with gcc/g++ 4.72
  * Ubuntu 11 with gcc/g++ 4.5.2
  * Ubuntu 12 with gcc/g++ 4.6.3
  * Ubuntu 12 with clang/clang++ 3.0
  * Amazon AWS with gcc/g++ 4.4
  * MacOS with XCode 7 and command line tools
  * FreeBSD 9.0 with gcc/g++ 4.2.1
  * Solaris 11 with gcc/g++ 4.5.2

Parsing code has been fuzz tested with zzuf. http://caca.zoy.org/wiki/zzuf

## Prerequisites before compiling and running.

  The short summary is that you need a C++ compiler (g++ preferred or
  clang++), GNU make, Boost header files, and the OpenSSL development files in
  order to compile the code. Below are the set of package installer commands
  that you can type from the command line to get the tools and libraries you
  need.

### Debian/Ubuntu/Mint
      sudo apt-get install g++
      sudo apt-get install make
      sudo apt-get install libboost-dev # For Boost
      sudo apt-get install libssl-dev # For OpenSSL

### RedHat/Fedora and EC2 Amazon Linux AMI
      sudo yum groupinstall "Development Tools" # For g++, make, et. al.
      sudo yum install boost-devel # For Boost
      sudo yum install openssl-devel # For OpenSSL

### Solaris and Mac
      OpenSSL is already installed on Solaris and is not needed on Mac.

      Install Boost locally as per instructions below, then uncomment and edit
      the top line of the common.inc file.

### Manual Boost install
    The compiled Boost runtime is not necessary. Just obtaining and unpacking
    the Boost source code distribution from www.boost.org will suffice. If you
    do not have the administrative privileges to install the Boost distribution
    into a standard system include path, you may uncomment and edit the top
    line of the common.inc file for the BOOST_INCLUDE variable. The common.inc
    file is in the same folder as this README file.

### Manual OpenSSL install
    You can obtain the OpenSSL development files and runtime from
    www.openssl.org. On most systems with development tools already installed,
    OpenSSL include files are already installed in the standard include path.
    If this is not the case, you can uncomment and edit the common.inc file to
    have the OPENSSL_INCLUDE variable defined.

### Other prerequisites
     pthreads and perl. I've never come across a system where this wasn't
     already pre-installed.

## Compiling and running

  Got Boost and OpenSSL taken care of as described above? Good. Just type
  "make" (or "gmake" on some systems). There will be three resulting binaries
  in the root of the source code package produced.

  stuntestcode - This is the unit test code. I highly recommend you run this
  program first. When run, you'll see a series of lines being printed in
  regards to different code paths being tested. If you see any line that ends
  in "FAIL", we likely have a bug. Please contact me immediately if you see
  this.

  stunserver - this is the server binary. Run "./stunserver --help" for
  details on running this program. Running this program without any command
  line arguments defaults to listening on port 3478 on all adapters.

  stunclient - this is the client test binary. Run "./stunclient --help" for
  details on running this program. Example: "./stunclient stun.selbie.com"

## Firewall

  Don't forget to configure your firewall to allow traffic for the local ports
  the stunserver will be listening on!

## Feature roadmap (the features I want to implement in a subsequent release)

  * Clean-up Makefile and add "configure" and autotools support

  * Finish Windows port and able to run as a Windows service

  * Scale across more than one CPU (for multi-core and multi-proc machines). The
  threading code has already been written, just needs some finish work.

  * TLS support

## Docker

1. `docker image build -t=stun-server-image .`
2. `docker container run -d -p 3478:3478/tcp -p 3478:3478/udp
--name=stun-container stun-server-image`

## Contact the author

  John Selbie
  john@selbie.com

> Please not that this is not the original version created by John Selbie.
