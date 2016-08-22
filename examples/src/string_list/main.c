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
/// @file examples/src/string_list/main.c
/// @author Issam SAID
/// @brief Implementation of an example of an string linked list using ulist.
///
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ulist/ulist.h>

///
/// @brief Allocate memory for a string.
///
char *create_string(const char *value, int i) {
    char *s = (char *)malloc(32);
    sprintf(s, "%s_%i", value, i);
    s[31] = '\0';
    return s;
}

///
/// @brief Delete a string.
///
void delete_string(void* s) { free(s); }

///
/// @brief A function to print the data of an entry in the date list.
///
void print_string(void *s) { fprintf(stdout, "\t%s\n", (char*)s); }

///
/// @brief A function used to illustrate a use case of the walk routine.
///
void capitalize_string(void *address) { 
    char *s = (char *)address;
    unsigned int i;
    for(i=0; i<strlen(s); i++) {
        if ((s[i]>='a') && (s[i]<='z'))
            s[i]=toupper(s[i]);
    }
}

///
/// @brief Main function to show how to use <b>ulist</b> to implement 
/// an string linked list.
///
/// @param Nothing.
/// @return Nothing.
///
int main( void) {
    char *my_string;
    ulist_t   *list = NULL;
    ulist_t   *node = NULL;
    unsigned int i;
    fprintf(stdout, "... Start string list example.\n");
    fprintf(stdout, "... Filling in the string linked list.\n");
    for (i=1; i<=20; i++)
        ulist_put(&list, ulist_create(create_string("foo", i)));
    my_string = create_string("my_string", 0);
    ulist_put(&list, ulist_create(my_string));
    for (i=22; i<=31; i++)
        ulist_put(&list, ulist_create(create_string("bar", i)));
    fprintf(stdout, "... The list size is: %ld.\n", ulist_size(&list));    
    ulist_print(&list, print_string);
    fprintf(stdout, "... Searching for one particular data in the list.\n");
    node = ulist_find(&list, my_string);
    if (node != NULL) fprintf(stdout, "... Found.\n");
    fprintf(stdout, "... Retrieving that node from the list.\n");
    node = ulist_pop(&list, my_string);
    ulist_print(&node, print_string);
    fprintf(stdout, 
            "... The list size is now: %ld.\n", ulist_size(&list));
    fprintf(stdout, 
            "... Walk through the list data and capitalize each string.\n");
    ulist_walk(&list, capitalize_string);
    ulist_print(&list, print_string);
    fprintf(stdout, "... Emptying the linked list.\n");
    ulist_delete(&list, delete_string);
    fprintf(stdout, "... End string list example.\n");
    return EXIT_SUCCESS;
}