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
/// @file examples/src/struct_list/main.c
/// @author Issam SAID
/// @brief Implementation of an example of an struct linked list using ulist.
///
#include <stdlib.h>
#include <ulist/ulist.h>

///
/// @brief A date structure for the sake of example.
///
typedef struct __date_t {
    int year;
    int month;
    int day;
} date_t;

///
/// @brief Allocate a date structure.
///
date_t *create_date(int d, int m, int y) {
    date_t *dt = (date_t*)malloc(sizeof(date_t));
    dt->year  = y;
    dt->month = m;
    dt->day   = d;
    return dt;
}

///
/// @brief Delete a date structure.
///
void delete_date(void* dt) { free(dt); }

///
/// @brief A function to print the data of an entry in the date list.
///
void print_date(void *address) { 
    date_t *dt = (date_t*)address;
    fprintf(stdout, "\t%d/%d/%d\n", dt->day, dt->month, dt->year); 
}

///
/// @brief A function used to illustrate a use case of the walk routine.
///
void increment_date(void *address) { 
    date_t *dt = (date_t*)address;
    dt->day = (dt->day+1)%31+1; 
}

///
/// @brief Main function to show how to use <b>ulist</b> to implement 
/// an struct linked list.
///
/// @param Nothing.
/// @return Nothing.
///
int main( void) {
    date_t *my_date = NULL;
    ulist_t   *list = NULL;
    ulist_t   *node = NULL;
    unsigned int i;
    fprintf(stdout, "... Start struct list example.\n");
    fprintf(stdout, "... Filling in the struct linked list.\n");
    for (i=1; i<=20; i++)
        ulist_put(&list, ulist_create(create_date(i, 8, 2016)));
    my_date = create_date(21, 8, 2016);
    ulist_put(&list, ulist_create(my_date));
    for (i=22; i<=31; i++)
        ulist_put(&list, ulist_create(create_date(i, 8, 2016)));
    fprintf(stdout, "... The list size is: %ld.\n", ulist_size(&list));    
    ulist_print(&list, print_date);
    fprintf(stdout, "... Searching for one particular data in the list.\n");
    node = ulist_find(&list, my_date);
    if (node != NULL) fprintf(stdout, "... Found.\n");
    fprintf(stdout, "... Retrieving that node from the list.\n");
    node = ulist_pop(&list, my_date);
    ulist_print(&node, print_date);
    fprintf(stdout, 
            "... The list size is now: %ld.\n", ulist_size(&list));
    fprintf(stdout, 
            "... Walk through the list data and increment each date.\n");
    ulist_walk(&list, increment_date);
    ulist_print(&list, print_date);
    fprintf(stdout, "... Emptying the linked list.\n");
    ulist_delete(&list, delete_date);
    fprintf(stdout, "... End struct list example.\n");
    return EXIT_SUCCESS;
}