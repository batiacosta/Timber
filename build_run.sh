set -e #Exit error

BUILD_DIR="build"
mkdir -p "$BUILD_DIR"


cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=DEBUG


cmake --build "$BUILD_DIR" --parallel

"$BUILD_DIR/Timber"
