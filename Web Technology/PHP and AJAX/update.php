<?php
require_once 'dbconnect.php';

if(isset($_POST['submit'])) {
	$eid = trim($_POST['eid']);
	$ename = trim($_POST['ename']);
	$epos = trim($_POST['epos']);
	$esal = trim($_POST['esal']);

	$sql = "update employee_details set ename = '$ename', epost = '$epos', esal = '$esal' where eid = '$eid'";

	$query = mysqli_query($conn, $sql);

	if($query) {
		echo "<script>
		alert('Record updated sucessfully');
		window.location.href='index.html';
		</script>";
	}
	else {
		echo "<script>
		alert('Failed to update record');
		window.location.href='index.html';
		</script>";
	}
}

?>