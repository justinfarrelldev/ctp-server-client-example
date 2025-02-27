#include "create_account.h"
#include <curl/curl.h>
#include <json-c/json.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Creates a new account by sending a POST request to the server.
 *
 * This function initializes a CURL session, constructs a JSON object with the
 * provided account details, and sends a POST request to the specified server
 * endpoint to create a new account.
 *
 * Note that the params below are all present within the Call to Power
 * multiplayer user dialogs.
 *
 * @param email The email address of the new account.
 * @param experience_level The experience level of the user.
 * @param info Additional information about the user.
 * @param location The location of the user.
 * @param name The name of the user.
 * @param password The password for the new account.
 */
void create_account(const char *email, int experience_level, const char *info,
                    const char *location, const char *name,
                    const char *password) {
  CURL *curl = NULL;
  struct curl_slist *headers = NULL;
  struct json_object *json_obj = NULL;
  struct json_object *account_obj = NULL;
  CURLcode res;

  // Initialize curl
  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  if (!curl) {
    fprintf(stderr, "Failed to initialize CURL\n");
    goto cleanup;
  }

  // Create JSON structure
  json_obj = json_object_new_object();
  account_obj = json_object_new_object();
  if (!json_obj || !account_obj) {
    fprintf(stderr, "Failed to create JSON objects\n");
    goto cleanup;
  }

  // Build account object
  json_object_object_add(account_obj, "email", json_object_new_string(email));
  json_object_object_add(account_obj, "experience_level",
                         json_object_new_int(experience_level));
  json_object_object_add(account_obj, "info", json_object_new_string(info));
  json_object_object_add(account_obj, "location",
                         json_object_new_string(location));
  json_object_object_add(account_obj, "name", json_object_new_string(name));

  // Build main object
  json_object_object_add(json_obj, "account", account_obj);
  json_object_object_add(json_obj, "password",
                         json_object_new_string(password));

  // Setup headers
  headers = curl_slist_append(headers, "Content-Type: application/json");
  if (!headers) {
    fprintf(stderr, "Failed to create headers\n");
    goto cleanup;
  }

  // Setup CURL options
  curl_easy_setopt(curl, CURLOPT_URL,
                   "https://open-ctp-server.fly.dev/account/create_account");
  curl_easy_setopt(curl, CURLOPT_POST, 1L);
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS,
                   json_object_to_json_string(json_obj));
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

  // Perform request
  res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(res));
  }

cleanup:
  if (headers)
    curl_slist_free_all(headers);
  if (json_obj)
    json_object_put(json_obj);
  if (curl)
    curl_easy_cleanup(curl);
  curl_global_cleanup();
}
