#include "trap.h"

// Test for strlen
void test_strlen() {
    check(strlen("") == 0);
    check(strlen("Hello") == 5);
    check(strlen("abcdef") == 6);
    check(strlen("Hello, World!") == 13);
}

// Test for strcpy
void test_strcpy() {
    char dest[20];
    strcpy(dest, "Hello");
    check(strcmp(dest, "Hello") == 0);
    strcpy(dest, "");
    check(strcmp(dest, "") == 0);
}

// Test for strncpy
void test_strncpy() {
    char dest[20];
    strncpy(dest, "Hello", 3);
    dest[3] = '\0'; // strncpy does not null-terminate if n is reached
    check(strcmp(dest, "Hel") == 0);
    strncpy(dest, "Hello", 10);
    check(strcmp(dest, "Hello") == 0);
}

// Test for strcat
void test_strcat() {
    char dest[20] = "Hello";
    strcat(dest, ", World!");
    check(strcmp(dest, "Hello, World!") == 0);
    strcat(dest, "");
    check(strcmp(dest, "Hello, World!") == 0);
}

// Test for strcmp
void test_strcmp() {
    check(strcmp("Hello", "Hello") == 0);
    check(strcmp("Hello", "hello") < 0);
    check(strcmp("Hello", "Hell") > 0);
}

// Test for strncmp
void test_strncmp() {
    check(strncmp("Hello", "Hell", 4) == 0);
    check(strncmp("Hello", "Hell", 5) > 0);
    check(strncmp("Hello", "hello", 5) < 0);
}

// Test for memset
void test_memset() {
    char buffer[10];
    memset(buffer, 'A', 5);
    for (int i = 0; i < 5; i++) {
        check(buffer[i] == 'A');
    }
}

// Test for memmove
void test_memmove() {
    char buffer[10] = "abcdef";
    memmove(buffer + 2, buffer, 4); // overlapping move
    check(strcmp(buffer, "ababcd") == 0);
}

// Test for memcpy
void test_memcpy() {
    char src[10] = "abcdef";
    char dest[10];
    memcpy(dest, src, 6);
    check(strcmp(dest, "abcdef") == 0);
}

// Test for memcmp
void test_memcmp() {
    char buffer1[5] = "abc";
    char buffer2[5] = "abd";
    check(memcmp(buffer1, buffer2, 3) < 0);
    check(memcmp(buffer1, buffer1, 3) == 0);
}

// Test for malloc
void test_malloc() {
    char *ptr = (char *)malloc(10);
    check(ptr != NULL);
    memset(ptr, 'A', 10);
    for (int i = 0; i < 10; i++) {
        check(ptr[i] == 'A');
    }
    free(ptr);
}

// Test for sprintf
void test_sprintf() {
    char buffer[50];
    sprintf(buffer, "%s %d", "Number", 10);
    check(strcmp(buffer, "Number 10") == 0);
}

void comprehensive_test() {
    char buffer1[50];
    char buffer2[50];
    char buffer3[50];
    char small_buffer[10];
    
    // Initialize buffers
    memset(buffer1, 0, sizeof(buffer1));
    memset(buffer2, 0, sizeof(buffer2));
    memset(buffer3, 0, sizeof(buffer3));
    
    // strcpy + strcat + strlen
    strcpy(buffer1, "Hello");
    check(strlen(buffer1) == 5);
    strcat(buffer1, ", ");
    strcat(buffer1, "World!");
    check(strlen(buffer1) == 13);
    
    // strncpy
    strncpy(buffer2, buffer1, 5);
    buffer2[5] = '\0';
    check(strcmp(buffer2, "Hello") == 0);
    
    // sprintf + strlen + strcat
    sprintf(buffer3, "The message is: ");
    strcat(buffer3, buffer1);
    check(strlen(buffer3) == strlen("The message is: Hello, World!"));
    
    // strcmp + strncmp
    check(strcmp(buffer1, "Hello, World!") == 0);
    check(strncmp(buffer1, "Hello", 5) == 0);
    
    // memmove with overlapping regions
    memmove(buffer1 + 7, buffer1, 6); // Moving "Hello" to start at index 7
    check(strcmp(buffer1, "Hello, Hello,") == 0);
    
    // memcpy + memcmp
    memcpy(small_buffer, "Test", 4);
    small_buffer[4] = '\0';
    check(memcmp(small_buffer, "Test", 4) == 0);
}

