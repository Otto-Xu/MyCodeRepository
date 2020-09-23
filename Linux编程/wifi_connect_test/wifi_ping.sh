#!/bin/bash
#检测WiFi连接，打印已分配的IP地址

while(true)
do
	ping -c 1 114.114.114.114 > /dev/null 2>&1
	
	if [ $? -eq 0 ]
	then
		CMD=`ifconfig wlan0 | grep -o -E "inet [0-9.]+"`
		echo `date +"%F %H:%M:%S"` $CMD | tee -a wifi_log.txt
	else
		echo `date +"%F %H:%M:%S"` "WiFi Connection Failure and Try to Reconnect" | tee -a wifi_log.txt
	fi

	sleep 2
done
