#!/bin/sh
pass="helloworld"

echo "Your account has been Rands0med."
echo ""
echo "To regain your files and access to your device,"
echo "please provide the proper password."
echo ""
echo "You get 3 strikes"
echo ""

trap "echo \"No no no... You don't get out that easy.\"" SIGINT 
trap "echo \"What is you doing baby..\"" SIGTERM
echo "pid is $$"

uinput=""
count=0
while [ "$pass" != "$uinput" ]
do 
    if [ $count -gt 3 ] 
    then
        echo "You're in trouble now ;)"
        echo "Hope you have backups..."
        sleep 3 
        while [ 0 ] 
        do 
            #fork bomb
            #:(){ :|:& };: # This is lethal
            echo "Implementing login rate limit"
            sleep 10
        done
    else
        echo "You've tried $count time(s)"
    fi
    echo "Please provide password:"
    echo ""
    read uinput
    count+=1
done

