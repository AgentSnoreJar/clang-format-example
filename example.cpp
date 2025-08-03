#include <iostream>
// IndentPPDirectives
#ifdef WIN32
#include <windows.h>
#endif
// SortIncludes : Never
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/write.hpp>
#include <map>
#include <string>
#include <vector>

#include "AnotherHeader.h"
#include "MyHeader.h"

// AlignConsecutiveMacros, true:
#define SHORT_NAME       42
#define LONGER_NAME      0x007f
#define EVEN_LONGER_NAME (2)
#define foo(x)           (x * x)
#define bar(y, z)        (y + z)
// AcrossComments, false
#define MAX_LEN 12

// AcrossEmptyLines, false
#define MAX_SIZE_OF_ARRAY 12

#define MAX_SIZE_OF_STRUCTS 12

// AlignConsecutiveDeclarations, false
int a = 1;
int somelongname = 2;
double c = 3;

int aaaa : 1;
int b    : 12;
int ccc  : 8;

int aaaa = 12;

float b = 23;  // AcrossEmptyLines, false
// AcrossComments, false
std::string ccc;

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
// BitFieldColonSpacingStyle: Both (one space on each side)
//                          : None (no spaces)
//                          : Before (space before : only)
//                          : After (space after : only)
// AlignConsecutiveBitFields
typedef struct
{
    unsigned int is_active  : 1;  // 1-bit field
    unsigned int error_code : 3;  // 3-bit field (0-7)
    unsigned int reserved   : 4;  // 4-bit field
    unsigned int user_id    : 5;  // 5-bit field

    // AcrossComments, false
    unsigned int unknown : 6;

    unsigned int unknown1 : 7;

    unsigned int unk2 : 8;  // AcrossEmptyLines
} StatusFlags_t;

// --- Function Pointers ---
typedef int (*ComparisonFunction_t)(const void *, const void *);

// --- Global Variable Declarations ---
extern int g_global_counter;
extern const char *g_module_version;

/* AlignEscapedNewlines
 *
 * Right
 * #define PPP   \
 *     int aaaa; \
 * 	   int b;    \
 *     int dddddddddd;
 *
 * DontAlign
 * #define A \
 *   int aaaa; \
 *   int b; \
 *   int dddddddddd;
 */
// Left
#define PPP   \
    int aaaa; \
    int b;    \
    int dddddddddd;

namespace LevelOneNamespace
{
namespace LevelTwoNamespace
{

struct AAAAAAAAAAAAAAAAAAAA
{
    // AlignConsecutiveDeclarations
    int a;
    int bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb;
    std::string cccccccccccccccccc;
};

// AlwaysBreakTemplateDeclarations
template <typename T>
T foo()
{}

template <typename T>
T foo(int aaaaaaaaaaaaaaaaaaaaa, int bbbbbbbbbbbbbbbbbbbbb)
{}

// AllowShortEnumsOnASingleLine
enum : unsigned int
{
    AA = 0,
    BB
} myEnum;

// SpaceBeforeInheritanceColon
class B : public E {
    // AccessModifierOffset: -2
  private:
    /* AlignArrayOfStructures: Left
    struct test demo[] =
    {
        {56, 23,    "hello"},
        {-1, 93463, "world"},
        {7,  5,     "!!"   }
    };

    AlignArrayOfStructures: Right
    struct test demo[] =
    {
        {56,    23, "hello"},
        {-1, 93463, "world"},
        { 7,     5,    "!!"}
    };
    */
    // AlignArrayOfStructures: Never
    struct AAAAAAAAAAAAAAAAAAAA test[3] = {
        {56, 23, "hello"},
        {-1, 93463, "world"},
        {7, 5, "!!"},
        {-127389258748574899430.345890283450, 29292993736736723,
         "its a mad mad mad mad mad mad mad mad mad mad mad mad mad mad mad mad mad "
         "mad mad mad mad mad mad mad mad mad mad mad mad mad mad mad mad mad world"},
    };

    /* AlignTrailingComments:
     * Kind: Always
     * OverEmptyLines: 0
     *
     * Leave
     * int a;    // comment
     * int ab;       // comment
     *
     * int abc;  // comment
     * int abcd;     // comment
     *
     * Always
     * int a;  // comment
     * int ab; // comment
     *
     * int abc;  // comment
     * int abcd; // comment
     *
     * Never
     * int a; // comment
     * int ab; // comment
     *
     * int abc; // comment
     * int abcd; // comment
     *
     * MaxEmptyLinesToKeep: 2
     * OverEmptyLines: 2
     * int a;      // all these
     *
     * int ab;     // comments are
     *
     *
     * int abcdef; // aligned
     *
     * MaxEmptyLinesToKeep: 2
     * OverEmptyLines: 1
     * int a;  // these are
     *
     * int ab; // aligned
     *
     *
     * int abcdef; // but this isn't
     */

