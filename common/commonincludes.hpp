/*
   Copyright 2011 John Selbie

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef STUNSERVER_COMMON_COMMONINCLUDES_H
#define STUNSERVER_COMMON_COMMONINCLUDES_H

// Fix for Lion (http://www.opensource.apple.com/source/xnu/xnu-1699.24.8/bsd/netinet6/in6.h)
#define __APPLE_USE_RFC_3542

#if __linux || __linux__ || __gnu_linux__ || linux
#define IS_LINUX
#endif

// standard system includes
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>
#include <memory.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <stdarg.h>
#include <math.h>
#include <sys/termios.h>

#include <map>
#include <vector>
#include <list>
#include <string>
#include <cassert>

#ifdef IS_LINUX
#define HAS_EPOLL
#include <sys/epoll.h>
#endif

#include <poll.h>

#include <pthread.h>

#ifdef DEBUG_MODE
#define DEBUG 1
#elif not defined(NDEBUG)
#define NDEBUG 1
#endif

#if !defined(DEBUG) && !defined(NDEBUG)
You_Didnt_Define_DEBUG_Or_NDEBUG g_compilererror[-1];
#endif

#if DEBUG
#define ASSERT(expr) assert(expr)
#define VERIFY(expr) ASSERT(expr)
#define ASSERTMSG(expr, msg) assert(expr&& msg)
#else
#define ASSERT(expr)
#define VERIFY(expr)
#define ASSERTMSG(expr, msg)
#endif

#define ARRAYSIZE(arr) (sizeof(arr) / sizeof(*arr))

#define COMPILE_TIME_ASSERT(x) static_assert(x, #x)

#ifndef UNREFERENCED_VARIABLE
#define UNREFERENCED_VARIABLE(unrefparam) ((void)unrefparam)
#endif

// --------------------------------------------

#include "hresult.h"
#include "chkmacros.h"

// ---------------------------------------------
// Unless there's good reason, put additional header files after hresult.h and
// chkmacros.h
#include "objectfactory.h"

#include "logger.h"

#endif
