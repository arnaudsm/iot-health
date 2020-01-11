# IOT Health Platform

# Dependencies
- `docker` and `docker-compose`

# Start server 
Run `docker-compose up -d` on the main folder

Clear cache with : `docker-compose up -d --build --force-recreate`  

`docker exec -it web sh` to create a terminal inside

# Contributors
 - [Arnaud de Saint Meloir](https://arnaud.at)
 - Marianne Strassburger
 - Luc Couvreux
 - Pol de Font-Réaulx

# Database structure 
table api_point
- time (type time automatique)
- sensor_id (type int)
- value (type réel)
