<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<title>Registration</title>
</head>
<body>
	<h1 align="center">WELCOME TO STUDENT INFORMATION DASHBOARD</h1>
	<h2 align="center">Register yourself</h2>
	<br><br>
	<fieldset>
		<legend>Fill your details</legend>
		<div align="center">
			<form action="register" method="POST">
				<label>*Username : </label>
				<input type="text" name="uname" placeholder="Enter your name">
				<br><br>
				<label>*Password : </label>
				<input type="Password" name="upwd" placeholder="Enter your password">
				<br><br>
				<label>*Confirm Password : </label>
				<input type="Password" name="ucpwd" placeholder="Enter your password">
				<br><br>
				<label>*Firstname : </label>
				<input type="text" name="fname" placeholder="Enter your firstname">
				<br><br>
				<label>*Mobile no. : </label>
				<input type="text" name="umobile" placeholder="Enter your mobile no.">
				<br><br>
				<input type="submit" name="submit" value="Submit">
				<input type="reset" name="reset" value="Reset">
				<br><br>
			</form>
		</div>
	</fieldset>

</body>
</html>