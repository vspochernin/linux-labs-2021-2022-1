#!/bin/bash
echo "*************************"
select opt in apache named sendmail
do
	case $opt in
		apache) /etc/rc.d/init.d/httpd restart;;
		named) /etc/rc.d/init.d/named restart;;
		sendmail) /etc/rc.d/init.d/sendmail restart;;
		*) echo "Ничего не будет перезапущено"
	esac
	echo "*************************"
# Если здесь не поставить "break", тогда мы не выйдем в процессор после выбора.
	break
done
