#ifndef CSSCORE_GLOBAL_H
#define CSSCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CSSCORE_LIBRARY)
#  define CSSCORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define CSSCORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CSSCORE_GLOBAL_H
