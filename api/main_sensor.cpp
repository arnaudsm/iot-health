#include <iostream>
#include <unistd.h>
#include <curl/curl.h>
#include <string>

#include "eHealth.h"

using namespace std;

void sendBdd(float val) {
	CURL *curl;
          CURLcode res;

          /* In windows, this will init the winsock stuff */
          curl_global_init(CURL_GLOBAL_ALL);

          /*CU get a curl handle */
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

	    string s = "sensor_id=" + std::to_string(3) + "&value=" + std::to_string(val);

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
	//int airflow = eHealth.getAirFlow();
	float temp = eHealth.getTemperature();
	sendBdd(temp);
	cout << temp;
        usleep(100000);
	
    }
}


