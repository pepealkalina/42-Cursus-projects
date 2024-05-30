FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y nginx openssl -y

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=SP/ST=Malaga/L=Malaga/O=42 Malaga/OU=preina-g/CN=preina-g" -keyout /etc/nginx/ssl/preina-g.key -out /etc/nginx/ssl/preina-g.crt

COPY tools/default /etc/nginx/sites-available/default

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]