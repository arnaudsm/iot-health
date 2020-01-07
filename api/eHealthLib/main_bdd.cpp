#include <iostream>

#include <CkHttpRequest.h>
#include <CkJsonObject.h>
#include <CkJsonArray.h>

using namespace std;

int main(int argc, char* argv[]) {
    for (i=0; i<=10; i=i+1) {
        CkHttpRequest req;

        req.put_HttpVerb("POST");
        req.put_Path("localhost/api/post/");
        req.put_ContentType("application/json");

        req.AddHeader("Accept","application/json");

        CkJsonObject json;
        json.AppendString("sensor_id", 1);
        json.AppendString("value", i);
        req.LoadBodyFromString(json.emit(),"utf-8");
    }
}
