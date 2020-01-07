#include <iostream>

#include <stdio.h>
#include <curl/curl.h>

using namespace std;

int main(int argc, char* argv[]) {
    int i;
    for (i=0; i<=10; i=i+1) {
        CURL *curl;
        CURLcode res;

        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        if(curl)
        {
            int res = 0;

            curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/api/post");
            /* Now specify the POST data */
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"sensor_id\":" + 1 + ", \"value\":" + i + "}");


            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Accept: application/json");
            headers = curl_slist_append(headers, "Content-Type: application/json");
            headers = curl_slist_append(headers, "charsets: utf-8");

            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_URL, curl_url);
            curl_easy_setopt(curl, CURLOPT_POST, 1);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, curl_fields);

            res = curl_easy_perform(curl);

            cout << res;

            curl_easy_cleanup(curl);
            curl_global_cleanup();
        }
    }
}
