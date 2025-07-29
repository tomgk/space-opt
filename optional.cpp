#include "optional.h"

#include "nonzero.h"
#include "nonnullptr.h"

static_assert(sizeof(int) == sizeof(Optional<ExcludeValue<int, -1>>));

static_assert(sizeof(int) == sizeof(Optional<NonZero<int>>));

static_assert(sizeof(int*) == sizeof(Optional<NonNullPtr<int>>));

//static_assert(sizeof(sizeof(std::string_view)) == sizeof(Optional<std::string_view>));

const char *EMPTY_STRING_VIEW()
{
    static const char *DATA = "5e8f801b-e83b-4d8c-ad57-cae0197d6670";
    return DATA;
}

static void useOptionalStringView()
{
    Optional<std::string_view> a;
}
