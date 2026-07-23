# 2048 rogue like using pygame.

## About

2048Py(Title pending) is a pre-alpha cozy-vibe rogue-like 2048 clone, it includes; passive abilities, power-ups, player obstructions, and other cool little touches that will hopefully make the game feel like more than just 2048.

## Goals

My goals for the game include however not limited to;

- At least five enemey-like obstructions.
- Fifty passive effects.
- Twenty power-ups.

![](sample/sample0.png)
![](sample/sample1.png)
![](sample/sample2.png)
![](sample/sample3.png)

## Prerequisites

- Python 3.10+
- A C++ compiler (g++ on Linux, MSVC on Windows)
- CMake

Optionally set the `NATIVE_WIDTH` & `NATIVE_HEIGHT` variables in `src/main.py` to your native resolution — they choose the requested fullscreen mode. Mouse input adapts to whatever window the system actually creates, so this is not required for the game to work.

## Linux

```bash
# Install system dependencies (Debian/Ubuntu)
sudo apt install python3 python3-pip python3-venv cmake g++

# Install system dependencies (Arch)
sudo pacman -S python python-pip cmake gcc

# Create venv and install Python dependencies
python3 -m venv src/venv
src/venv/bin/pip install pygame moderngl numpy pybind11 cmake

# Build the C++ engine
bash compile.sh

# Run
cd src

source venv/bin/activate.fish # Drop the fish if you are not using that shell or do not know what a shell is.

python3 main.py
```

> **fish shell:** `source src/venv/bin/activate` won't work — use `source src/venv/bin/activate.fish` or just invoke `src/venv/bin/python3` directly as shown above.

## Engine tests

The C++ engine has a headless pytest harness (determinism, invariant fuzzing, feature-interaction regression tests):

```bash
src/venv/bin/pip install pytest
src/venv/bin/python3 -m pytest tests/ -q
```

Tests marked `xfail` document known engine bugs; they flip to a loud failure once the bug is fixed.

## Windows

Install prerequisites:
- [Python 3.10+](https://www.python.org/downloads/) — check "Add Python to PATH" during install
- [Visual Studio Build Tools](https://visualstudio.microsoft.com/visual-cpp-build-tools/) — select the "Desktop development with C++" workload
- [CMake](https://cmake.org/download/)

```bat
REM Create venv and install Python dependencies
python -m venv src\venv
src\venv\Scripts\activate
pip install pygame-ce moderngl numpy pybind11 cmake

REM Build the C++ engine
compile.bat

REM Run
src\venv\Scripts\activate
python src\main.py
```

[^1]:
    Kudos to @SheviTGP for his help testing and improving Windows instructions.
[^1]
[^2]:
    Huge thanks to merionette for composing such great music.
[^2]
