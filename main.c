#include <gtk/gtk.h>
extern void on_create_account_clicked(GtkWidget *widget, gpointer data);

/**
 * create_buttons:
 * @window: a pointer to the GtkWidget representing the main application window.
 *
 * This function creates a "Create Account" button and a label with a message
 * indicating that the login functionality is under development. It adds them
 * to the provided window and connects the "clicked" signal of the button to
 * its respective callback function, `on_create_account_clicked`.
 */
void create_buttons(GtkWidget *window) {
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_container_add(GTK_CONTAINER(window), box);
  GtkWidget *create_account_button =
      gtk_button_new_with_label("Create Account");
  GtkWidget *login_label = gtk_label_new(
      "\n\n"
      "The login functionality is currently under development. "
      "Account creation is fully operational. \nThis example illustrates "
      "how to interface with the server using C. \nLobbies, sessions, and "
      "authentication logic are nearing completion, with the login endpoint "
      "and session refreshing logic still in progress.");

  g_signal_connect(create_account_button, "clicked",
                   G_CALLBACK(on_create_account_clicked), window);

  gtk_container_add(GTK_CONTAINER(box), create_account_button);
  gtk_container_add(GTK_CONTAINER(box), login_label);
}

/**
 * @brief Activates the GTK application and creates the main window.
 *
 * This function is called when the GTK application is activated. It creates a
 * new application window, sets its title, and adjusts its default size to 25%
 * of the screen's width and height. Finally, it displays the window.
 *
 * @param app A pointer to the GtkApplication instance.
 * @param user_data A pointer to user data, which is cast to a char* and printed
 * to prevent clang-tidy errors.
 */
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

  create_buttons(window);

  gtk_widget_show_all(window);
  printf("%s", (char *)user_data); // This is here to prevent clang-tidy errors
}

int main(int argc, char **argv) {
  GtkApplication *app =
      gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  return status;
}
