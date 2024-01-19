# CppMake - cpp build system
## Disclaimer

[TheReclif](https://github.com/TheReclif) is the original author behind the idea of CppMake.

`CppMake` is in the PoC phase of development. It is not advised to use in production.

## What is CppMake?

CppMake is build tool aimed to replace `CMake` for building `c++` projects.

## Requirements

To use `CppMake` you need `CMake >= 3.25` and `CMake` supported `c++` compiler installed.

## Basic usage

After installing `CppMake` as `CMake` package, copy contents of `example` directory to your project root and configure cmake project as normal.

## Examples

* [minimal example](example)

## How it works?

`CppMake` generates `CMake` files based on configuration defined in `build.cpp` in the root of the project.

## License

`CppMake` is distributed inder [MIT license](LICENSE)