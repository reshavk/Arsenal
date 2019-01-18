<?php
require_once 'dbconnect.php';

if(isset($_POST['submit'])) {
	$eid = trim($_POST['eid']);

	$sql = "select * from employee_details where eid = '$eid'";

	$result = mysqli_query($conn, $sql);

	if(mysqli_num_rows($result) > 0) {
		while($row = mysqli_fetch_assoc($result)) {
			echo "Employee name : ".$row['ename']."<br><br>Employee Position : ".$row['epost']."<br><br>Employee Salary : ".$row['esal']."<br><br>";
		}
	}
	else {
		echo "<script>
		alert('No such employee exists');
		window.location.href='index.html';
		</script>";
	}
}

?>