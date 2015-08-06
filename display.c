#include "mycalc.h"


void change_display(GtkWidget *a, gpointer  b)
{
	char tmp[4];
	sprintf(tmp,"%s",(gchar *)b);
	strcat(display_string,tmp);
	gtk_entry_set_text((GtkEntry *)disp,display_string);
}
void remove_display(GtkWidget *a, gpointer  b)
{
	display_string[0]='\0';
	gtk_entry_set_text((GtkEntry *)disp,display_string);
}
void remove_last_display(GtkWidget *a, gpointer  b)
{
	display_string[strlen(display_string)-1]='\0';
	gtk_entry_set_text((GtkEntry *)disp,display_string);
}
GtkWidget* new_button(int i)
{
	char ip[2];
	sprintf(ip,"%d",i);
	
	
	
	GtkWidget *button=gtk_button_new_with_label(ip);
	switch(i)
	{
		case 1:
			g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"1");
			break;
		case 2:
			g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"2");
			break;
		case 3:
			g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"3");
			break;
		case 4:
			g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"4");
			break;
		case 5:
			g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"5");
			break;
		case 6:
			g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"6");
			break;
		case 7:
			g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"7");
			break;
		case 8:
			g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"8");
			break;
		case 9:
			g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"9");
			break;
		case 0:
			g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"0");
			break;
	}
	return (GtkWidget *)button;
}

void create_display()
{
	//gtk_init(&argc,&argv);
	
	display_string[0]='\0';
	
	GtkWidget *window,*button,*box,*panel,*line;
	
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Amrutansu's Calculator");
	gtk_window_set_default_size(GTK_WINDOW(window),450,450);
	g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	
	
	box=gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
	//display=gtk_label_new();
	
	//add label
	panel=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
	
	
	//FIRST LINE IN BUTTON PANEL
	line=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	for(int i=9;i>6;i--)
	{
		button=new_button(i);
		//char temp[4];
		//sprintf(temp,"%d",i);
		gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
		gtk_widget_show(button);
	}
	button=gtk_button_new_with_label("+");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"+");
	gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
	gtk_widget_show(button);
	gtk_box_pack_start((GtkBox *)panel,line,TRUE,TRUE,5);
	gtk_widget_show(line);
	
	
	
	
	
	//SECOND LINE IN BUTTON PANEL
	line=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	for(int i=6;i>3;i--)
	{
		button=new_button(i);
		gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
		gtk_widget_show(button);
	}
	button=gtk_button_new_with_label("-");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"-");
	gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
	gtk_widget_show(button);
	gtk_box_pack_start((GtkBox *)panel,line,TRUE,TRUE,5);
	gtk_widget_show(line);
	
	
	
	//THIRD LINE IN BUTTON PANEL
	line=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	for(int i=3;i>0;i--)
	{
		button=new_button(i);
		gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
		gtk_widget_show(button);
	}
	button=gtk_button_new_with_label("*");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"*");
	gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
	gtk_widget_show(button);
	gtk_box_pack_start((GtkBox *)panel,line,TRUE,TRUE,5);
	gtk_widget_show(line);
	
	
	//FOURTH LINE IN BUTTON PANEL
	line=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	
	button=new_button(0);
	gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
	gtk_widget_show(button);
	button=gtk_button_new_with_label(".");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)".");
	gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
	gtk_widget_show(button);
	button=gtk_button_new_with_label("<-");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(remove_last_display),NULL); //Change
	gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
	gtk_widget_show(button);
	button=gtk_button_new_with_label("/");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"/");
	gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
	gtk_widget_show(button);
	gtk_box_pack_start((GtkBox *)panel,line,TRUE,TRUE,5);
	gtk_widget_show(line);
	
	
	
	//FIFTH LINE IN BUTTON PANEL
	line=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	
	button=gtk_button_new_with_label("(");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)"(");
	gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
	gtk_widget_show(button);
	button=gtk_button_new_with_label(")");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_display),(gpointer)")");
	gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
	gtk_widget_show(button);
	button=gtk_button_new_with_label("clr");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(remove_display),NULL);
	gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,3);
	gtk_widget_show(button);
	button=gtk_button_new_with_label("=");
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(solve),NULL);
	gtk_box_pack_start((GtkBox *)line,button,TRUE,TRUE,5);
	gtk_widget_show(button);
	gtk_box_pack_start((GtkBox *)panel,line,TRUE,TRUE,5);
	gtk_widget_show(line);
	
	
	disp=gtk_entry_new();
	gtk_entry_set_text((GtkEntry *)disp,display_string);
	
	
	gtk_box_pack_start((GtkBox *)box,disp,TRUE,TRUE,5);
	gtk_widget_show(disp);
	gtk_box_pack_start((GtkBox *)box,panel,TRUE,TRUE,5);
	gtk_widget_show(panel);
	
	
	gtk_container_add(GTK_CONTAINER(window),box);
	gtk_widget_show(box);
	gtk_widget_show(window);
	gtk_main();
}
