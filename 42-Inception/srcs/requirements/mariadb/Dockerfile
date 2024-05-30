FROM debian:bullseye

RUN apt update && apt upgrade -y
RUN apt install -y mariadb-server

RUN mkdir -p /var/run/mysqld \
&& chown -R mysql:mysql /var/run/mysqld \
&& chmod 777 /var/run/mysqld


COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
RUN chmod 644 /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/init.sh /

RUN service mariadb start

RUN chmod +x /init.sh

EXPOSE 3306

CMD ["/init.sh"]
