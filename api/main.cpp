#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <curl/curl.h>

#include "eHealth.h"

using namespace std;

void insertIntoDbInt(int value, int sensor_id) {
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
      //headers = curl_slist_append(headers, "Accept: application/json");
      //headers = curl_slist_append(headers, "Content-type: application/json");
      headers = curl_slist_append(headers, "charsets: utf-8");

      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
      curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/api/post/");

      /* Now specify the POST data */
      string s = "sensor_id=" + std::to_string(sensor_id) + "&value=" + std::to_string(value);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, s.c_str());

      /* Perform the request, res will get the return code */
      res = curl_easy_perform(curl);

      cout << res << endl;
      /* always cleanup */
      curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

void insertIntoDbFloat(float value, int sensor_id) {
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
      //headers = curl_slist_append(headers, "Accept: application/json");
      //headers = curl_slist_append(headers, "Content-type: application/json");
      headers = curl_slist_append(headers, "charsets: utf-8");

      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
      curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/api/post/");

      /* Now specify the POST data */
      string s = "sensor_id=" + std::to_string(sensor_id) + "&value=" + std::to_string(value);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, s.c_str());

      /* Perform the request, res will get the return code */
      res = curl_easy_perform(curl);

      cout << res << endl;
      /* always cleanup */
      curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main(int argc, char* argv[]) {
    eHealthClass eHealthClass();

    while(true) {
       int airFlow = eHealth.getAirFlow();
       int electroCardio = eHealth.getECG();
       float temperature = eHealth.getTemperature();

       insertIntoDbInt(airFlow, 1);
       insertIntoDbInt(electroCardio, 2);
       insertIntoDbFloat(temperature, 3);
       // wait for 0.1 sec
       usleep(1000000);
    }
}



