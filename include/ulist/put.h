#ifndef _ULIST_PUT_H_
#define _ULIST_PUT_H_
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
/// @brief Header and implementation of the routine used to add an entry to 
/// a linked list.
///
#define DEFINE_ULIST_PUT(TYPE)   \
    void ulist_put_##TYPE(list_##TYPE##_t **head, TYPE data);

#define IMPLEMENT_ULIST_PUT(TYPE)                               \
    void ulist_put_##TYPE(list_##TYPE##_t** head, TYPE data) {  \
        list_##TYPE##_t*     n = *head;                         \
        list_##TYPE##_t** prev =  head;                         \
        list_##TYPE##_t* entry =                                \
            (list_##TYPE##_t*) malloc(sizeof(list_##TYPE##_t)); \
        entry->data = data;                                     \
        entry->next = NULL;                                     \
        while(n != NULL) {                                      \
            prev = &n->next;                                    \
            n    = n->next;                                     \
        }                                                       \
        *prev = entry;                                          \
    }

#endif  // _ULIST_PUT_H_