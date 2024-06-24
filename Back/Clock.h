
  #ifndef __MAS4_DIGITAL_CLOCK_BACK_V_02__
  #define __MAS4_DIGITAL_CLOCK_BACK_V_02__
  struct tm *previous;

  gboolean DigitalTime ()
      {
         time_t raw;
         struct tm *formatted;
         char *f_hour, *f_min;

         raw = time (NULL);
         if (raw < 1 || !GTK_IS_WIDGET (hour) || !GTK_IS_WIDGET (minute) || !GTK_IS_WIDGET (period))
             {  return (FALSE);  }
         formatted = localtime (&raw);

         f_hour = malloc (sizeof (char) * 10);
         f_min = malloc (sizeof (char) * 10);

         if (formatted->tm_hour > 12)
             {
                formatted->tm_hour -= 12;
                gtk_label_set_text (GTK_LABEL (period), " PM ");
              }

          sprintf (f_hour, " %d :", formatted->tm_hour);
          sprintf (f_min, " %d ", formatted->tm_min);
          if (formatted->tm_hour < 10)
              {  sprintf (f_hour, " 0%d :", formatted->tm_hour);  }
          if (formatted->tm_min < 10)
              {  sprintf (f_min, " 0%d ", formatted->tm_min);  }

          gtk_label_set_text (GTK_LABEL (hour), f_hour);
          gtk_label_set_text (GTK_LABEL (minute), f_min);

          sleep (1);

          return (TRUE);
       }

  #endif