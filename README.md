# LLVM demo

Download the LLVM+Clang binaries for your system from http://llvm.org/releases/download.html. For OS X:

    wget http://llvm.org/releases/3.6.2/clang+llvm-3.6.2-x86_64-apple-darwin.tar.xz
    tar xf clang+llvm-3.6.2-x86_64-apple-darwin.tar.xz
    export PATH=$PWD/clang+llvm-3.6.2-x86_64-apple-darwin/bin:$PATH

## Run the factorial program

    clang test.c -o test
    ./test

## C to LLVM IR

    clang -c -emit-llvm -O0 test.c -o test.bc
    llvm-dis test.bc
    less test.ll

## LLVM IR to assembly

    llc -O0 test.bc -o test.s
    less test.s

    llc -O3 test.bc -o test-o3.s
    less test-o3.s

## Generate LLVM IR programmatically

    llc -march=cpp test.bc -o test-codegen.cpp
    clang++ `llvm-config --cxxflags --ldflags --libs core` test-codegen.cpp -o test-codegen
