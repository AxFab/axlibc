#include <ctype.h>

#define CTYPE_ALPHA     0x001
#define CTYPE_BLANK     0x002
#define CTYPE_CNTRL     0x004
#define CTYPE_GRAPH     0x008
#define CTYPE_PUNCT     0x010
#define CTYPE_SPACE     0x020
#define CTYPE_LOWER     0x040
#define CTYPE_UPPER     0x080
#define CTYPE_DIGIT     0x100
#define CTYPE_XDIGT     0x200

typedef struct axCinfo axCinfo_t;
struct axCinfo
{
  uint16_t  _flags;
  char      _lower;
  char      _upper;
};

typedef struct axLocale axLocale_t;
struct axLocale
{
  axCinfo_t   _ctype[256];
};


// ==========================================================================

int isalnum (int c);  /**< checks for an alphanumeric character */
int isalpha (int c);  /**< checks for an alphabetic character */
int isblank (int c);  /**< checks for a blank character */
int iscntrl (int c);  /**< checks for a control character */
int isdigit (int c);  /**< checks for a digit (0 through 9) */
int isgraph (int c);  /** checks for any printable character except space */
int islower (int c);  /** checks for a lowercase character */
int isprint (int c);  /** checks for any printable character including space */
int ispunct (int c);  /** checks for any printable character which is not a space or an alphanumeric character */
int isspace (int c);  /**< checks for white-space characters */
int isupper (int c);  /**< checks for an uppercase letter */
int isxdigit (int c); /**< checks for hexadecimal digits */
int tolower (int c);  /** convert to lowercase */
int toupper (int c);  /** convert to uppercase */

// ===========================================================================

int isalnum_l (int c, locale_t locale);   /**< checks for an alphanumeric character */
int isalpha_l (int c, locale_t locale);   /**< checks for an alphabetic character */
int isblank_l (int c, locale_t locale);   /**< checks for a blank character */
int iscntrl_l (int c, locale_t locale);   /**< checks for a control character */
int isdigit_l (int c, locale_t locale);   /**< checks for a digit (0 through 9) */
int isgraph_l (int c, locale_t locale);   /** checks for any printable character except space */
int islower_l (int c, locale_t locale);   /** checks for a lowercase character */
int isprint_l (int c, locale_t locale);   /** checks for any printable character including space */
int ispunct_l (int c, locale_t locale);   /** checks for any printable character which is not a space or an alphanumeric character */
int isspace_l (int c, locale_t locale);   /**< checks for white-space characters */
int isupper_l (int c, locale_t locale);   /**< checks for an uppercase letter */
int isxdigit_l (int c, locale_t locale);  /**< checks for hexadecimal digits */
int tolower_l (int c, locale_t locale);   /** convert to lowercase */
int toupper_l (int c, locale_t locale);   /** convert to uppercase */

