set(GALAXY_PREPROCESSOR_FLAGS
    "_CRT_SECURE_NO_WARNINGS"
    "_CRT_SECURE_NO_DEPRECATE"
    "_CRT_NONSTDC_NO_DEPRECATE"
    "_GLIBCXX_HAS_GTHREADS"
    "_GLIBCXX_USE_NANOSLEEP"
    "IMGUI_IMPL_OPENGL_LOADER_GLAD"
    "UNICODE"
    "_UNICODE"
    "AL_LIBTYPE_STATIC"
    "GLM_FORCE_XYZW_ONLY"
    "GLFW_INCLUDE_NONE"
    "STB_IMAGE_IMPLEMENTATION"
    "STB_IMAGE_WRITE_IMPLEMENTATION"
    "STB_IMAGE_RESIZE_IMPLEMENTATION"
    "STB_TILEMAP_EDITOR_IMPLEMENTATION"
    "STBI_ONLY_PNG"
    "STB_IMAGE_STATIC"
    "STB_IMAGE_WRITE_STATIC"
    "STB_IMAGE_RESIZE_STATIC"
    "SOL_CXX17_FEATURES"
    "_LIBCPP_ENABLE_NODISCARD"
)

set(GALAXY_PREPROCESSOR_FLAGS_DEBUG
    "${GALAXY_PREPROCESSOR_FLAGS}"
    "_DEBUG"
    "_LIBCPP_DEBUG"
    "_LIBCPP_ENABLE_THREAD_SAFETY_ANNOTATIONS"
)

set(GALAXY_PREPROCESSOR_FLAGS_RELEASE
    "${GALAXY_PREPROCESSOR_FLAGS}"
    "NDEBUG"
    "_LIBCPP_DISABLE_DEPRECATION_WARNINGS"
    "_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS"
)