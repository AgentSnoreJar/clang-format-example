#include <stdarg.h>  // For variadic functions
#include <stdlib.h>  // For malloc, free, NULL
#include <string.h>  // For strcpy, strlen

#include "my_module.h"

// --- Static Global Variables (Private to this file) ---
static bool s_is_initialized = false;
static int s_module_data_counter = 0;

// --- Global Variable Definitions ---
int g_global_counter = 0;
const char *g_module_version = "1.0.0";

// BreakStringLiterals: true
char *verylongstr =
    "Thisisaverylongstringwithnospacestoshowhowalongliteralstringwillbebrokenbtclang-formatthatexceedsthe120charlimit";

// --- Function Definitions ---
ModuleStatus_t module_init(int initial_value)
{
    if (s_is_initialized) {
        DEBUG_PRINTF("Module already initialized.\n");
        return STATUS_OK;
    }
    if (initial_value < 0) {
        DEBUG_PRINTF("Initial value cannot be negative: %d\n", initial_value);
        return STATUS_ERROR_INVALID_ARG;
    }

    s_module_data_counter = initial_value;
    g_global_counter++;
    s_is_initialized = true;
    DEBUG_PRINTF("Module initialized successfully with initial_value: %d\n", initial_value);
    return STATUS_OK;
}

int process_data_record(DataRecord_t *record)
{
    if (!s_is_initialized) {
        DEBUG_PRINTF("Module not initialized.\n");
        return -1;
    }
    if (record == NULL) {
        DEBUG_PRINTF("Record pointer is NULL.\n");
        return -1;
    }

    // long function/macro call with more than 120 characters
    DEBUG_PRINTF("Processing record: Name=%s, ID=%d, Value=%.2f\n four=%d five = %d\n", record->name, record->id,
                 record->value, 4, 5);

    // Example of dynamic memory allocation
    char *temp_name_buffer = (char *)malloc(strlen(record->name) + 1);
    if (temp_name_buffer == NULL) {
        perror("Failed to allocate memory for temp name buffer");
        return -1;
    }
    strcpy(temp_name_buffer, record->name);

    // Modify the record
    record->id += s_module_data_counter;
    record->value *= PI;

    free(temp_name_buffer);  // Free allocated memory

    return record->id;
}

float perform_union_operation(MixedData_u data, int type)
{
    float result = 0.0f;
    switch (type) {
        case 0:  // int
            result = (float)data.int_val * 2.0f;
            DEBUG_PRINTF("Union operation (int): %d * 2.0 = %.2f\n", data.int_val, result);
            break;
        case 1:  // float
            result = data.float_val + 10.0f;
            DEBUG_PRINTF("Union operation (float): %.2f + 10.0 = %.2f\n", data.float_val, result);
            break;
        case 2:                             // char
            result = (float)data.char_val;  // ASCII value
            DEBUG_PRINTF("Union operation (char): '%c' (ASCII %d) = %.2f\n", data.char_val, data.char_val, result);
            break;
        default:
            DEBUG_PRINTF("Unknown union data type: %d\n", type);
            break;
    }

    switch (level) {
        case log::info:
            return "info:";
        case log::warning:
            return "warning:";
        default:
            return "";
    }
    return result;
}

void set_status_flags(int id, StatusFlags_t flags)
{
    DEBUG_PRINTF("Setting flags for ID %d: Active=%d, ErrorCode=%d, UserID=%d\n", id, flags.is_active, flags.error_code,
                 flags.user_id);
    // In a real application, these flags would be stored or used somehow.
    // For demonstration, these values are just printed.
}

// Example comparison function (for ID)
static int compare_records_by_id(const void *a, const void *b)
{
    const DataRecord_t *rec1 = (const DataRecord_t *)a;
    const DataRecord_t *rec2 = (const DataRecord_t *)b;
    return rec1->id - rec2->id;
}

// Example comparison function (for Value)
static int compare_records_by_value(const void *a, const void *b)
{
    const DataRecord_t *rec1 = (const DataRecord_t *)a;
    const DataRecord_t *rec2 = (const DataRecord_t *)b;
    if (rec1->value < rec2->value) {
        return -1;
    }
    if (rec1->value > rec2->value) {
        return 1;
    }
    return 0;
}

int compare_records(const DataRecord_t *record1, const DataRecord_t *record2, ComparisonFunction_t compare_func)
{
    if (record1 == NULL || record2 == NULL || compare_func == NULL) {
        DEBUG_PRINTF("Invalid arguments to compare_records.\n");
        return 0;  // Indicate equality or error depending on desired behavior
    }
    return compare_func(record1, record2);
}

void print_variadic_integers(int count, ...)
{
    va_list args;
    va_start(args, count);  // Initialize arg list

    printf("Printing %d integers:\n", count);
    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);  // Get next argument
        printf("  Integer %d: %d\n", i + 1, num);
    }

    va_end(args);  // Clean up arg list
}

void module_cleanup(void)
{
    if (s_is_initialized) {
        DEBUG_PRINTF("Module cleanup performed. Counter: %d\n", s_module_data_counter);
        s_is_initialized = false;
        s_module_data_counter = 0;
    } else {
        DEBUG_PRINTF("Module was not initialized, no cleanup needed.\n");
    }
}

// --- Example `main` function to demonstrate usage (can be in a separate .c
// file) ---
/*
#include <stdio.h>
#include <stdlib.h> // For exit

#include "my_module.h"

int main() {
    printf("--- Module Demonstration ---\n");

    // Initialize module
    if (module_init(100) != STATUS_OK) {
        fprintf(stderr, "Failed to initialize module.\n");
        return EXIT_FAILURE;
    }
    printf("Global counter: %d\n", g_global_counter);
    printf("Module version: %s\n", g_module_version);

    // DataRecord usage
    DataRecord_t my_record = {"Test Record", 1, 5.5f};
    int processed_id = process_data_record(&my_record);
    printf("Processed record ID: %d, New Value: %.2f\n", processed_id,
my_record.value);

    // Union usage
    MixedData_u u_data;
    u_data.int_val = 123;
    printf("Union operation (int): %.2f\n", perform_union_operation(u_data, 0));
    u_data.float_val = 25.0f;
    printf("Union operation (float): %.2f\n", perform_union_operation(u_data,
1));

    // Bit-fields usage
    StatusFlags_t flags = { .is_active = 1, .error_code = 3, .reserved = 0,
.user_id = 42 }; set_status_flags(1234, flags);

    // Function pointer usage
    DataRecord_t recA = {"Alpha", 10, 100.0f};
    DataRecord_t recB = {"Beta", 20, 50.0f};

    printf("Comparing records by ID (recA vs recB): %d\n",
compare_records(&recA, &recB, compare_records_by_id)); printf("Comparing records
by Value (recA vs recB): %d\n", compare_records(&recA, &recB,
compare_records_by_value));

    // Variadic function usage
    print_variadic_integers(3, 10, 20, 30);
    print_variadic_integers(5, 1, 2, 3, 4, 5);

    // Cleanup module
    module_cleanup();

    printf("--- End of Demonstration ---\n");
    return EXIT_SUCCESS;
}
*/
