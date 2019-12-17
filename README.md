# IOT Health Platform

# Dependencies
- `docker` and `docker-compose`

# Start server 
Run `docker-compose -f ./docker-compose-dev.yml up` on the main folder

Clear cache with : `docker-compose -f ./docker-compose-dev.yml up -d --build --force-recreate`  

`docker exec -it web sh` to create a terminal inside

# Contributors
 - [Arnaud de Saint Meloir](https://arnaud.at)
 - Marianne Strassburger
 - Luc Couvreux
 - Pol de Font-Réaulx

# Database structure 
table : data

columns:
- epoch (int)
- capteur_1 (float)
- capteur_2 (float)
- capteur_3 (float)
