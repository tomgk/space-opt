#include "optional.h"

static_assert(sizeof(int) == sizeof(Optional<ExcludeValue<int, -1>>));
