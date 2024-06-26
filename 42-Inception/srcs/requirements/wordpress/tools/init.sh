#!/bin/bash

WP_CONFIG_FILE="/var/www/html/wordpress/wp-config.php"
WP_CONFIG_SAMPLE="/var/www/html/wordpress/wp-config-sample.php"
WP_CLI_URL="https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar"

if ! [[ -f /var/www/html/wordpress/wp-config.php ]]; then

    curl -o /usr/local/bin/wp $WP_CLI_URL
    chmod +x /usr/local/bin/wp

    cp $WP_CONFIG_SAMPLE $WP_CONFIG_FILE

    sed -i "s/password_here/$MARIA_DB_PASS/g" $WP_CONFIG_FILE
    sed -i "s/localhost/mariadb/g" $WP_CONFIG_FILE
    sed -i "s/username_here/$MARIA_DB_USER/g" $WP_CONFIG_FILE
    sed -i "s/database_name_here/$MARIA_DB_NAME/g" $WP_CONFIG_FILE

    wp core install --allow-root --url=$URL --title=$MARIA_DB_USER --admin_user=$MARIA_DB_USER --admin_password=$MARIA_DB_PASS --admin_email=$WP_EMAIL --path=/var/www/html/wordpress/
    wp user create $WP_USER $WP_EMAIL2 --user_pass=$WP_PASS --role=author --allow-root --path=/var/www/html/wordpress/
else
    echo "wp-config.php exists. Skipping installation..."
fi

/usr/sbin/php-fpm7.4 -y /etc/php/7.4/fpm/php-fpm.conf -F