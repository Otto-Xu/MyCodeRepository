#!/bin/bash
#检测WiFi连接，打印所连接的WiFi的SSID

wifi_test()
{
	while(true)
	do
		ret=$(iwgetid)
	
		if [ ! "$ret" ]
		then
			echo `date +"%F %H:%M:%S"` "WiFi Connection Failure And Try to Reconnect" | tee -a wifi_log.txt
		else
			echo `date +"%F %H:%M:%S"` $(iwgetid) "connection succeeded" | tee -a wifi_log.txt
		fi

		sleep 2
	done
}

wifi_test
