#include "create_account.h"
#include <gtk/gtk.h>

void on_create_account_clicked(GtkWidget *widget, gpointer data) {
  GtkWidget *dialog, *content_area;
  GtkWidget *grid;
  GtkWidget *email_label, *info_label, *location_label, *name_label,
      *password_label, *experience_label;
  GtkWidget *email_entry, *info_entry, *location_entry, *name_entry,
      *password_entry;
  GtkWidget *experience_combo;
  GtkDialogFlags flags = GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT;

  dialog = gtk_dialog_new_with_buttons("Create Account", GTK_WINDOW(data),
                                       flags, ("_OK"), GTK_RESPONSE_OK,
                                       ("_Cancel"), GTK_RESPONSE_CANCEL, NULL);

  content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
  grid = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);

  email_label = gtk_label_new("Email:");
  info_label = gtk_label_new("Info:");
  location_label = gtk_label_new("Location:");
  name_label = gtk_label_new("Name:");
  password_label = gtk_label_new("Password:");
  experience_label = gtk_label_new("Experience Level:");

  email_entry = gtk_entry_new();
  info_entry = gtk_entry_new();
  location_entry = gtk_entry_new();
  name_entry = gtk_entry_new();
  password_entry = gtk_entry_new();
  gtk_entry_set_visibility(GTK_ENTRY(password_entry), FALSE);

  experience_combo = gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(experience_combo),
                                 "Beginner");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(experience_combo), "Easy");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(experience_combo),
                                 "Medium");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(experience_combo), "Hard");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(experience_combo),
                                 "Very Hard");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(experience_combo),
                                 "Impossible");

  gtk_grid_attach(GTK_GRID(grid), email_label, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), email_entry, 1, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), info_label, 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), info_entry, 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), location_label, 0, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), location_entry, 1, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), name_label, 0, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), password_label, 0, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), password_entry, 1, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), experience_label, 0, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), experience_combo, 1, 5, 1, 1);

  gtk_container_add(GTK_CONTAINER(content_area), grid);
  gtk_widget_show_all(dialog);

  gint result = gtk_dialog_run(GTK_DIALOG(dialog));

  if (result == GTK_RESPONSE_OK) {
    g_print("Create Account OK clicked\n");

    const char *email = gtk_entry_get_text(GTK_ENTRY(email_entry));
    const char *info = gtk_entry_get_text(GTK_ENTRY(info_entry));
    const char *location = gtk_entry_get_text(GTK_ENTRY(location_entry));
    const char *name = gtk_entry_get_text(GTK_ENTRY(name_entry));
    const char *password = gtk_entry_get_text(GTK_ENTRY(password_entry));
    int experience_level =
        gtk_combo_box_get_active(GTK_COMBO_BOX(experience_combo));

    create_account(email, experience_level, info, location, name, password);
  } else {
    g_print("Create Account Cancel clicked\n");
  }

  gtk_widget_destroy(dialog);
}
