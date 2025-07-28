#ifndef NONZERO_H
#define NONZERO_H

#include "excludevalue.h"

template<typename T>
using NonZero = ExcludeValue<T, 0>;

#endif // NONZERO_H
