# build_and_run.ps1

$buildDir = "build"

# Create build directory if it doesn't exist
if (!(Test-Path $buildDir)) {
    New-Item -ItemType Directory -Path $buildDir | Out-Null
}

# Configure with CMake
cmake -S . -B $buildDir -G "Ninja" -DCMAKE_BUILD_TYPE=Debug

# Build the project
cmake --build $buildDir --parallel

# Run the executable
Start-Process "$buildDir\Timber.exe"
