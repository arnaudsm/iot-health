#include <iostream>

#include <stdio.h>
#include <curl/curl.h>

using namespace std;

int main(int argc, char* argv[]) {
    int i;
    for (i=0; i<=10; i=i+1) {
          CURL *curl;
          CURLcode res;

          /* In windows, this will init the winsock stuff */
          curl_global_init(CURL_GLOBAL_ALL);

          /* get a curl handle */
          curl = curl_easy_init();
          if(curl) {
            /* First set the URL that is about to receive our POST. This URL can
               just as well be a https:// URL if that is what should receive the
               data. */
            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Accept: application/json");
            headers = curl_slist_append(headers, "Content-Type: application/json");
            headers = curl_slist_append(headers, "charsets: utf-8");

            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/api/post/");
            /* Now specify the POST data */
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"sensor_id\":" + std::to_string(1) + ", \"value\":" + std::to_string(i) + "}");

            /* Perform the request, res will get the return code */
            res = curl_easy_perform(curl);

            cout << res;
            /* always cleanup */
            curl_easy_cleanup(curl);
          }
          curl_global_cleanup();
    }
}
