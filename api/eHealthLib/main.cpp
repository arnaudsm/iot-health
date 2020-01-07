#include <iostream>
#include <pqxx/pqxx>
#include <eHealth.h>
#include <unistd.h>

using namespace std;
using namespace pqxx;



int main(int argc, char* argv[]) {
    eHealthClass eHealth();

    eHealth->initBloodPressureSensor();
    eHealth->initPulsioximeter();

    while(true) {
       int airFlow = eHealth->getAirFlow();
       int electroCardio = eHealth->getECG();
       float pulsio = eHealth->getECG();

       insertIntoDb(airFlow, electroCardio, pulsio);

       sleep(10000);
    }
}

void insertIntoDb(int airFlow, int electroCardio, float pulsio) {
    std::string sql;

   try {
      connection C("dbname = testdb user = postgres password = password \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
      }

      /* Create SQL statement */
       sql = "INSERT INTO api_point (sensor_id, value) VALUES (1," + airFlow + "); ";
       sql = "INSERT INTO api_point (sensor_id, value) VALUES (2," + electroCardio + "); ";
       sql = "INSERT INTO api_point (sensor_id, value) VALUES (3," + pulsio + "); ";

      /* Create a transactional object. */
      work W(C);

      /* Execute SQL query */
      W.exec( sql );
      W.commit();
      cout << "Records created successfully" << endl;
      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
   }

    C.disconnect ();
}

