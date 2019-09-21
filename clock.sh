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
