# run as `bazel build engine; .\bazel-bin\engine.exe`

CPPOPTS = select({
    "@bazel_tools//src/conditions:windows": ["/std:c++latest"],
    "//conditions:default": [
        "-std=c++23",
        "-fcoroutines",
    ],
})

cc_binary(
    name = "engine",
    srcs = glob(["**/*.c*", "**/*.h*"]),
    copts = CPPOPTS,
    visibility = ["//visibility:public"],
    deps = [
        "@sdl2//:SDL2_lib",
        "@sdl-image//:SDL_Image-lib",
    ],
    local_defines = ["SDL_MAIN_HANDLED"],
)
