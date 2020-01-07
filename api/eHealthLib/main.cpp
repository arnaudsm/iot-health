#include <iostream>
#include <pqxx/pqxx>
#include <eHealth.h>
#include <unistd.h>

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {
    eHealthClass eHealth();
    eHealth->initPulsioximeter();

    while(true) {
        int oxy = eHealth->getOxygenSaturation();
        int bpm = eHealth->getBPM();
        cout << "Oxy: " << oxy << endl;
        cout << "BPM: " << bpm << endl;
        sleep(2000);
    }
}

int utils() {
    eHealthClass eHealth();

    eHealth->initBloodPressureSensor();
    eHealth->initPulsioximeter();

    while(true) {
       int airFlow = eHealth->getAirFlow();
       int electroCardio = eHealth->getECG();
       int oxy = eHealth->getOxygenSaturation();
       int bpm = eHealth->getBPM();

       insertIntoDb(airFlow, electroCardio, oxy, bpm);

       sleep(10000);
    }
}

void insertIntoDb(int airFlow, int electroCardio, int oxy, int bpm) {
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
       sql1 = "INSERT INTO api_point (sensor_id, value) VALUES (1," + airFlow + "); ";
       sql2 = "INSERT INTO api_point (sensor_id, value) VALUES (2," + electroCardio + "); ";
       sql3 = "INSERT INTO api_point (sensor_id, value) VALUES (3," + oxy + "); ";
       sql4 = "INSERT INTO api_point (sensor_id, value) VALUES (4," + bpm + "); ";

      /* Create a transactional object. */
      work W(C);
      /* Execute SQL query */
      W.exec( sql1 );
      W.commit();

      work W(C);
      /* Execute SQL query */
      W.exec( sql2 );
      W.commit();

      work W(C);
      /* Execute SQL query */
      W.exec( sql3 );
      W.commit();

      work W(C);
      /* Execute SQL query */
      W.exec( sql4 );
      W.commit();

      cout << "Records created successfully" << endl;
      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
   }

    C.disconnect ();
}

