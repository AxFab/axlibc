#ifndef LOCALE_H__
#define LOCALE_H__

/** @file locale.h
 * @brief category macros
 * @version C89, C99, IEEE, Unix95, Unix98, POSIX, XSI
 *
 * The <locale.h> header provides a definition for structure lconv. (See the
 * definitions of LC_MONETARY in the XBD specification, LC_MONETARY , and the
 * XBD specification, LC_NUMERIC .)
 * The <locale.h> header defines NULL (as defined in <stddef.h>) and at least
 * the following as macros which expand to distinct integral-constant
 * expressions, for use as the first argument to the setlocale() function.
 * Additional macro definitions, beginning with the characters LC_ and an
 * upper-case letter, may also be given here.
 * The following are declared as functions and may also be defined as macros.
 * Function prototypes must be provided for use with an ISO C compiler.
 */

#include <stddef.h>

__AXLIBC_BEG

// ===========================================================================
/** */
#define LC_ALL        1

/** Affects the behaviour of regular expressions and the collation functions */
#define LC_COLLATE    2

/** Affects the behaviour of regular expressions, character classification,
 * character conversion functions and wide-character functions. */
#define LC_CTYPE      3

/** Affects what strings are expected by commands and utilities as affirmative
 * or negative responses, what strings are given by commands and utilities as
 * affirmative or negative responses, and the content of messages.
 */
#define LC_MESSAGES   4

/** Affects the behaviour of functions that handle monetary values.
 */
#define LC_MONETARY   5

/** Affects the radix character for the formatted input/output functions and
 * the string conversion functions.
 */
#define LC_NUMERIC    6

/** Affects the behaviour of the time conversion functions.
 */
#define LC_TIME       7


// ===========================================================================
struct lcov
{
char    *currency_symbol;     /**< The local currency symbol applicable to the current locale. */
char    *decimal_point;       /**< The radix character used to format non-monetary quantities. */
char     frac_digits;         /**< The number of fractional digits (those after the decimal-point) to be displayed in a formatted monetary quantity. */
char    *grouping;            /**< A string whose elements taken as one-byte integer values indicate the size of each group of digits in formatted non-monetary quantities. */
char    *int_curr_symbol;     /**< The international currency symbol applicable to the current locale. The first three characters contain the alphabetic international currency symbol in accordance with those specified in the . The fourth character (immediately preceding the null byte) is the character used to separate the international currency symbol from the monetary quantity. */
char     int_frac_digits;     /**< The number of fractional digits (those after the decimal-point) to be displayed in an internationally formatted monetary quantity. */
char    *mon_decimal_point;   /**< The radix character used to format monetary quantities. */
char    *mon_grouping;        /**< A string whose elements taken as one-byte integer values indicate the size of each group of digits in formatted monetary quantities. */
char    *mon_thousands_sep;   /**< The separator for groups of digits before the decimal-point in formatted monetary quantities. */
char    *negative_sign;       /**< The string used to indicate a negative valued formatted monetary quantity. */
char     n_cs_precedes;       /**< Set to 1 if the currency_symbol  or int_curr_symbol  precedes the value for a negative formatted monetary quantity. Set to 0 if the symbol succeeds the value. */
char     n_sep_by_space;      /**< Set to 0 if no space separates the currency_symbol  or int_curr_symbol from the value for a negative formatted monetary quantity. Set to 1 if a space separates the symbol from the value;  and set to 2 if a space separates the symbol and the sign string, if adjacent. */
char     n_sign_posn;         /**< Set to a value indicating the positioning of the negative_sign for a negative formatted monetary quantity. */
char    *positive_sign;       /**< The string used to indicate a non-negative valued formatted monetary quantity. */
char     p_cs_precedes;       /**< Set to 1 if the currency_symbol  or int_curr_symbol  precedes the value for a non-negative formatted monetary quantity. Set to 0 if the symbol succeeds the value. */
char     p_sep_by_space;      /**< Set to 0 if no space separates the currency_symbol  or int_curr_symbol from the value for a non-negative formatted monetary quantity. Set to 1 if a space separates the symbol from the value;  and set to 2 if a space separates the symbol and the sign string, if adjacent. */
char     p_sign_posn;         /**< Set to a value indicating the positioning of the positive_sign for a non-negative formatted monetary quantity. */
char    *thousands_sep;       /**< The character used to separate groups of digits before the decimal-point character in formatted non-monetary quantities. */
};


// ===========================================================================
/**
 * The localeconv() function sets the components of an object with the type
 * struct lconv with the values appropriate for the formatting of numeric
 * quantities (monetary and otherwise) according to the rules of the current
 * locale.
 * @return A pointer to the filled-in object. The structure pointed to by the
 * return value must not be modified by the program, but may be overwritten by
 * a subsequent call to localeconv(). In addition, calls to setlocale() with
 * the categories LC_ALL, LC_MONETARY, or LC_NUMERIC may overwrite the contents
 * of the structure.
 */
struct lconv* localeconv(void);

/**
 * The setlocale() function selects the appropriate piece of the program's
 * locale, as specified by the category and locale arguments, and may be used
 * to change or query the program's entire locale or portions thereof. The
 * value LC_ALL for category names the program's entire locale; other values
 * for category name only a part of the program's locale
 */
char setlocale(int category, const char *locale);


__AXLIBC_END

#endif /* LOCALE_H__ */
