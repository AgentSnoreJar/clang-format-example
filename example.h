#ifndef MY_MODULE_H
#define MY_MODULE_H

#include <stdbool.h>  // For bool type (C99)
#include <stdio.h>    // For FILE, printf, etc.

// --- Preprocessor Directives ---
#define MAX_BUFFER_SIZE 256
#define PI              3.14159f

#ifdef DEBUG_MODE
#define DEBUG_PRINTF(...) fprintf(stderr, "DEBUG: " __VA_ARGS__)
#else
#define DEBUG_PRINTF(...)
#endif

// --- Enums ---
typedef enum
{
    STATUS_OK,
    STATUS_ERROR_INVALID_ARG,
    STATUS_ERROR_FILE_NOT_FOUND,
    STATUS_COUNT  // Used to determine the number of status codes
} ModuleStatus_t;

// --- Structs ---
typedef struct
{
    char name[MAX_BUFFER_SIZE];
    int id;
    float value;
} DataRecord_t;

// --- Unions ---
typedef union
{
    int int_val;
    float float_val;
    char char_val;
} MixedData_u;

// --- Struct with Bit-fields ---
typedef struct
{
    unsigned int is_active  : 1;  // 1-bit field
    unsigned int error_code : 3;  // 3-bit field (0-7)
    unsigned int reserved   : 4;  // 4-bit field
    unsigned int user_id    : 8;  // 8-bit field
} StatusFlags_t;

// AlignArrayOfStructures: Never
struct test demo[] = {{56, 23, "hello"}, {-1, 93463, "world"}, {7, 5, "!!"}};

// --- Function Pointers ---
typedef int (*ComparisonFunction_t)(const void *, const void *);

// --- Global Variable Declarations ---
extern int g_global_counter;
extern const char *g_module_version;

// --- Function Prototypes ---
/**
 * @brief Initializes the module's internal state.
 *
 * @param initial_value An initial integer value.
 * @return ModuleStatus_t STATUS_OK on success, or an error code.
 */
ModuleStatus_t module_init(int initial_value);

/**
 * @brief Processes a data record.
 *
 * This function takes a pointer to a DataRecord_t and performs some operations.
 *
 * @param record A pointer to the DataRecord_t to process.
 * @return int The processed record ID, or -1 on error.
 */
int process_data_record(DataRecord_t *record);

/**
 * @brief Performs a generic operation with different data types using a union.
 *
 * @param data A MixedData_u containing the data.
 * @param type An integer indicating the type of data (0 for int, 1 for float, 2
 * for char).
 * @return float The result of the operation.
 */
float perform_union_operation(MixedData_u data, int type);

/**
 * @brief Sets the status flags for a given ID.
 *
 * @param id The ID to set flags for.
 * @param flags The StatusFlags_t to apply.
 */
void set_status_flags(int id, StatusFlags_t flags);

/**
 * @brief Compares two DataRecord_t structures using a provided comparison
 * function.
 *
 * @param record1 Pointer to the first record.
 * @param record2 Pointer to the second record.
 * @param compare_func Function pointer to the comparison logic.
 * @return int Result of the comparison (negative if record1 < record2, 0 if
 * equal, positive if record1 > record2).
 */
int compare_records(const DataRecord_t *record1, const DataRecord_t *record2, ComparisonFunction_t compare_func);

/**
 * @brief Prints a variable number of integers to the console.
 *
 * This function uses variadic arguments (varargs) to print any number of
 * integers.
 *
 * @param count The number of integers to print.
 * @param ... The integers to print.
 */
void print_variadic_integers(int count, ...);

/**
 * @brief Cleans up any resources allocated by the module.
 */
void module_cleanup(void);

#endif  // MY_MODULE_H
