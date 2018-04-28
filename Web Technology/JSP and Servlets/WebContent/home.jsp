<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" import="java.sql.*" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<title>Home</title>
	<script type="text/javascript">
		function showDetails() {
			var x = document.getElementById('details');
			if(x.style.display == 'none')
				x.style.display = 'block';
			else
				x.style.display = 'none';
		}
	</script>
</head>
<body>
<%
if(session.getAttribute("unm") == null)
	response.sendRedirect("login.jsp");
String uname = request.getParameter("uname");
String upwd = request.getParameter("upwd");
Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/wtpracs","root","root");
PreparedStatement ps = con.prepareStatement("select * from stud_record where username = ? and password = ?");
ps.setString(1, uname);
ps.setString(2, upwd);
ResultSet rs = ps.executeQuery();
%>
	<h1 align="center">STUDENT INFORMATION PORTAL</h1>
	<fieldset>
		<legend>Choose Operation</legend>
		<div align="center">
			<button style="width: 20%; height: 40px" onclick="showDetails()" >View Details</button>
		</div>
	</fieldset>
	<br><br>
	
	<div id = 'details' style="display:none">
		<fieldset>
			<legend>Your details</legend>
			<div align="center">
			<%while(rs.next()) { %>
			<label>User name : </label>
			<%=rs.getString(1) %><br><br>
			<label>First name : </label>
			<%=rs.getString(3) %><br><br>
			<label>Mobile No. : </label>
			<%=rs.getString(4) %><br><br>
			<%} %>
			</div>
		</fieldset>
	</div>
	
</body>
</html>