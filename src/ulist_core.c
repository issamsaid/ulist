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
/// @file ulist_core.c
/// @author Issam SAID
/// @brief Implement the main manipulation routines of the linked lists.
///
#include <string.h>
#include <ulist/core.h>
#include <ulist/error.h>

CPPGUARD_BEGIN();                                                         

ulist_t* ulist_create(void *data) { 
    ulist_t *n = (ulist_t*) malloc(sizeof(ulist_t));         
    if (n == NULL) 
        ULIST_EXIT(ULIST_OUT_OF_MEMORY, "failed to allocate ulist node");
    if (data == NULL) 
        ULIST_EXIT(ULIST_INVALID_DATA, "the data to wrap can not be NULL"); 
    n->data = data;
    n->next = NULL;                                
    return n;
}                                                  

int ulist_delete(ulist_t **head, void (*release_data)(void*)) {  
    ulist_t     *i = *head;                   
    ulist_t **at_i =  head;                   
    ulist_t     *j;                   
    ulist_t **at_j;
    while(i != NULL) {                                 
        j      = i;                                      
        at_j   = at_i;
        i     = i->next;                                
        at_i  = &i->next;                               
        if (release_data != NULL) release_data(j->data);
        //if (j->data != NULL) free(j->data);
        free(j); 
        *at_j = NULL;                         
    }
    return ULIST_SUCCESS;                                                  
}                                                      

int ulist_put(ulist_t **head, ulist_t *n) {
    ulist_t     *i = *head;                                  
    ulist_t **at_i =  head;                
    if (n == NULL) 
        ULIST_EXIT(ULIST_INVALID_NODE, "the node to be put can not be NULL");                                    
    while(i != NULL) { at_i = &i->next; i = i->next; }                
    *at_i = n;   
    return ULIST_SUCCESS;                                                     
}                                                                     

ulist_t *ulist_pop(ulist_t **head, void *data) {
    ulist_t     *i = *head;                     
    ulist_t **at_i =  head;
    if (data == NULL) 
        ULIST_EXIT(ULIST_INVALID_DATA, "the data to pop out can not be NULL");                     
    while(i != NULL) {                          
        if (i->data == data) { *at_i = i->next; break; }
        at_i = &i->next; i = i->next;                   
    } 
    i->next = NULL;                                                  
    return i;                                           
}

ulist_t* ulist_find(ulist_t **head, void *data) { 
    ulist_t *i = *head;
    if (data == NULL) 
        ULIST_EXIT(ULIST_INVALID_DATA, "the data to query can not be NULL");                     
    while(i != NULL) { 
        if (i->data == data) break; 
        i=i->next; 
    } 
    return i;                                                  
}     

CPPGUARD_END();