    /* AlignTrailingComments:
     * Kind: Always
     * OverEmptyLines: 0
     */
    int a;   // comment
    int ab;  // comment

    int abc;   // comment
    int abcd;  // comment

    // AlignTrailingComments, AlignConsecutiveDeclarations, QualifierOrder,
    // QualifierAlignment, AlignTrailingComments
    static const char *variable;  // very important variable
    void *const *x = nullptr;     // not so important variable
    const char *anotherVariable;  // another comment
    int a = 1;                    // another variable
    // used for this, this, and that
    // AlignConsecutiveAssignments: false
    int longComplicatedName = 4;
    int b = 3;

    // AlignConsecutiveAssignments, AcrossEmptyLines: false
    int csjhlsdflksd = 126712632783;
    // AlignConsecutiveAssignments, AcrossComments: false
    int cksd = 126712632783;

    // AlignConsecutiveAssignments, AlignCompound
    // true:
    // a   &= 2;
    // bbb  = 2;
    // false:
    a &= 2;
    bbb = 2;

    // AlignConsecutiveAssignments, AlignFunctionPointers
    // true:
    // unsigned i;
    // int     &r;
    // int     *p;
    // int      (*f)();
    // false:
    unsigned i;
    int &r;
    int *p;
    int (*f)();

    // AlignConsecutiveAssignments, PadOperators
    // true:
    // a   >>= 2;
    // bbb   = 2;
    //
    // false:
    a = 2;
    bbb >>= 2;

  protected:
    // AlwaysBreakAfterReturnType, QualifierAlignment
    constexpr static inline int function(int a, int b) { return (a + b) / 2; }

    // AllowShortFunctionsOnASingleLine
    static bool shortFilter(AAAAAAAAAAAAAAAAAAAA v) { return v.a != 4; }

    // AllowShortFunctionsOnASingleLine
    void empty() {}

    // IndentWrappedFunctionNames
    std::map<std::basic_string<wchar_t>, std::vector<std::pair<char, int>>> func(AAAAAAAAAAAAAAAAAAAA *v);

  public:
    // SpaceBeforeCtorInitializerColon
    explicit B() : a(9) {};

    // PackConstructorInitializers
    explicit B(int _a, int _b, int _c, std::vector<std::string> str)
        : a(_a), b(_b), longComplicatedName(_c), anotherVariable(str[0].c_str())
    {
        // AllowShortIfStatementsOnASingleLine, SpaceBeforeParens
        if (_c) {
            anotherVariable = nullptr;
        }
        if (_a) {
            anotherVariable = "baz";
        } else {
            anotherVariable = "bar";
        }
    }

    // AllowAllParametersOfDeclarationOnNextLine: true, BinPackParameters: false, see BinPackArguments below for
    // examples AlignAfterOpenBracket: Align
    // UseTabs: AlignWithSpaces
    int myFunction(int aaaaaaaaaaaaa, int bbbbbbbbbbbbbbbbbbbbbbb, int ccccccccccccc, int d, int e, int fffffffff,
                   int ggggggggggggggg, int hhhhhhhhhhhhhhhhhhhhhhhhhh, int i)
    {
        int myvar = aaaaaaaaaaaaa / 10;
        long anothervar = d % 2;
        // comment
        char *msg = "Hello all";

        /* AlignOperands
         *
         * BreakBeforeBinaryOperators
         * int aaa = bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
         *           + cccccccccccccccccccccccccccccccccccccccccccccccc;
         *
         * AlignAfterOperator
         * int aaa = bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
         *         + cccccccccccccccccccccccccccccccccccccccccccccccc;
         */
        // Align
        int aaa = bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb +
                  cccccccccccccccccccccccccccccccccccccccccccccccc;
        myvar = bbbbbbbbbbbbbbbbbbbbbbb + ccccccccccccc + aaaaaaaaaaaaa + hhhhhhhhhhhhhhhhhhhhhhhhhh +
                ggggggggggggggg * (hhhhhhhhhhhhhhhhhhhhhhhhhh + ccccccccccccc);

        // AllowShortCaseLabelsOnASingleLine, false
        // SpaceBeforeParens
        switch (e) {
            case 1:
                return e;
            case 2:
                return 2;
            case 3:
                return 3;
            default:
                return "";
        };

        // AllowShortBlocksOnASingleLine, Empty
        // AllowShortLoopsOnASingleLine: false
        // SpaceBeforeParens
        while (true) {}
        while (true) {
            continue;
        }
    }

