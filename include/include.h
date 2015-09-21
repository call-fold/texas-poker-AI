#ifndef INCLUDE_H
#define INCLUDE_H

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char ac_2[];
extern char ac_3[];
extern char ac_4[];
extern char ac_5[];
extern int steps;			/* Data_init */
extern int ac; 
extern int error;
extern int money;
extern char my_id_s[10];

extern char color[7][10];
extern char point[7][10];
extern char bet[7][10];
extern int pointInt[7][1];
extern int betInt[7];
extern int betInt_max;
extern int m;
extern int member_count;

extern void Data_init();
extern void bet_Data_init();
extern int my_money(char *s);
extern void inquire_explain(char *s);
extern void card_explain(char *s);
extern int hold_strategy_1();
extern int hold_strategy_2();
extern int strategy();

#endif