#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include<math.h>

#define MAX_LIM 1000

char display_string[MAX_LIM];
void create_display();
void solve();
int get_precedence(char);
int isop(char);
long double solution(long double,long double,char);

GtkWidget *disp;
