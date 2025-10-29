<?php
// Thiết lập encoding UTF-8
header('Content-Type: text/html; charset=UTF-8');
mb_internal_encoding('UTF-8');

$serverName = "localhost\\SQLEXPRESS"; 
$connectionOptions = array(
    "Database" => "TrainBookingSystem", 
    "Uid" => "sa",                      
    "PWD" => "26122005",
    "CharacterSet" => "UTF-8"
);

$conn = sqlsrv_connect($serverName, $connectionOptions);

if ($conn === false) {
    die(print_r(sqlsrv_errors(), true));
}

// Thiết lập encoding cho SQL Server
sqlsrv_query($conn, "SET NAMES 'utf8'");
?>
