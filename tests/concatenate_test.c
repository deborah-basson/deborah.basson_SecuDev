#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "concatenate.h"

void test_basic_concatenate(void) {
    const char* foo = "foo";
    const char* bar = "bar";

    char* result = concatenate_data(foo, bar, MAX_INPUT_SIZE);

    assert(result != NULL);
    assert(strcmp(result, "foobar") == 0);

    (void)printf("[PASSED] test_basic_concatenate\n");
}

void setup(void) {
    FILE* file1 = fopen("data1", "w");
    FILE* file2 = fopen("data2", "w");

    if (file1 != NULL) {
        (void)fprintf(file1, "hello");
        (void)fclose(file1);
    }

    if (file2 != NULL) {
        (void)fprintf(file2, "world");
        (void)fclose(file2);
    }
}

void teardown(void) {
    (void)remove("data1");
    (void)remove("data2");
}

void test_concatenate_from_files(void) {
    setup();

    char data1[MAX_INPUT_SIZE] = {0};
    char data2[MAX_INPUT_SIZE] = {0};

    FILE* file1 = fopen("data1", "r");
    FILE* file2 = fopen("data2", "r");

    if (file1 != NULL && file2 != NULL) {
        (void)fgets(data1, sizeof(data1), file1);
        (void)fgets(data2, sizeof(data2), file2);
        (void)fclose(file1);
        (void)fclose(file2);

        char* result = concatenate_data(data1, data2, MAX_INPUT_SIZE);
        assert(result != NULL);
        assert(strcmp(result, "helloworld") == 0);

        (void)printf("[PASSED] test_concatenate_from_files\n");
    } else {
        if (file1 != NULL) {
            (void)fclose(file1);
        }
        if (file2 != NULL) {
            (void)fclose(file2);
        }
        (void)fprintf(stderr, "[FAILED] test_concatenate_from_files : Failed to open test files\n");
    }

    teardown();
}

int main(void) {
    test_basic_concatenate();
    test_concatenate_from_files();
    (void)printf("[DONE] Testsuite execution finished.\n");
    return 0;
}
