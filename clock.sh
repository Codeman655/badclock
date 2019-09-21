#! /bin/bash 
# /usr/local/bin/clock.sh 
#
 
function d_start ( ) 
{ 
    echo  "Clock: starting service" 
	/usr/local/bin/clock
}
 
function d_status ( ) 
{ 
    echo  "Current competition time is $(date): $(date +%s)" 
}

function d_stop ( ) 
{ 
    echo  "Deluge: stopping Service (PID = $(ps aux | grep clock | awk '{print $2}') " 
	for pid in $(ps aux | grep clock | awk '{print $2}'); do
		kill $pid
	done
 }
 
# Management instructions of the service 
case "$ 1"  in 
    start )
        d_start
        ;; 
    stop )
        ;; 
    reload )
        ;; 
    status )
        d_status
        ;; 
    * ) 
    echo  "Usage: $ 0 {start | stop | reload | status}" 
    exit  1 
    ;; 
esac
 
exit  0
