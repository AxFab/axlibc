#include <ctype.h>

// ==========================================================================
/** checks for an alphanumeric character */
int isalnum (int c)
{
  return _getLocale()->_ctype[c]._flags & ( CTYPE_ALPHA | CTYPE_DIGIT );
}

/** checks for an alphabetic character */
int isalpha (int c)
{
  return _getLocale()->_ctype[c]._flags & CTYPE_ALPHA;
}

/** checks for a blank character */
int isblank (int c)
{
  return _getLocale()->_ctype[c]._flags & CTYPE_BLANK;
}

/** checks for a control character */
int iscntrl (int c)
{
  return _getLocale()->_ctype[c]._flags & CTYPE_CNTRL;
}

/** checks for a digit (0 through 9) */
int isdigit (int c)
{
  return _getLocale()->_ctype[c]._flags & CTYPE_DIGIT;
}

/** checks for any printable character except space */
int isgraph (int c)
{
  return _getLocale()->_ctype[c]._flags & CTYPE_GRAPH;
}

/** checks for a lowercase character */
int islower (int c)
{
  return _getLocale()->_ctype[c]._flags & CTYPE_LOWER;
}

/** checks for any printable character including space */
int isprint (int c)
{
  return (_getLocale()->_ctype[c]._flags & CTYPE_GRAPH ) || ( c == ' ' );
}

/** checks for any printable character which is not a space or an alphanumeric 
 * character */
int ispunct (int c)
{
  return _getLocale()->_ctype[c]._flags & CTYPE_PUNCT;
}

/** checks for white-space characters */
int isspace (int c)
{
  return _getLocale()->_ctype[c]._flags & CTYPE_SPACE;
}

/** checks for an uppercase letter */
int isupper (int c)
{
  return _getLocale()->_ctype[c]._flags & CTYPE_UPPER;
}

/** checks for hexadecimal digits */
int isxdigit (int c)
{
  return _getLocale()->_ctype[c]._flags & CTYPE_XDIGT;
}

/** convert to lowercase */
int tolower (int c)
{
  return _getLocale()->_ctype[c]._lower;
}

/** convert to uppercase */
int toupper (int c)
{
  return _getLocale()->_ctype[c]._upper;
}

// ===========================================================================

/** checks for an alphanumeric character */
int isalnum_l (int c, locale_t locale)
{
  return locale._ctype[c]._flags & ( CTYPE_ALPHA | CTYPE_DIGIT );
}

/** checks for an alphabetic character */
int isalpha_l (int c, locale_t locale)
{
  return locale._ctype[c]._flags & CTYPE_ALPHA;
}

/** checks for a blank character */
int isblank_l (int c, locale_t locale)
{
  return locale._ctype[c]._flags & CTYPE_BLANK;
}

/** checks for a control character */
int iscntrl_l (int c, locale_t locale)
{
  return locale._ctype[c]._flags & CTYPE_CNTRL;
}

/** checks for a digit (0 through 9) */
int isdigit_l (int c, locale_t locale)
{
  return locale._ctype[c]._flags & CTYPE_DIGIT;
}

/** checks for any printable character except space */
int isgraph_l (int c, locale_t locale)
{
  return locale._ctype[c]._flags & CTYPE_GRAPH;
}

/** checks for a lowercase character */
int islower_l (int c, locale_t locale)
{
  return locale._ctype[c]._flags & CTYPE_LOWER;
}

/** checks for any printable character including space */
int isprint_l (int c, locale_t locale)
{
  return (locale._ctype[c]._flags & CTYPE_GRAPH ) || ( c == ' ' );
}

/** checks for any printable character which is not a space or an alphanumeric 
 * character */
int ispunct_l (int c, locale_t locale)
{
  return locale._ctype[c]._flags & CTYPE_PUNCT;
}

/** checks for white-space characters */
int isspace_l (int c, locale_t locale)
{
  return locale._ctype[c]._flags & CTYPE_SPACE;
}

/** checks for an uppercase letter */
int isupper_l (int c, locale_t locale)
{
  return locale._ctype[c]._flags & CTYPE_UPPER;
}

/** checks for hexadecimal digits */
int isxdigit_l (int c, locale_t locale)
{
  return locale._ctype[c]._flags & CTYPE_XDIGT;
}

/** convert to lowercase */
int tolower_l (int c, locale_t locale)
{
  return locale._ctype[c]._lower;
}

/** convert to uppercase */
int toupper_l (int c, locale_t locale)
{
  return locale._ctype[c]._upper;
}

