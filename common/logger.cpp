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

#include "logger.h"

#ifdef ANDROID
#include <android/log.h>
#else
#include <cstdio>
#endif
#include <cstdarg>

namespace Logging {
static uint32_t s_loglevel = LL_ALWAYS; // error and usage messages only

#ifndef ANDROID
void VPrintMsg(const char* pszFormat, va_list& args)
{
    ::vprintf(pszFormat, args);
    ::printf("\n");
    ::fflush(::stdout);
}
#endif

uint32_t GetLogLevel()
{
    return s_loglevel;
}

void SetLogLevel(uint32_t level)
{
    s_loglevel = level;
}

void LogMsg(uint32_t level, const char* pszFormat, ...)
{
    va_list args;
    va_start(args, pszFormat);

    if (level <= s_loglevel)
    {
#ifdef ANDROID
        int androidLogLevel = ANDROID_LOG_UNKNOWN;
        if (level == LL_ALWAYS)
        {
            androidLogLevel = ANDROID_LOG_INFO;
        }
        else if (level == LL_DEBUG)
        {
            androidLogLevel = ANDROID_LOG_DEBUG;
        }
        else
        {
            androidLogLevel = ANDROID_LOG_VERBOSE;
        }
        __android_log_vprint(androidLogLevel, "stuntman", pszFormat, args);
#else
        VPrintMsg(pszFormat, args);
#endif
    }

    va_end(args);
}
}
