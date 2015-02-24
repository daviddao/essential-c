#include "minunit.h"
#include "../src/hashmap.h"
#include <assert.h>
#include <string.h>

Hashmap *map = NULL;
static int traverse_called = 0;
char* test1 = "test data 1";
char* test2 = "test data 2";
char* test3 = "xest data 3";
char* expect1 = "THE VALUE 1";
char* expect2 = "THE VALUE 2";
char* expect3 = "THE VALUE 3";

static int traverse_good_cb(HashmapNode *node)
{
    debug("KEY: %s", (char*)node->key);
    traverse_called++;
    return 0;
}


static int traverse_fail_cb(HashmapNode *node)
{
    debug("KEY: %s", (char*)node->key);
    traverse_called++;

    if(traverse_called == 2) {
        return 1;
    } else {
        return 0;
    }
}


char *test_create()
{
    map = Hashmap_create(NULL, NULL);
    mu_assert(map != NULL, "Failed to create map.");

    return NULL;
}

char *test_destroy()
{
    Hashmap_destroy(map);

    return NULL;
}


char *test_get_set()
{
    int rc = Hashmap_set(map, test1, expect1);
    mu_assert(rc == 0, "Failed to set expect1");
    char* result = Hashmap_get(map, test1);
    mu_assert(result == expect1, "Wrong value for test1.");

    rc = Hashmap_set(map, test2, expect2);
    mu_assert(rc == 0, "Failed to set test2");
    result = Hashmap_get(map, test2);
    mu_assert(result == expect2, "Wrong value for test2.");

    rc = Hashmap_set(map, test3, expect3);
    mu_assert(rc == 0, "Failed to set test3");
    result = Hashmap_get(map, test3);
    mu_assert(result == expect3, "Wrong value for test3.");

    return NULL;
}

char *test_get_set_unique()
{
    int rc = Hashmap_set(map, test1, expect1);
    mu_assert(rc == 0, "Failed to set expect1");
    char* result = Hashmap_get(map, test1);
    mu_assert(result == expect1, "Wrong value for test1.");

    rc = Hashmap_set(map, test1, expect2);
    mu_assert(rc == 1, "Failed to detect uniqueness");
    result = Hashmap_get(map, test1);
    mu_assert(result == expect1, "Wrong value for test2.");

    rc = Hashmap_set(map, test3, expect3);
    mu_assert(rc == 0, "Failed to set test3");
    result = Hashmap_get(map, test3);
    mu_assert(result == expect3, "Wrong value for test3.");

    return NULL;
}

char *test_traverse()
{
    int rc = Hashmap_traverse(map, traverse_good_cb);
    mu_assert(rc == 0, "Failed to traverse.");
    mu_assert(traverse_called == 3, "Wrong count traverse.");

    traverse_called = 0;
    rc = Hashmap_traverse(map, traverse_fail_cb);
    mu_assert(rc == 1, "Failed to traverse.");
    mu_assert(traverse_called == 2, "Wrong count traverse for fail.");

    return NULL;
}

char *test_delete()
{
    char* deleted = (char*)Hashmap_delete(map, test1);
    mu_assert(deleted != NULL, "Got NULL on delete.");
    mu_assert(deleted == expect1, "Should get test1");
    char* result = Hashmap_get(map, test1);
    mu_assert(result == NULL, "Should delete.");

    deleted = (char*)Hashmap_delete(map, test2);
    mu_assert(deleted != NULL, "Got NULL on delete.");
    mu_assert(deleted == expect2, "Should get test2");
    result = Hashmap_get(map, test2);
    mu_assert(result == NULL, "Should delete.");

    deleted = (char*)Hashmap_delete(map, test3);
    mu_assert(deleted != NULL, "Got NULL on delete.");
    mu_assert(deleted == expect3, "Should get test3");
    result = Hashmap_get(map, test3);
    mu_assert(result == NULL, "Should delete.");

    return NULL;
}

char *test_delete_unique()
{
    char* deleted = (char*)Hashmap_delete(map, test1);
    mu_assert(deleted != NULL, "Got NULL on delete.");
    mu_assert(deleted == expect1, "Should get test1");
    char* result = Hashmap_get(map, test1);
    mu_assert(result == NULL, "Should delete.");

    deleted = (char*)Hashmap_delete(map, test2);
    mu_assert(deleted == NULL, "Got sth different than NULL on delete.");
    result = Hashmap_get(map, test2);
    mu_assert(result == NULL, "Should delete.");

    deleted = (char*)Hashmap_delete(map, test3);
    mu_assert(deleted != NULL, "Got NULL on delete.");
    mu_assert(deleted == expect3, "Should get test3");
    result = Hashmap_get(map, test3);
    mu_assert(result == NULL, "Should delete.");

    return NULL;
}


char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_get_set);
    mu_run_test(test_traverse);
    mu_run_test(test_delete);
    mu_run_test(test_get_set_unique);
    mu_run_test(test_delete_unique);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);