# build_and_run.ps1

$buildDir = "build"

# Create build directory if it doesn't exist
if (!(Test-Path $buildDir)) {
    New-Item -ItemType Directory -Path $buildDir | Out-Null
}

# Configure with CMake using Visual Studio generator
cmake -S . -B $buildDir -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug

# Build the project (Debug configuration)
cmake --build $buildDir --config Debug

# Run the executable
$exePath = Join-Path $buildDir "Debug\Timber.exe"
if (Test-Path $exePath) {
    Start-Process $exePath
} else {
    Write-Host "Executable not found: $exePath"
}
