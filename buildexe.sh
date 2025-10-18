#!/bin/bash

# Ensure Wine is installed
command -v wine >/dev/null 2>&1 || { echo "Wine is not installed. Run: sudo apt install wine"; exit 1; }

# Set up Wine prefix
export WINEPREFIX="$HOME/.wine_pyinstaller"

# Download Windows Python installer if missing
if [ ! -f python-installer.exe ]; then
    echo "Downloading Windows Python installer..."
    wget https://www.python.org/ftp/python/3.11.6/python-3.11.6-amd64.exe -O python-installer.exe
fi

# Install Python inside Wine
wine python-installer.exe /quiet InstallAllUsers=1 PrependPath=1 Include_pip=1

# Install PyInstaller inside Wine
wine pip install pyinstaller

# Build the .exe
echo "Building your .exe..."
wine pyinstaller --onefile --noconsole "$1"

echo "Done. Check dist/ for your .exe"
