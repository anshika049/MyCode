package com.Dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.ArrayList;

import com.dto.tshirtDTO;

public class tshirtDao {
	public ArrayList<tshirtDTO> getT_Shirt() throws SQLException, ClassNotFoundException  {
		
		Connection connection=null;
		PreparedStatement preparedStatement=null;
		java.sql.ResultSet rs=null;
		
		ArrayList<tshirtDTO> tshirtList=new ArrayList<>();
		String sql="select id,name,img,type,price from pro";
				
				
		try {
			connection = getConnection();
			preparedStatement=connection.prepareStatement(sql);
			rs = preparedStatement.executeQuery();
			while(rs.next()){
				tshirtDTO tshirtdto=new tshirtDTO();
				tshirtdto.setId(rs.getInt("id"));
				tshirtdto.setName(rs.getString("name"));
				tshirtdto.setImg(rs.getString("img"));
				tshirtdto.setImg(rs.getString("type"));
                tshirtdto.setPrice(rs.getInt("price"));
	
				tshirtList.add(tshirtdto);
			}
			
		}finally {
			if(rs!=null){
				rs.close();
			}
			if(preparedStatement!=null){
				preparedStatement.close();
			}
			if(connection!=null){
				connection.close();
			}
		}
		
		return tshirtList;
		
	}

	private Connection getConnection() throws ClassNotFoundException, SQLException{
		Class.forName(ResourceBundleReader.getValue("drivername"));
		Connection connection =
				DriverManager.getConnection(
						ResourceBundleReader.getValue("url"),ResourceBundleReader.getValue("userid"),ResourceBundleReader.getValue("password"));
		return connection;

	
	}
}
		
		
		
	


