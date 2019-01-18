

import java.io.*;
import java.sql.*;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Register
 */
public class Register extends HttpServlet {
	private static final long serialVersionUID = 1L;
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		String uname = request.getParameter("uname");
		String upwd = request.getParameter("upwd");
		String fname = request.getParameter("fname");
		String mobile = request.getParameter("umobile");
		
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/wtpracs", "root", "root");
			PreparedStatement ps = con.prepareStatement("insert into stud_record values(?, ?, ?, ?)");
			ps.setString(1, uname);
			ps.setString(2, upwd);
			ps.setString(3, fname);
			ps.setString(4, mobile);
			
			int i = ps.executeUpdate();
			if(i > 0) {
				out.println("Registration Successful");
				out.println("<a href= 'login.jsp'>Click here for login</a>");
			}
			else {
				out.println("Registration failed !");
			}
			
		}
		catch(Exception e) {
			System.out.println(e);
		}
		
	}

}
