
  #ifndef __MAS4_DIGITAL_CLOCK_FRONT_V_02__
  #define __MAS4_DIGITAL_CLOCK_FRONT_V_02__

  void Digital (GtkApplication *clock)
      {
         GtkWidget *board, *frame;

         board = gtk_application_window_new (clock);
         gtk_window_set_decorated (GTK_WINDOW (board), FALSE);
         gtk_window_set_resizable (GTK_WINDOW (board), FALSE);
         gtk_window_set_default_size (GTK_WINDOW (board), 100, 30);

         frame = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
         hour = gtk_label_new (" HH :");
         minute = gtk_label_new (" MM ");
         period = gtk_label_new (" AM ");

         g_idle_add ((GSourceFunc) DigitalTime, NULL);

         gtk_box_append (GTK_BOX (frame), hour);
         gtk_box_append (GTK_BOX (frame), minute);
         gtk_box_append (GTK_BOX (frame), period);
         gtk_window_set_child (GTK_WINDOW (board), frame);

         gtk_widget_show (board);
       }

  #endif