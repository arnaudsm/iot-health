#include <iostream>

#include <stdio.h>
#include <curl/curl.h>

using namespace std;

int main(int argc, char* argv[]) {
    for (i=0; i<=10; i=i+1) {
        CURL *curl;
        CURLcode res;

        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        if(curl)
        {
            int res = 0;
            snprintf(curl_url, sizeof(curl_url), "http://localhost/api/post", results);
            snprintf(curl_fields, sizeof(curl_fields),"{\"sensor_id\":\"%d\", \"value\":\"%d\"}", 1, i);


            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Accept: application/json");
            headers = curl_slist_append(headers, "Content-Type: application/json");
            headers = curl_slist_append(headers, "charsets: utf-8");

            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_URL, curl_url);
            curl_easy_setopt(curl, CURLOPT_POST, 1);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, curl_fields);

            res = curl_easy_perform(curl);

            curl_easy_cleanup(curl);
            curl_global_cleanup();
        }
    }
}
