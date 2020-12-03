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

#define ARRAYSIZE(arr) (sizeof(arr) / sizeof(*arr))

#define COMPILE_TIME_ASSERT(x) static_assert(x, #x)

#ifndef UNREFERENCED_VARIABLE
#define UNREFERENCED_VARIABLE(unrefparam) ((void)unrefparam)
#endif

#endif
