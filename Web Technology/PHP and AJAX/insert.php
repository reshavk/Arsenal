<?php
require_once 'dbconnect.php';

if(isset($_POST['submit'])) {
	$eid = trim($_POST['eid']);
	$ename = trim($_POST['ename']);
	$epost = trim($_POST['epos']);
	$esal = trim($_POST['esal']);

	$sql = "insert into employee_details values('$eid', '$ename', '$epost', '$esal')";

	$query = mysqli_query($conn, $sql);

	if($query) {
		echo "<script>
		alert('Employee record sucessfully inserted');
		window.location.href='index.html';
		</script>";
	}
	else {
		echo "<script>
		alert('Employee record update failed');
		window.location.href='index.html';
		</script>";
	}
}

?>