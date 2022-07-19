/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <EventGenerator.h> header file. */
#define HAVE_EVENTGENERATOR_H 1

/* Define if GCC visibility extensions are supported */
/* #undef HAVE_GCC_VISIBILITY_EXTS */

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if you have the `getopt_long' function. */
#define HAVE_GETOPT_LONG 1

/* Defined if libxml++ is available */
#define HAVE_ICONV 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Defined if libxml++ is available */
/* #undef HAVE_LIBXMLPP */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <ParserEventGeneratorKit.h> header file. */
#define HAVE_PARSEREVENTGENERATORKIT_H 1

/* Define to 1 if you have the <SGMLApplication.h> header file. */
#define HAVE_SGMLAPPLICATION_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

// Do not exist
#undef HAVE_DLFCN_H
#undef HAVE_GETOPT_H
#undef HAVE_GETOPT_LONG
#undef HAVE_INTTYPES_H
#undef HAVE_STDINT_H
#undef HAVE_STRINGS_H
#undef HAVE_UNISTD_H


// Unsure
#define HAVE_ICONV 1
#define HAVE_LIBXMLPP 1

#undef LIBCURL_FEATURE_ASYNCHDNS

/* Defined if libcurl supports IPv6 */
#undef LIBCURL_FEATURE_IPV6

/* Defined if libcurl supports KRB4 */
#undef LIBCURL_FEATURE_KRB4

/* Defined if libcurl supports libz */
#undef LIBCURL_FEATURE_LIBZ

/* Defined if libcurl supports SSL */
#undef LIBCURL_FEATURE_SSL

/* Defined if libcurl supports DICT */
#undef LIBCURL_PROTOCOL_DICT

/* Defined if libcurl supports FILE */
#undef LIBCURL_PROTOCOL_FILE

/* Defined if libcurl supports FTP */
#undef LIBCURL_PROTOCOL_FTP

/* Defined if libcurl supports FTPS */
#undef LIBCURL_PROTOCOL_FTPS

/* Defined if libcurl supports GOPHER */
#undef LIBCURL_PROTOCOL_GOPHER

/* Defined if libcurl supports HTTP */
#undef LIBCURL_PROTOCOL_HTTP

/* Defined if libcurl supports HTTPS */
#undef LIBCURL_PROTOCOL_HTTPS

/* Defined if libcurl supports LDAP */
#undef LIBCURL_PROTOCOL_LDAP

/* Defined if libcurl supports TELNET */
#undef LIBCURL_PROTOCOL_TELNET


// MSVC Defines we seem to need
#ifdef _MSC_VER
typedef int ssize_t;
#endif
