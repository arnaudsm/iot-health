# IOT Health Platform

# Dependencies
- `docker` and `docker-compose`

# Start server 
Run `docker-compose -f ./docker-compose-dev.yml up -d` on the main folder

Clear cache with : `docker-compose -f ./docker-compose-dev.yml up -d --build --force-recreate`

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
