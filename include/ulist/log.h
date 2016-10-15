#ifndef __ULIST_LOG_H_
#define __ULIST_LOG_H_
///
/// @copyright Copyright (c)2016-, Issam SAID <said.issam@gmail.com>
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
/// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
/// HOLDER OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
/// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
/// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
/// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
/// LIABILITY, WETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
/// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
/// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
/// @file ulist/log.h
/// @author Issam SAID
/// @brief Macros to format information or debug messages when using ulist.
///
#include <stdio.h>
#include <ulist/colors.h>

#ifdef  __ULIST_DEBUG
#define __ULIST_VERBOSE
#define ULIST_DEBUG(fmt,...)                                       \
fprintf(stdout, C_PURPLE"[ULIST DBG]: "fmt".\n"C_END, ##__VA_ARGS__)
#else 
#define ULIST_DEBUG(fmt,...) 
#endif  // __ULIST_DEBUG

#ifdef __ULIST_VERBOSE                             
#define ULIST_PRINT(fmt,...)                                      \
fprintf(stdout, C_GREEN"[ULIST MSG]: "fmt".\n"C_END, ##__VA_ARGS__)
#else 
#define ULIST_PRINT(fmt,...) 
#endif  // __ULIST_VERBOSE 

#endif  // __ULIST_LOG_H_