#ifndef _ULIST_H_
#define _ULIST_H_
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
/// 3. Neither the name of the UPMC nor the names of its contributors
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
/// @file ulist/ulist.h
/// @author Issam SAID
/// @brief Gather the generic linked lists manipulation routines in one file.
///
#define DEFINE_LIST_SIZE(type)   \
    size_t list_size_##type(list_##type** head);

#define DEFINE_ULIST(TYPE)    \
    DEFINE_ULIST_TYPES(TYPE)  \
    DEFINE_ULIST_PUT(TYPE)    \
    DEFINE_ULIST_POP(TYPE)    \
    DEFINE_ULIST_FIND(TYPE)   \
    DEFINE_ULIST_UTIL(TYPE)        



#define IMPLEMENT_LIST_SIZE(type)                                        \
    size_t list_size_##type(list_##type** head) {                        \
        size_t count = 0;                                                \
        list_##type* n = *head;                                          \
        while(n != NULL) {                                               \
            count++;                                                     \
            n=n->next;                                                   \
        }                                                                \
        return count;                                                    \
    }

#define IMPLEMENT_ULIST(TYPE)  \
    IMPLEMENT_ULIST_PUT(TYPE)  \
    IMPLEMENT_ULIST_POP(TYPE)  \
    IMPLEMENT_ULIST_FIND(TYPE) \
    IMPLEMENT_ULIST_UTIL(TYPE)

#endif  // _ULIST_H_