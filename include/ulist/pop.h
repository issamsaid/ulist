#ifndef _ULIST_POP_H_
#define _ULIST_POP_H_
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
/// @file ulist/pop.h
/// @author Issam SAID
/// @brief Header and implementation of the routine used to remove an entry  
/// from a linked list.
///
#define DEFINE_ULIST_POP(TYPE)                               \
    void ulist_pop_##TYPE(ulist_##TYPE##_t **head, TYPE data);

#define IMPLEMENT_ULIST_POP(TYPE)                               \
    void ulist_pop_##TYPE(ulist_##TYPE##_t **head, TYPE data) { \
        ulist_##TYPE##_t* to_remove;                            \
        ulist_##TYPE##_t*  n    = *head;                        \
        ulist_##TYPE##_t** prev =  head;                        \
        while(n != NULL) {                                      \
            if (n->data == data) {                              \
                to_remove = n;                                  \
                *prev     = n->next;                            \
            }                                                   \
            prev = &n->next;                                    \
            n    = n->next;                                     \
        }                                                       \
        free(to_remove);                                        \
        to_remove = NULL;                                       \
    }

#endif  // _ULIST_POP_H_