#define MAX_LEN 100

// Function to generate a random string of given length
void generate_random_string(char *str, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    str[length] = '\0';
}

void random_comprehensive_test() {
    char buffer1[MAX_LEN];
    char buffer2[MAX_LEN];
    char buffer3[MAX_LEN];
    char small_buffer[MAX_LEN];
    
    int len1 = rand() % (MAX_LEN / 2) + 1;  // Random length between 1 and MAX_LEN/2
    int len2 = rand() % (MAX_LEN / 2) + 1;
    int len3 = rand() % (MAX_LEN / 2) + 1;
    
    // Generate random strings
    generate_random_string(buffer1, len1);
    generate_random_string(buffer2, len2);
    generate_random_string(buffer3, len3);
    
    // Testing strcat + strlen + strcpy
    strcpy(small_buffer, buffer1);
    strcat(small_buffer, buffer2);
    check(strlen(small_buffer) == len1 + len2);
    
    // Testing strncmp + strncpy
    if (len3 < len1 + len2) {
        strncpy(buffer3, small_buffer, len3);
        buffer3[len3] = '\0';
        check(strncmp(buffer3, small_buffer, len3) == 0);
    }
    
    // Testing memmove (random overlapping regions)
    int overlap_offset = rand() % len1;
    char temp_buffer[MAX_LEN];
    memcpy(temp_buffer, buffer1, len1);  // Copy buffer1 to a temporary buffer
    memmove(buffer1 + overlap_offset, temp_buffer, len1 - overlap_offset);
    
    // Verify that overlapping memmove did not corrupt the memory
    for (int i = 0; i < len1 - overlap_offset; i++) {
        check(buffer1[overlap_offset + i] == temp_buffer[i]);
    }
    
    // Testing memcpy + memcmp
    memcpy(small_buffer, buffer2, len2);
    small_buffer[len2] = '\0';
    check(memcmp(small_buffer, buffer2, len2) == 0);
    
    // Testing sprintf with random integer
    int random_number = rand() % 10000;
    sprintf(buffer1, "Random number: %d", random_number);
}

void test_string_functions() {
    char src[MAX_LEN] = "Hello, World!";
    char dst[MAX_LEN];
    char buf[MAX_LEN];

    // Test strlen
    check(strlen(src) == 13);

    // Test strcpy
    strcpy(dst, src);
    check(strcmp(dst, src) == 0);

    // Test strncpy
    strncpy(dst, src, 5);
    dst[5] = '\0';
    check(strcmp(dst, "Hello") == 0);

    // Test strcat
    strcpy(dst, "Hello");
    strcat(dst, ", World!");
    check(strcmp(dst, src) == 0);

    // Test strcmp
    check(strcmp(src, dst) == 0);
    check(strcmp(src, "Hello, Universe!") != 0);

    // Test strncmp
    check(strncmp(src, "Hello, Universe!", 7) == 0);
    check(strncmp(src, "Hello, Universe!", 8) != 0);

    // Test memset
    memset(dst, 'A', 10);
    for (int i = 0; i < 10; i++) {
        check(dst[i] == 'A');
    }

    // Test memmove
    char temp[MAX_LEN];
    strcpy(temp, src);
    memmove(temp + 7, temp, 6);
    check(strcmp(temp, "Hello, Hello,") == 0);

    // Test memcpy
    memcpy(dst, src, 13);
    check(strcmp(dst, src) == 0);

    // Test memcmp
    check(memcmp(src, dst, 13) == 0);
    check(memcmp(src, "Hello, Universe!", 13) != 0);

    // Test malloc and free
    char *dynamic_str = (char *)malloc(14);
    check(dynamic_str != NULL);
    strcpy(dynamic_str, src);
    check(strcmp(dynamic_str, src) == 0);
    free(dynamic_str);

    // Test sprintf and printf with %d, %s, and %c
    int num = 42;
    char str[] = "Test";
    char ch = 'A';

    sprintf(buf, "Number: %d, String: %s, Char: %c", num, str, ch);
    check(strcmp(buf, "Number: 42, String: Test, Char: A") == 0);
}

