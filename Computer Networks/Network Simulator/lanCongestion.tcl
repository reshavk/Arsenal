set ns [new Simulator]

$ns color 1 Blue

set file1 [open out.tr w]
$ns trace-all $file1

set file2 [open out.nam w]
$ns namtrace-all $file2

proc finish {} {
	global ns file1 file2
	$ns flush-trace
	close $file1
	close $file2
	exec nam out.nam &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 2Mb 10ms DropTail

$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right

set lan [$ns newLan "$n3 $n4 $n5" 0.5Mb 40ms LL Queue/DropTail MAC/CSMA/Cd Channel]

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

$ns at 0.1 "$ftp start"
$ns at 124.5 "$ftp stop"

proc plotting {tcpsource file3} {
	global ns
	set congs [$tcpsource set cwnd_]
	set now [$ns now]
	puts $file3 "$now $congs"
	$ns at [expr $now+0.1] "plotting $tcpsource $file3"
}

set print [open lan.xg w]
$ns at 1.0 "plotting $tcp $print"

$ns at 125.0 "finish"

$ns run

