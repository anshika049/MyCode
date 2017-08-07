package com.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.Dao.tshirtDao;
import com.dto.tshirtDTO;


 @WebServlet("/tshirtServlet")
 public class tshirtServlet extends HttpServlet
  {
	 protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	 {
		 request.getParameter("type");
		 
		 HttpSession session=request.getSession();
		 
		 ArrayList<tshirtDTO>  arrayList=null;
		 tshirtDao tshirtdao=new tshirtDao();
		 try {
			arrayList=tshirtdao.getT_Shirt();
			
	PrintWriter printWriter=response.getWriter();
	
		   
			
			session.setAttribute("arrayList",arrayList );
			printWriter.print(arrayList);
			response.setContentType("text/html");	
		} catch (ClassNotFoundException e) {
		} catch (SQLException e) {
			
			e.printStackTrace();
		} 
		 
     }
		

}
