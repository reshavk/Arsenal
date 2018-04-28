<?php
require_once 'dbconnect.php';

$eid = $_REQUEST['id'];

$sql = "select * from employee_details where eid = '$eid'";

$result = mysqli_query($conn, $sql);

if(mysqli_num_rows($result) > 0) {
	while($row = mysqli_fetch_assoc($result)) {
		echo "<br><fieldset><legend>Employee Details</legend>Employee name : ".$row['ename']."<br><br>Employee Position : ".$row['epost']."<br><br>Employee Salary : ".$row['esal']."<br><br></fieldset>";
	}
}
else {
	echo "<br><fieldset>No such employee exists</fieldset>";
}

?>