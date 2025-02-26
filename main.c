#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Window");
  GdkRectangle workarea = {0};
  gdk_monitor_get_workarea(
      gdk_display_get_primary_monitor(gdk_display_get_default()), &workarea);

  gint screen_width = workarea.width;
  gint screen_height = workarea.height;
  gtk_window_set_default_size(GTK_WINDOW(window), screen_width * 0.25,
                              screen_height * 0.25);
  gtk_widget_show_all(window);
  printf("%s",
         (char *)user_data); // This is here to prevent clang-tidy errors
}

int main(int argc, char **argv) {
  GtkApplication *app =
      gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  return status;
}
