# fujiwara by C Language
Estimation of Wind Forces and Moments Acting on Ships
This is a CLI that implements the methods described in fujiwara 2001

# Fujiwara: Estimation of Wind Forces and Moments Acting on Ships

This repository contains a C program for estimating wind forces and moments acting on ships. The program is based on the Fujiwara method, which is widely used in naval architecture for the prediction of aerodynamic forces and moments on ships.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Installation

To compile and run the program, you need to have a C compiler installed on your system. The following instructions assume you are using `gcc`, the GNU Compiler Collection.

1. Clone the repository:

    ```sh
    git clone https://github.com/snurudeen21/fujiwara.git
    cd fujiwara
    ```

2. Compile the program:

    ```sh
   gcc *.c -o nsh -lm
    ```

## Usage

The program reads input data from the i/o stream  and outputs the estimated coefficient of wind forces and moments at the attack angles The commands that run the code are discussed herein
```sh
##Launch the program by typing
.\nsh.exe on Windows
./nsh.exe on Linux

### Command Line Arguments
  ```sh
  angles start end step
  analyze L B HC HBR C CBR AT AL AOD
  plot  (takes no arguments)
  save file_name

### Example Command

```sh
angles 0 180 10
analyze 117 17.9 6.71 17.5 0.85 4.6 316 1337 451
plot
save rdi
