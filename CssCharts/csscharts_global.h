#ifndef CSSCHARTS_GLOBAL_H
#define CSSCHARTS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CSSCHARTS_LIBRARY)
#  define CSSCHARTSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CSSCHARTSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CSSCHARTS_GLOBAL_H
