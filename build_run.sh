set -e #Exit error

BUILD_DIR="build"
EXECUTABLE="Timber"

UNAME_OUT="$(uname -s)"
case "${UNAME_OUT}" in
    Linux*|Darwin*)
        PLATFORM="unix"
        GENERATOR="Unix Makefiles"
        EXECUTABLE="./$BUILD_DIR/$EXECUTABLE"
        ;;
    MINGW* |MSYS*|CYGWIN*)
        PLATFORM="windows"
        GENERATOR="Ninja"
        EXECUTABLE="./$BUILD_DIR/$EXECUTABLE.exe"
        ;;
    *)
        echo "Unsupported platform: ${UNAME_OUT}"
        exit 1
        ;;
esac

echo "Detected platform: $PLATFORM"
echo "Using generator: $GENERATOR"

mkdir -p "$BUILD_DIR"

cmake -S . -B "$BUILD_DIR" -G "$GENERATOR" -DCMAKE_BUILD_TYPE=DEBUG

cmake --build "$BUILD_DIR" --parallel

echo "Running: $EXECUTABLE"
"$EXECUTABLE"
