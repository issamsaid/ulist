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
/// @file ulist_util.c
/// @author Issam SAID
/// @brief Implement the optional routines to walk through the linked lists.
///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ulist/util.h>
#include <ulist/error.h>
#include <ulist/log.h>

CPPGUARD_BEGIN();                                                         

size_t ulist_size(ulist_t** head) { 
    size_t count = 0;                                 
    ulist_t* i = *head;                    
    while(i != NULL) { count++; i=i->next; }                                               
    return count;                                   
}                                                   

void ulist_print(ulist_t** head, void (*print_data)(void*)) {
    ulist_t* i = *head;   
    if (print_data == NULL) 
        ULIST_EXIT(ULIST_INVALID_FUNCTOR, "the data printer can not be NULL");                 
    ULIST_PRINT("Content");    
    while(i != NULL) {                
        print_data(i->data);          
        ULIST_PRINT("---");           
        ULIST_PRINT("---");           
        i=i->next;                    
    }                                 
    ULIST_PRINT("NULL");              
}                                     

void ulist_walk(ulist_t** head, void (*function)(void*)){     
    ulist_t* i = *head;  
    if (function == NULL) 
        ULIST_EXIT(ULIST_INVALID_FUNCTOR, "the function can not be NULL");                               
    while(i != NULL) { function(i->data); i=i->next; }                                               
}                                                   

CPPGUARD_END();
