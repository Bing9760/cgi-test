<%@ page language="java" contentType="text/html;charset=gb2312"%>
<%@page import="java.io/*"%>
<html>
<head>
<meta charset="utf-8">
<title>无标题文档</title>
</head>

<body>
<center>
<%
	String path = request.getRealPath("/");
	File fp = new File(path,"AjaxSentMsg.ini");
	FileWriter fwriter = new FileWriter(fp);
	request.setCharacterEncoding("GBK");
	String str_file = request.getParameter("textarea");
	fwriter.write(str_file);
	fwriter.close();
	out.println("write done!";)
%>
</center>
</body>
</html>
