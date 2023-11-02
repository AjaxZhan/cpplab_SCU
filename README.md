## Introduction

This is a lab in the data structure and algorithm course of SCU, which realizes the analysis and operation of mathematical expressions using C++.

Since I seldom write C++ programs, I especially welcome suggestions from all walks of life for this small project.

## Environment And Dependencies

- Language: C++11
- OS: Ubuntu22.04
- Hardware Environment: AMD
- Compiler: g++
- Build tools: CMake
- IDE: VsCode
- Version Control: Git
- Debug : gdb

## Project Structure

In this project, I used an MVC-like development model to divide the project into the following modules.

```
├─controller                     // Controller
│       └── UIController.cpp            // Interact with User
├─doc                            // Some doc that may help
├─includes                       // The .h file
│       └── Enum.h                      // Constant
│       └── Expression.h                
│       └── MathService.h               
│       └── Stack.h                     // Self-implementation stack. Course Requirements:
│       └── UIController.h              
├─service                        // Core function
│       └── Expression.cpp              //  Expression parsing and evaluation
│       └── MathService.cpp             //  Encapsulation of mathematical calculations
├─target                         // The packaged program
├─test                           // Some simple unit test.
├─CalApplication.cpp             // Entry file
├─.gitignore                     // gitignore file
├─README.md                      // Document
```

## Run 

### use g++ directly

If you are a Windows user, please change `app.out` to `app.exe`.

```shell
g++ -I/includes/ CalApplication.cpp ./controller/UIController.cpp services/*.cpp -o ./target/app.out -std=c++11
.target/app.out
```

### use cmake

You can try it yourself.

```shell
mkdir build
cd build
cmake ..
make
```

run:
```shell
cd ..
./target/app
```

## Todo

- [x] Building Project using CMake



## Pits I've Stepped On

1. template in cplusplus: The template class **cannot be split into two files**, and an error will be reported!
2. Confusing stk and vector causes a memory leak.
