# Create bin directory if it doesn't exist
if (-Not (Test-Path -Path .\bin)) {
    New-Item -ItemType Directory -Path .\bin
}

# Check if g++ is installed
$gpp = Get-Command g++ -ErrorAction SilentlyContinue
if (-Not $gpp) {
    Write-Host "g++ not found. Please install g++ and try again."
    exit 1
}

# Compile C++ files
& g++ ./src/*.cpp -o ./bin/csc10004_SortingAlgo_win32_x86_64

# Check if the compilation was successful
if ($LASTEXITCODE -ne 0) {
    Write-Host "Compilation failed."
    exit $LASTEXITCODE
}

# Print the contents of the bin directory
Write-Host "Building complete"
