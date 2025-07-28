#ifndef NONNULLPTR_H
#define NONNULLPTR_H

#include "excludevalue.h"

template<typename T>
using NonNullPtr = ExcludeValue<T*, nullptr>;

#endif // NONNULLPTR_H
