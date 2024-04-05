workspace(name = "ninja_alex_ahouldvedonec")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

git_repository(
    name = "sdl2",
    commit = "1e5f94490568dde3ef12fd4e884c264486f26260",  # v??
    remote = "https://github.com/mason-bially/sdl2",
    shallow_since = "1712336631 -0700",
)

new_git_repository(
    name = "sdl-image",
    commit = "2f47e3457fd0387ccd8400cf1a63a8f8d29f3fd3",
    remote = "https://github.com/libsdl-org/SDL_image",
    build_file_content = """
cc_library(
    name = "SDL_Image-headers",
    hdrs = glob(["include/**/*.h*"]),
	strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SDL_Image-lib",
    srcs = glob(["src/**/*.c"]),
    hdrs = glob(["include/**/*.h*"]),
	strip_include_prefix = "include",
    include_prefix = "SDL2",

    deps = [
        "@sdl2//:SDL2_hdrs",
        ":SDL_Image-headers",
    ],

    alwayslink = True,
    #linkopts = SDL_LINKOPTS,

    #local_defines = SDL_LOCALDEFINES,
    visibility = ["//visibility:public"],
)
    """
)