# IEEE Conference Backend

## Setup Instructions
```bash
conan profile detect --force
conan install . --output-folder=build --build=missing
cmake --preset conan-release
cmake --build --preset conan-release
```