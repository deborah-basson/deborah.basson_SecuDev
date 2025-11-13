#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "concatenate.h"

void test_basic_concatenate(void) {
    const char* foo = "foo";
    const char* bar = "bar";

    char* result = concatenate_data(foo, bar, 100);

    assert(result != NULL);
    assert(strcmp(result, "foobar") == 0);

    printf("test_basic_concatenate: PASSED\n");
}

void setup(void) {
    FILE* f1 = fopen("data1", "w");
    FILE* f2 = fopen("data2", "w");

    if (f1 != NULL) {
        fprintf(f1, "hello");
        fclose(f1);
    }

    if (f2 != NULL) {
        fprintf(f2, "world");
        fclose(f2);
    }
}

void teardown(void) {
    remove("data1");
    remove("data2");
}

void test_concatenate_from_files(void) {
    setup();

    char data1[100] = {0};
    char data2[100] = {0};

    FILE* f1 = fopen("data1", "r");
    FILE* f2 = fopen("data2", "r");

    if (f1 != NULL && f2 != NULL) {
        fgets(data1, sizeof(data1), f1);
        fgets(data2, sizeof(data2), f2);
        fclose(f1);
        fclose(f2);

        char* result = concatenate_data(data1, data2, 100);
        assert(result != NULL);
        assert(strcmp(result, "helloworld") == 0);

        printf("test_concatenate_from_files: PASSED\n");
    }

    teardown();
}

int main(void) {
    test_basic_concatenate();
    test_concatenate_from_files();
    printf("All tests passed!\n");
    return 0;
}
