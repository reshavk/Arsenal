<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="/WEB-INF/struts-html.tld" prefix="html" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <style>
         body {
    margin: 0;
    padding: 0;
    text-align: center;
    font-family:"Adobe Garamond Pro Bold", Georgia, "Times New Roman", Times, serif;
    font-size: 13px;
    color: #061C37;
    background: yellow;
}
.contentbox{
background-color:white;
border : 5px solid green;
position: absolute;
top: 200px;
right:550px;
}
        </style>
    </head>
    <body >
        <div style="color:red">
            <html:errors />
        </div>
        <div class="contentbox">
        <html:form action="/Login" >
            User Name : <html:text name="LoginForm" property="userName" /> <br>
            Password  : <html:password name="LoginForm" property="password" /> <br>
            <html:submit value="Login" />
        </html:form>
        </div>
    </body>
</html>
