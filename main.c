#include<stdio.h>
#include<gtk/gtk.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include"Fonction.h"
GtkBuilder *builder;


//declation de la fenetre menu principale et ces bouttons
GtkWidget *window1;
GtkWidget *button1;
GtkWidget *button2;
GtkWidget *button3;
GtkWidget *button4;





//declation de la Location d'une voitures et ces bouttons
GtkWidget *window2;
GtkWidget *button5;
GtkWidget *button6;
GtkWidget *button7;
GtkWidget *button8;
GtkWidget *button9;
GtkWidget *button10;


//declation de Gestion des voitures et ces bouttons
GtkWidget *window3;
GtkWidget *button11;
GtkWidget *button12;
GtkWidget *button13;
GtkWidget *button14;
GtkWidget *button15;



//declation de Gestion des clients et ces bouttons
GtkWidget *window4;
GtkWidget *button16;
GtkWidget *button17;
GtkWidget *button18;
GtkWidget *button19;
GtkWidget *button20;



void reteur2(){
new_window();
gtk_widget_destroy(window2);
}

void reteur3(){
new_window();
gtk_widget_destroy(window3);
}
void reteur4(){
new_window();
gtk_widget_destroy(window4);
}

void print(){
printf("bonjour");}

void quitte(){
    g_signal_connect(G_OBJECT(window1), "destroy",G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_destroy(window1);
}

void New_window2(GtkWidget *widget,gpointer data){
//creation de la fenetre 2 (Location d'une voitures)

builder=gtk_builder_new_from_file("projet.glade");
window2=gtk_builder_get_object(builder,"window2");
button5=gtk_builder_get_object(builder,"button5");
button6=gtk_builder_get_object(builder,"button6");
button7=gtk_builder_get_object(builder,"button7");
button8=gtk_builder_get_object(builder,"button8");
button9=gtk_builder_get_object(builder,"button9");
button10=gtk_builder_get_object(builder,"button10");


g_signal_connect(button5,"clicked",G_CALLBACK(Visualiser_Contrat),NULL);
g_signal_connect(button6,"clicked",G_CALLBACK(Louer_Voiture),NULL);
g_signal_connect(button7,"clicked",G_CALLBACK(Retourner_Voiture),NULL);
g_signal_connect(button8,"clicked",G_CALLBACK(Modifier_Contrat),NULL);
g_signal_connect(button9,"clicked",G_CALLBACK(Supprimer_Contrat),NULL);


 g_signal_connect (button10, "clicked", G_CALLBACK (reteur2), NULL);

    gtk_widget_destroy(window1);

gtk_widget_show_all(window2);
}





void New_window3(GtkWidget *widget,gpointer data){
//creation de la fenetre 3 (Gestion des voiture)

builder=gtk_builder_new_from_file("projet.glade");
window3=gtk_builder_get_object(builder,"window3");
button11=gtk_builder_get_object(builder,"button11");
button12=gtk_builder_get_object(builder,"button12");
button13=gtk_builder_get_object(builder,"button13");
button14=gtk_builder_get_object(builder,"button14");
button15=gtk_builder_get_object(builder,"button15");

g_signal_connect(button11,"clicked",G_CALLBACK(Lister_voitures),NULL);
g_signal_connect(button12,"clicked",G_CALLBACK(Ajouter_voiture),NULL);
g_signal_connect(button13,"clicked",G_CALLBACK(Modifier_Voiture),NULL);
g_signal_connect(button14,"clicked",G_CALLBACK(Supprimer_Voiture),NULL);

 g_signal_connect (button15, "clicked", G_CALLBACK (reteur3), NULL);

    gtk_widget_destroy(window1);

gtk_widget_show_all(window3);

}










void New_window4(GtkWidget *widget,gpointer data){
//creation de la fenetre 4(Gestion des clients)





builder=gtk_builder_new_from_file("projet.glade");
window4=GTK_WIDGET(gtk_builder_get_object(builder,"window4"));
button16=GTK_WIDGET(gtk_builder_get_object(builder,"button16"));
button17=GTK_WIDGET(gtk_builder_get_object(builder,"button17"));
button18=GTK_WIDGET(gtk_builder_get_object(builder,"button18"));
button19=GTK_WIDGET(gtk_builder_get_object(builder,"button19"));
button20=GTK_WIDGET(gtk_builder_get_object(builder,"button20"));

g_signal_connect(button16,"clicked",G_CALLBACK(Liste_Clients),NULL);
g_signal_connect(button17,"clicked",G_CALLBACK(Ajouter_Client),NULL);
g_signal_connect(button18,"clicked",G_CALLBACK(Modifier_Client),NULL);
g_signal_connect(button19,"clicked",G_CALLBACK(Supprimer_client),NULL);


 g_signal_connect (button20, "clicked", G_CALLBACK (reteur4), NULL);

    gtk_widget_destroy(window1);



gtk_widget_show_all(window4);

}
//creation de la premiere fenetre (Menu principal)

void new_window(){


builder=gtk_builder_new_from_file("projet.glade");
window1=gtk_builder_get_object(builder,"window1");
button1=gtk_builder_get_object(builder,"button1");
button2=gtk_builder_get_object(builder,"button2");
button3=gtk_builder_get_object(builder,"button3");
button4=gtk_builder_get_object(builder,"button4");



g_signal_connect(button1,"clicked",G_CALLBACK(New_window2)  ,NULL);
g_signal_connect(button2,"clicked",G_CALLBACK(New_window3)  ,NULL);
g_signal_connect(button3,"clicked",G_CALLBACK(New_window4)  ,NULL);

 g_signal_connect (button4, "clicked", G_CALLBACK (quitte), NULL);

gtk_widget_show_all(window1);
}








int main(int argc,char **argv){

gtk_init(&argc,&argv);

builder=gtk_builder_new_from_file("projet.glade");

new_window();

gtk_main();

return 0;
}
