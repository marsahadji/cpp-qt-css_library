#ifndef CSSSQL_GLOBAL_H
#define CSSSQL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CSSSQL_LIBRARY)
#  define CSSSQLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CSSSQLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CSSSQL_GLOBAL_H