// Function to generate a random integer
int generate_random_integer() {
    return rand() % 10000;
}

// Function to generate a random character
char generate_random_character() {
    return (char)(rand() % 26 + 'A');
}

void random_test_string_functions() {
    char src[MAX_LEN];
    char dst[MAX_LEN];
    char buf[MAX_LEN];
    char expected[MAX_LEN];

    // Generate random data
    int rand_len = rand() % (MAX_LEN / 2) + 1;
    generate_random_string(src, rand_len);
    int rand_int = generate_random_integer();
    char rand_char = generate_random_character();

    // Test strlen
    check(strlen(src) == rand_len);

    // Test strcpy
    strcpy(dst, src);
    check(strcmp(dst, src) == 0);

    // Test strncpy
    int n = rand() % rand_len + 1;
    strncpy(dst, src, n);
    dst[n] = '\0';
    check(strncmp(dst, src, n) == 0);

    // Test strcat
    strcpy(dst, "Prefix");
    strcat(dst, src);
    sprintf(expected, "Prefix%s", src);
    check(strcmp(dst, expected) == 0);

    // Test strcmp
    check(strcmp(src, src) == 0);
    check(strcmp(src, "Different") != 0);

    // Test strncmp
    check(strncmp(src, src, rand_len) == 0);
    check(strncmp(src, "Different", rand_len) != 0);

    // Test memset
    memset(dst, rand_char, rand_len);
    for (int i = 0; i < rand_len; i++) {
        check(dst[i] == rand_char);
    }

// Testing memmove (random overlapping regions)
int overlap_offset = rand() % rand_len;
char temp_buffer[MAX_LEN];
memcpy(temp_buffer, src, rand_len);  // Copy src to a temporary buffer
memmove(src + overlap_offset, temp_buffer, rand_len - overlap_offset);

// Verify that overlapping memmove did not corrupt the memory
for (int i = 0; i < rand_len - overlap_offset; i++) {
    check(src[overlap_offset + i] == temp_buffer[i]);
}
    // Test memcpy
    memcpy(dst, src, rand_len);
    check(strncmp(dst, src, rand_len) == 0);

    // Test memcmp
    check(memcmp(src, src, rand_len) == 0);
    check(memcmp(src, "Different", rand_len) != 0);

    // Test malloc and free
    char *dynamic_str = (char *)malloc(rand_len + 1);
    check(dynamic_str != NULL);
    strcpy(dynamic_str, src);
    check(strcmp(dynamic_str, src) == 0);
    free(dynamic_str);

    // Test sprintf and printf with %d, %s, and %c
    sprintf(buf, "Number: %d, String: %s, Char: %c", rand_int, src, rand_char);
    sprintf(expected, "Number: %d, String: %s, Char: %c", rand_int, src, rand_char);
    check(strcmp(buf, expected) == 0);

}

int main(const char *args) {
    int seed = atoi(args);
    printf("seed = %d\n", seed);
    test_strlen();
    test_strcpy();
    test_strncpy();
    test_strcat();
    test_strcmp();
    test_strncmp();
    test_memset();
    test_memmove();
    test_memcpy();
    test_memcmp();
    test_malloc();
    test_sprintf();
    comprehensive_test();
    srand(seed);
    for (int i = 0; i < 5; i++)
    {
    	random_comprehensive_test();
    	random_test_string_functions();
    }
    test_string_functions();
    return 0;
}

