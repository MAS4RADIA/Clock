
  #include <gtk/gtk.h>
  #include <X11/Xlib.h>
  #include <gdk/x11/gdkx.h>

  #include "./Globals.h"
  #include "./Back/Clock.h"
  #include "./Front/Clock.h"

  int main (void)
      {
         int status;
         GtkApplication *dig_clock;

         dig_clock = gtk_application_new ("mas4.digital.clock", G_APPLICATION_DEFAULT_FLAGS);
         g_signal_connect (dig_clock, "activate", G_CALLBACK (Digital), NULL);
         status = g_application_run (G_APPLICATION (dig_clock), 0, NULL);
         g_object_unref (dig_clock);

         return (status);
       }