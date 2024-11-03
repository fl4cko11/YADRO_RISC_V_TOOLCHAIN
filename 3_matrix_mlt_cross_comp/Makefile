matrix_mlt_x86_64: matrix_mlt_x86_64_funcs.o matrix_mlt_x86_64_main.o
	gcc matrix_mlt_x86_64_funcs.o matrix_mlt_x86_64_main.o -o matrix_mlt_x86_64

matrix_mlt_RISC_V_LINUX_GCC: matrix_mlt_RISC_V_LINUX_GCC_funcs.o matrix_mlt_RISC_V_LINUX_GCC_main.o
	/home/vlados/riscv-toolchain/risc_v_gcc_linux/bin/riscv64-unknown-linux-gnu-gcc matrix_mlt_RISC_V_LINUX_GCC_funcs.o matrix_mlt_RISC_V_LINUX_GCC_main.o -o matrix_mlt_RISC_V_LINUX_GCC

matrix_mlt_RISC_V_NEWLIB_GCC: matrix_mlt_RISC_V_NEWLIB_GCC_funcs.o matrix_mlt_RISC_V_NEWLIB_GCC_main.o
	/home/vlados/riscv-toolchain/risc_v_gcc_newlib/bin/riscv64-unknown-elf-gcc matrix_mlt_RISC_V_NEWLIB_GCC_funcs.o matrix_mlt_RISC_V_NEWLIB_GCC_main.o -o matrix_mlt_RISC_V_NEWLIB_GCC

matrix_mlt_RISC_V_LINUX_CLANG: matrix_mlt_RISC_V_LINUX_CLANG_funcs.o matrix_mlt_RISC_V_LINUX_CLANG_main.o
	/home/vlados/riscv-toolchain/llvm/llvm-project/build/bin/clang -target riscv64-unknown-linux-gnu matrix_mlt_RISC_V_LINUX_CLANG_funcs.o matrix_mlt_RISC_V_LINUX_CLANG_main.o -o matrix_mlt_RISC_V_LINUX_CLANG

matrix_mlt_x86_64_funcs.o: matrix_mlt_funcs.c
	gcc -c matrix_mlt_funcs.c -o matrix_mlt_x86_64_funcs.o

matrix_mlt_x86_64_main.o: matrix_mlt_main.c
	gcc -c matrix_mlt_main.c -o matrix_mlt_x86_64_main.o

matrix_mlt_RISC_V_LINUX_GCC_funcs.o: matrix_mlt_funcs.c
	/home/vlados/riscv-toolchain/risc_v_gcc_linux/bin/riscv64-unknown-linux-gnu-gcc -c matrix_mlt_funcs.c -o matrix_mlt_RISC_V_LINUX_GCC_funcs.o

matrix_mlt_RISC_V_LINUX_GCC_main.o: matrix_mlt_main.c
	/home/vlados/riscv-toolchain/risc_v_gcc_linux/bin/riscv64-unknown-linux-gnu-gcc -c matrix_mlt_main.c -o matrix_mlt_RISC_V_LINUX_GCC_main.o

matrix_mlt_RISC_V_NEWLIB_GCC_funcs.o: matrix_mlt_funcs.c
	/home/vlados/riscv-toolchain/risc_v_gcc_newlib/bin/riscv64-unknown-elf-gcc -c matrix_mlt_funcs.c -o matrix_mlt_RISC_V_NEWLIB_GCC_funcs.o

matrix_mlt_RISC_V_NEWLIB_GCC_main.o: matrix_mlt_main.c
	/home/vlados/riscv-toolchain/risc_v_gcc_newlib/bin/riscv64-unknown-elf-gcc -c matrix_mlt_main.c -o matrix_mlt_RISC_V_NEWLIB_GCC_main.o

matrix_mlt_RISC_V_LINUX_CLANG_funcs.o: matrix_mlt_funcs.c
	/home/vlados/riscv-toolchain/llvm/llvm-project/build/bin/clang -target riscv64-unknown-linux-gnu -c matrix_mlt_funcs.c -o matrix_mlt_RISC_V_LINUX_CLANG_funcs.o

matrix_mlt_RISC_V_LINUX_CLANG_main.o: matrix_mlt_main.c
	/home/vlados/riscv-toolchain/llvm/llvm-project/build/bin/clang -target riscv64-unknown-linux-gnu -c matrix_mlt_main.c -o matrix_mlt_RISC_V_LINUX_CLANG_main.o

clean:
	rm -f *.o matrix_mlt_x86_64 matrix_mlt_RISC_V_LINUX_GCC matrix_mlt_RISC_V_NEWLIB_GCC matrix_mlt_RISC_V_LINUX_CLANG