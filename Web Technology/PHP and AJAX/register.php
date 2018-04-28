<?php
require_once 'dbconnect.php';

if(isset($_POST['submit'])) {
	$username = trim($_POST['uname']);
	$password = trim($_POST['upwd']);
	$firstname = trim($_POST['fname']);
	$lastname = trim($_POST['sname']);
	$gender = trim($_POSt['gender']);
	$email = trim($_POST['uemail']);
	$course = trim($_POST['ucourse']);
	$mobileno = trim($_POST['umno']);

	$sql = "insert into students values{'$username', '$password', '$firstname', '$lastname', '$gender', '$email', '$course', '$mobileno'}";

	$query = mysqli_query($conn, $sql);

	if($query) {
		echo "<script>alert('Registration successful')</script>";
	}
	else {
		echo "<script>alert('Failed ! Registration failed with some error.')</script>";
	}
}
?>

<!DOCTYPE html>
<html>
<head>
	<title>Registration Form</title>
</head>
<body>
	<h1>STUDENT REGISTRATION FORM</h1>
	<form name="stdreg" action="" method="post">
	<fieldset>
	<legend>Fill the following details</legend>
	<div style="margin-left: 40%">
		<label>Username : </label>
		<input type="text" name="uname" placeholder="Enter your username">
		<br><br>
		<label>Password : </label>
		<input type="Password" name="upwd" placeholder="Enter your password">
		<br><br>
		<label>Firstname : </label>
		<input type="text" name="fname" placeholder="Enter your Firstname">
		<br><br>
		<label>Secondname : </label>
		<input type="text" name="sname" placeholder="Enter your Secondname">
		<br><br>
		<label>Gender : </label>
		<input type="radio" name="gender" value="Male">Male
		<input type="radio" name="gender" value="Female">Female
		<br><br>
		<label>E-Mail : </label>
		<input type="text" name="uemail" placeholder="Enter your email-id">
		<br><br>
		<label>Course : </label>
		<select name="ucourse">
			<option>Select Class </option>
			<option>SE COMP</option>
			<option>TE COMP</option>
			<option>BE COMP</option>
		</select>
		<br><br>
		<label>Mobile No. : </label>
		<input type="text" name="umno" placeholder="Enter you mobile number">
		<br><br>
		<input style="margin-left: 5%" type="submit" value="Submit" onclick="validate()">
		<input style="margin-left: 5%" align="center" type="reset" value="Reset">
		<br><br>
	</div>
	</fieldset>
	</form>

</body>
</html>