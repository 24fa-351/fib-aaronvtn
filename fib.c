#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long unsigned int recursive_fib(int r);

int main(int argc, char *argv[]) {
   if (argc != 4) {
      printf("Input error, program takes 3 parameters.\n");
      printf("Example:\n./fib 5 i filename.txt\n\n");
      exit(0);
   }

   if (atoi(argv[1]) <= 0) {
      printf("Input error, first argument must be a positive non-zero integer.\n");
      printf("Example:\n./fib 5 i filename.txt\n\n");
      exit(0);
   }
   int arg_int = atoi(argv[1]);

   if (strcmp(argv[2], "i") != 0 && strcmp(argv[2], "r") != 0) {
      printf("Input error, second argument must be i or r.\n");
      printf("Example:\n./fib 5 i filename.txt\n\n");
      exit(0);
   }
   char method = *argv[2];

   char file_int[100];
   FILE* file_pointer;

   file_pointer = fopen(argv[3], "r");

   if (file_pointer == NULL) {
      printf("File not found.\n");
      exit(0);
   }

   fread(file_int, sizeof(file_int), 1, file_pointer);
   int n = arg_int + atoi(file_int);
   fclose(file_pointer);

   unsigned long long int first_num = 0; // Seed values for fibonacci iterative method
   unsigned long long int second_num = 1;
   unsigned long long int sum;

   if (method == 'i') {
      // Iterative method to find Nth Fibonacci number
      for (int ix = 1; ix < n; ix++) {
         sum = first_num + second_num;
         second_num = first_num;
         first_num = sum;
      }
      printf("%llu\n", sum);
   }

   if (method == 'r') {
      printf("%llu\n", recursive_fib(n-1)); // n-1 so it behaves as 0, 1, 1, ..
   }

   return 0;
}

long long unsigned int recursive_fib(int r) {
   // Recursive method to find Nth Fibonacci number
   if (r <= 1) 
      return r;
   return recursive_fib(r - 1) + recursive_fib(r - 2);
}