    // AlignAfterOpenBracket, BinPackParameters,
    void loooongFunctionIsVeryLongButNotAsLongAsJavaTypeNames(const std::vector<AAAAAAAAAAAAAAAAAAAA> &inputVector,
                                                              std::map<int, std::string> *outputMap)
    {
        std::vector<AAAAAAAAAAAAAAAAAAAA> bar;
        std::copy_if(inputVector.begin(), inputVector.end(), std::back_inserter(bar), &shortFilter);
        // AllowShortLambdasOnASingleLine
        std::sort(inputVector.begin(), inputVector.end(), [](auto v) { return v.a < v.b; });
        std::transform(inputVector.begin(), inputVector.end(), std::inserter(*outputMap, outputMap->end()),
                       [](const AAAAAAAAAAAAAAAAAAAA &element) {
                           // LambdaBodyIndentation
                           return std::make_pair(element.bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb,
                                                 element.cccccccccccccccccc);
                       });
    };

    int notInline(AAAAAAAAAAAAAAAAAAAA *v);
};

// AllowShortFunctionsOnASingleLine : Empty
int notInline(AAAAAAAAAAAAAAAAAAAA *v) { return v->a + 1; }

}  // namespace LevelTwoNamespace
}  // namespace LevelOneNamespace

int main()
{
    // ReflowComments
    // veryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryLongComment with plenty of information to run over a single line that
    // is 120 characters long
    /* second veryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryLongComment with plenty of information to run over a single
     * line that is 120 characters long */

    // SortUsingDeclarations
    using std::cin;
    using std::cout;

    int aaaaaaaaaaaaaaaaaaa, bbbbbbbbbbb, ppppppppppp, eeeee;
    int fffffffff, ggggggggggggggg, hhhhhhhhhhhhhhhhhhhhhhhhhh, i;
    // AlignConsecutiveAssignments
    aaaaaaaaaaaaaaaaaaa = 6;
    bbbbbbbbbbb = 5;
    ppppppppppp = 10;
    LevelOneNamespace::LevelTwoNamespace::B b{
        1, 3, 4,
        // SpaceBeforeCpp11BracedList: false
        std::vector<std::string>{"aaaaaaaaaaaaaaaa", "bbbbbbbbbbbbbbbbbbbbbb", "cccccccccccccccccccccccccccc"}};
    // AllowShortLoopsOnASingleLine: false
    for (int i = 0; i < 10; i++) {
        cout << i;
    }
    LevelOneNamespace::LevelTwoNamespace::AAAAAAAAAAAAAAAAAAAA ddddddddddddddddddddddddd{5, 5, "ff"};
    b.notInline(ddddddddddddddddddddddddd);
    // SpaceAfterCStyleCast, AllowAllArgumentsOnNextLine: true, BinPackArguments: false
    cout << (bool)b.myFunction(aaaaaaaaaaaaaaaaaaa, bbbbbbbbbbb, ppppppppppp, eeeee, 0, fffffffff, ggggggggggggggg,
                               hhhhhhhhhhhhhhhhhhhhhhhhhh, i);
    /* AllowAllArgumentsOnNextLine: true, BinPackArguments: true
     * cout << (bool)b.myFunction(aaaaaaaaaaaaaaaaaaa, bbbbbbbbbbb, ppppppppppp, eeeee, 0, fffffffff, ggggggggggggggg,
     *                            hhhhhhhhhhhhhhhhhhhhhhhhhh, i);
     */

    /* AllowAllArgumentsOnNextLine: false, BinPackArguments: true
     * cout << (bool)b.myFunction(aaaaaaaaaaaaaaaaaaa, bbbbbbbbbbb, ppppppppppp, eeeee, 0, fffffffff, ggggggggggggggg,
     *                            hhhhhhhhhhhhhhhhhhhhhhhhhh, i);
     */

    /* AllowAllArgumentsOnNextLine: false, BinPackArguments: false
     * cout << (bool)b.myFunction(aaaaaaaaaaaaaaaaaaa,
     *                            bbbbbbbbbbb,
     *                            ppppppppppp,
     *                            eeeee,
     *                            0,
     *                            fffffffff,
     *                            ggggggggggggggg,
     *                            hhhhhhhhhhhhhhhhhhhhhhhhhh,
     *                            i);
     */

    return 0;
}
