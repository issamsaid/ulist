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
/// @file test/src/util_test.cc
/// @author Issam SAID
/// @brief Unit testing file for the generic linked list auxiliary routines.
///
#include <gtest/gtest.h>
#include <ulist/ulist.h>

namespace {

    typedef struct __mock_t {
        int   i;
        float f;
    } mock_t;

    mock_t *create_mock(int i, float f) {
        mock_t *m = (mock_t *)malloc(sizeof(mock_t));
        m->i = i;
        m->f = f;
        return m;
    }

    void delete_mock(void* m) { free(m); }

    void print_mock(void *v) { 
        mock_t *m = (mock_t *)v;
        fprintf(stdout, "\t%d - %f\n", m->i, m->f); 
    }

    void increment_mock(void *address) { 
        mock_t *m = (mock_t*)address;
        m->i = (m->i)+1; 
    }

    class UtilTest : public ::testing::Test {
    protected:
        virtual void SetUp() {}
        virtual void TearDown() {}
    };

    TEST_F(UtilTest, size) { 
        ulist_t *list = ulist_create(create_mock(1, 1.3));
        ASSERT_TRUE(list != NULL);
        ASSERT_EQ(ulist_size(&list), 1);
        ulist_delete(&list, delete_mock);
        ASSERT_TRUE(list == NULL);
    }

    TEST_F(UtilTest, print) { 
        unsigned int i = 0;
        ulist_t *list = ulist_create(create_mock(0, 0.0));
        ASSERT_EQ(ulist_size(&list), 1);
        for (i=1; i<1000; i++)
            ulist_put(&list, ulist_create(create_mock(i, i*1.1)));
        ulist_print(&list, print_mock);
        ulist_delete(&list, delete_mock);
        ASSERT_EQ(ulist_size(&list), 0);
    }

    TEST_F(UtilTest, walk) { 
        unsigned int i = 0;
        ulist_t *list = ulist_create(create_mock(0, 0.0));
        ulist_t    *n = list;
        mock_t     *m = NULL;
        ASSERT_EQ(ulist_size(&list), 1);
        for (i=1; i<1000; i++)
            ulist_put(&list, ulist_create(create_mock(i, i*1.1)));
        ulist_walk(&list, increment_mock);
        i = 1;
        while(n != NULL) {
            m = (mock_t*)n->data;
            ASSERT_EQ(m->i, i);
            n = n->next;
            i++;
        }
        ulist_delete(&list, delete_mock);
        ASSERT_EQ(ulist_size(&list), 0);
    }
}