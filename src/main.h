#pragma once 

struct Transaction
{
    int fromId;
    int toId;

    int amount;
    int fromBalance;
};

struct Account
{
    /* data */
    int id;
    char name[24];
    int balance; // grand total balance
    int debt; // how much they owe
    int spent; // how much they spent
    
    int phoneNumber;
    char* address;
};

char options[7][20];
void new_account();
void menu_opts_init(int c_opt);
int tv_menu(char options[7][20]);
void menu_init();
void mem_junk_init();