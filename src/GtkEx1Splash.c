/*
 ============================================================================
 Name        : screensplash.c
 Author      : Alex Monteiro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in GTK+
 ============================================================================

$apt-get install libgtk2.0-dev
 */

#include <gtk-2.0/gtk/gtk.h>

/* Close the splash screen */
gboolean close_screen(gpointer data)
{
  gtk_widget_destroy((GtkWidget*)data);
  gtk_main_quit ();
  return(FALSE);
}


int Show_Splash_Screen(char* image_name,int time,int width,int height)
{
  GtkWidget  *image, *window;
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (window, width, height);
  gtk_window_set_decorated(GTK_WINDOW (window), FALSE);
  gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER_ALWAYS);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  image=gtk_image_new_from_file(image_name);
  gtk_container_add(GTK_CONTAINER(window), image);
  gtk_widget_show_all (window);
  g_timeout_add (time, close_screen, window);
  gtk_main ();
  return 0;
}


 int main (int argc, char *argv[])
 {
    GtkWidget *window;
    GtkWidget *label;

    gtk_init (&argc, &argv);

    /* create the main, top level, window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* give it the title */
    gtk_window_set_title (GTK_WINDOW (window), "Hello World");

    /* Connect the destroy signal of the window to gtk_main_quit
     * When the window is about to be destroyed we get a notification and
     * stop the main GTK+ loop
     */
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    /* Create the "Hello, World" label  */
    label = gtk_label_new ("Hello, World");

    /* and insert it into the main window  */
    gtk_container_add (GTK_CONTAINER (window), label);

    Show_Splash_Screen("praia-do-forte-praia.jpg",3000,727,481);

    /* make sure that everything, window and label, are visible */
    gtk_widget_show_all (window);

    /* start the main loop, and let it rest there until the application is closed */
    gtk_main ();

    return 0;
 }
