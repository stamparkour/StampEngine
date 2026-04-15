include(FetchContent)

#source files
set(STAMP_REFLECT_SOURCES
)
set(STAMP_REFLECT_HEADERS
	"include/stamp/reflect/reflect.h"
	"include/stamp/reflect/reflect_traits.h" 
	"include/stamp/reflect/reflect_helpers.h"
	"include/stamp/reflect/reflect_ctypes.h"
	"include/stamp/reflect/string_literal.h"
	"include/stamp/reflect/meta_tuple.h"
	"include/stamp/reflect/view/view.h"
	 

	"include/stamp/reflect/std/reflect_std.h" 
	"include/stamp/reflect/std/reflect_vector.h" 
	"include/stamp/reflect/std/reflect_array.h"
	"include/stamp/reflect/std/reflect_iterator.h"

	"include/stamp/reflect/reflect_types.h"
	"include/stamp/reflect/types/property.h"
	"include/stamp/reflect/types/function.h"
	"include/stamp/reflect/types/operator.h"
	"include/stamp/reflect/types/constructor.h"
	"include/stamp/reflect/types/iterator.h"
	"include/stamp/reflect/types/tag.h"

	"include/stamp/reflect/view/view_handle.h" 
	"include/stamp/reflect/view/default_view_desc.h"
	"include/stamp/reflect/view/view_handle_impl.h"
 "include/stamp/reflect/attributes/attributes.h")

# add the library
add_library(stamp_reflect INTERFACE ${STAMP_REFLECT_SOURCES} ${STAMP_REFLECT_HEADERS})
add_library(stamp::reflect ALIAS stamp_reflect)
target_link_libraries(stamp_reflect)
target_compile_features(stamp_reflect INTERFACE cxx_std_20)


# adds a directory to search when finding header files
target_include_directories(stamp_reflect 
	INTERFACE "include" 
)
