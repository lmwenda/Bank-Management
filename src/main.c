#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char options[7][20] = {"View Menu", "New Account",    "New Transaction",
                       "View Transcations", "View Acccounts", "Edit Account"};

// creating new account
void new_account() {
    printf("\n \n Initializing new account... \n");
    struct Account new_account;

    // prompt information

    char *name = "sdfsdfsdfsdf";
    int phoneNumber;
    char *address = "sdfsdfsdfsf";

    char *ptr_name = &name;
    int *ptr_phoneNumber = &phoneNumber;
    char *ptr_address = &address;

    // add the information to the new account created

    printf("\n Name: ");
    scanf("%s", ptr_name);
    printf("%s", ptr_name);

    printf("\n Phone Number: ");
    scanf("%d", ptr_phoneNumber);
    printf("%d", *ptr_phoneNumber);

    printf("\n Address: ");
    scanf("%s", ptr_address);
    printf("%s", ptr_address);

    // store the information in the new account struct

    printf("\n Parsing the information into the new account... \n");

    new_account.name = ptr_name;
    new_account.phoneNumber = *ptr_phoneNumber;
    new_account.address = ptr_address;

    new_account.balance = 0;
    new_account.debt = 0;
    new_account.spent = 0;

    printf("New Account created: %s(#%d) \n", new_account.name, new_account.phoneNumber);
  }

// a conditional statement to find the right function for their option
// e.g 1 -> new_account();
void menu_opts_init(int c_opt)
{
    switch(*&c_opt)
    {   
        case 0:
            tv_menu(options);
            break;
        case 1:
            new_account();
            break;
        

    }
}

// toggle view menu
int tv_menu(char options[7][20]) {
  for (register int i = 0; i < 6; i++)
    printf("\n Option %d: %s", i, options[i]);

  printf(
      "\n \n What would you like to do? \n Pick an option by their number: ");
  int c_opt; // chosen option integer
  scanf("%d", &c_opt);
  printf("\n You've chosen: %s \n", options[*&c_opt]);

  menu_opts_init(c_opt);

  return *&c_opt;
}

// menu intialization
void menu_init() {
  printf("Welcome to Bank of Atmora \n");

  const int c_opt = tv_menu(options);
}

// void function of me practising pointers, memory address, allocating memory &
// managing time function filled with memory junk experiments
void mem_junk_init() {
  const int value = 100;
  const int *avalue = &value;

  printf("\n value: %d", *avalue);
  printf("\n address of value: %p", avalue);

  int *arrval;
  arrval = (int *)malloc(sizeof(int));
  *arrval = 500;

  int *array;
  array = malloc(*arrval * sizeof(int));

  int total = 0;
  int *ptr = &total;
  for (int i = 0; i < *arrval; i++) {
    array[i] = i + 1;
    printf("\n %d", array[i]);
    *ptr = *ptr + 1;
  }
  free(arrval);
  free(array);

  printf("\n total: %d", *ptr);

  const char *name = "Create a New Account";
  printf("\n size of memory allocated: %ld", sizeof(name));
}

// Execution time: 0.000128 seconds
void ptr_benchmark()
{
  int i = 5;
  int* ptr = &i;
  printf("\n %d", *ptr);
}

// Execution time: 0.000035 seconds
void int_benchmark()
{
  int i = 5;
  printf("\n %d", i);
}

// main function
int main(int argc, char const *argv[]) {
  clock_t start, end;

  double cpu_time_used;

  start = clock();

  // code to measure

  menu_init();

    // mem_junk_init();
    // ptr_benchmark();
    // int_benchmark();

  end = clock();

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Execution time: %f seconds\n", cpu_time_used);

  return 0;
}
