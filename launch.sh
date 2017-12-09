#!/bin/zsh

make; 

PORT=$1

./rt_server void.xml -p $PORT &;
SERVER=$!

sleep 1;

./rt_client 127.0.0.1 $PORT &;

wait $SERVER
killall rt_client
