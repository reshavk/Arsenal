<?php
require_once 'dbconnect.php';

if(isset($_POST['submit'])) {
	$eid = trim($_POST['eid']);

	$sql = "delete from employee_details where eid = '$eid'";

	$query = mysqli_query($conn, $sql);

	if($query) {
		echo "<script>
		alert('Record deleted sucessfully');
		window.location.href='index.html';
		</script>";
	}
	else {
		echo "<script>
		alert('Failed to delete record');
		window.location.href='index.html';
		</script>";
	}
}

?>