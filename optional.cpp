#include "optional.h"

#include "nonzero.h"
#include "nonnullptr.h"

static_assert(sizeof(int) == sizeof(Optional<ExcludeValue<int, -1>>));

static_assert(sizeof(int) == sizeof(Optional<NonZero<int>>));

static_assert(sizeof(int*) == sizeof(Optional<NonNullPtr<int>>));
