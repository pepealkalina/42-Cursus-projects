#!/bin/bash



# mysql -sfu root < "mysql_secure_installation.sql"

echo "CREATE DATABASE ${MARIA_DB_NAME};" > init.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIA_DB_ROOT_PASS}';" >> init.sql
echo "CREATE USER '${MARIA_DB_USER}'@'%' IDENTIFIED BY '${MARIA_DB_PASS}';" >> init.sql
echo "GRANT ALL PRIVILEGES ON *.* TO '${MARIA_DB_USER}'@'%';" >> init.sql
echo "FLUSH PRIVILEGES;" >> init.sql

chmod 777 init.sql
mv init.sql /run/mysqld/init.sql
chown -R mysql:root /var/run/mysqld

pkill -f mysqld

tail -f

mariadbd --init-file /run/mysqld/init.sql
