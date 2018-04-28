<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<title>Login</title>
</head>
<body>
	<h1 align="center">WELCOME TO STUDENT INFORMATION PORTAL</h1>
	<h3 align="center">Login to portal</h3>
	<fieldset>
		<legend>Enter your credentials</legend>
		<form action="login" method="POST">
			<div align="center">
				<label>Username : </label>
				<input type="text" name="uname" placeholder="Enter you username">
				<br><br>
				<label>Password : </label>
				<input type="text" name="upwd" placeholder="Enter you password">
				<br><br>
				<input type="submit" name="submit" value="Submit">
				<br><br>
				<label>First time here !</label><br>
				<a href="register.jsp">Click here to register</a>
			</div>
		</form>
	</fieldset>


</body>
</html>