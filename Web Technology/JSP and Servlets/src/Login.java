

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class Login
 */
public class Login extends HttpServlet {
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
		System.out.println(uname+ "\n"+ upwd);
		
		Boolean flag = false;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/wtpracs", "root", "root");
			PreparedStatement ps = con.prepareStatement("select * from stud_record where username = ? and password = ?");
			ps.setString(1, uname);
			ps.setString(2, upwd);
			
			ResultSet rs = ps.executeQuery();
			flag = rs.next();
			if(flag) {
				HttpSession session = request.getSession();
				session.setAttribute("unm", uname);
				RequestDispatcher rd = request.getRequestDispatcher("home.jsp");
				rd.forward(request, response);
			}
			else {
				out.println("Authentication failed !\nMake sure you are registered");
				RequestDispatcher rd = request.getRequestDispatcher("login.jsp");
				rd.include(request, response);
			}
		}
		catch(Exception e) {
			System.out.println(e);
		}
		
		
	}

}
    
