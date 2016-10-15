#ifndef __ULIST_ERROR_H_
#define __ULIST_ERROR_H_
///
/// @copyright Copyright (c) 2016-, Issam SAID <said.issam@gmail.com>.
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permetted provided that the following conditions
/// are met:
///
/// 1. Redistributions of source code must retain the above copyright
///    notice, this list of conditions and the following disclaimer.
/// 2. Redistributions in binary form must reproduce the above copyright
///    notice, this list of conditions and the following disclaimer in the
///    documentation and/or other materials provided with the distribution.
/// 3. Neither the name of the copyright holder nor the names of its contributors
///    may be used to endorse or promote products derived from this software
///    without specific prior written permission.
///
/// THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
/// INCLUDING, BUT NOT LIMITED TO, WARRANTIES OF MERCHANTABILITY AND FITNESS
/// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE copyright holder OR
/// ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
/// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
/// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
/// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
/// LIABILITY, WETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
/// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
/// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
/// @file ulist/error.h
/// @author Issam SAID
/// @brief ulist error handling routines and macros.    
///
#include <stdlib.h>
#include <ulist/guard.h>
#include <ulist/colors.h>

CPPGUARD_BEGIN();

#define ULIST_SUCCESS          0
#define ULIST_OUT_OF_MEMORY   -1
#define ULIST_INVALID_NODE    -2
#define ULIST_INVALID_DATA    -3
#define ULIST_INVALID_FUNCTOR -4

#define ULIST_EXIT(error_code, fmt,...)                                     \
{                                                                           \
    fprintf(stderr, C_RED"[ULIST ERR(%s)]: "fmt" @%s:%d.\n"C_END,           \
            ULIST_ERROR_MSG(error_code),##__VA_ARGS__, __FILE__, __LINE__); \
    exit(error_code);                                                       \
}

#define ULIST_ERROR_MSG(error_code)                                     \
    ((error_code == ULIST_SUCCESS)         ? "ULIST_SUCCESS"          : \
     (error_code == ULIST_OUT_OF_MEMORY)   ? "ULIST_OUT_OF_MEMORY"    : \
     (error_code == ULIST_INVALID_NODE)    ? "ULIST_INVALID_NODE"     : \
     (error_code == ULIST_INVALID_DATA)    ? "ULIST_INVALID_DATA"     : \
     (error_code == ULIST_INVALID_FUNCTOR) ? "ULIST_INVALID_FUNCTOR"  : \
    "ULIST_UNKNOWN")

CPPGUARD_END();

#endif  // __ULIST_ERROR_H_