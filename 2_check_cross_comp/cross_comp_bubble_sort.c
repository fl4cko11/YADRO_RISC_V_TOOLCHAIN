#include <stdlib.h>
#include <stdio.h>
// /home/vlados/riscv-toolchain/risc_v_gcc_linux/bin/riscv64-unknown-linux-gnu-gcc - gcc_linux
// /home/vlados/riscv-toolchain/risc_v_gcc_linux/sysroot - sysroot gcc_linux

// /home/vlados/riscv-toolchain/risc_v_gcc_newlib/bin/riscv64-unknown-elf-gcc - gcc_newlib

// /home/vlados/riscv-toolchain/llvm/llvm-project/build/bin/clang - clang (таргет явно указать, сисруты не надо)

int int_comparator(int a1, int a2) {
    return a1 > a2 ? 1 : 0;
}

int *int_swap(int *array, int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
    return array;  
}


int *bubble_sort(int *array, int len_array) {
    int i = 0;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int j = 0; j <= len_array - i - 2; j++) {
            if (int_comparator(array[j], array[j+1])) {
                array = int_swap(array, j, j+1);
                flag = 1;
            } 
        }
        i++;
    }
    return array;
}

int main() {
    int len_array = 3;
    int *array = (int *)malloc(len_array * sizeof(int));
    printf ("input %d int value: \n", len_array);
    for (int i = 0; i < len_array; i++) {
        printf ("input int value: ");
        while (scanf ("%d", &array[i]) != 1) {
            printf ("wrong value, try again");
        }
    }

    array = bubble_sort(array, len_array);
    printf("sorted array: ");
    for (int i = 0; i < len_array; i++) {
        printf ("%d ", array[i]);
    }
    return 0;
}