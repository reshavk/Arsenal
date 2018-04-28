<?xml version = "1.0"?>
<xsl:stylesheet version="1.1" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match ="/">

<html>
<body>
<h3>Books</h3>
<table border = "2">
    <tr bgcolor = "lightgray">
        <th>Book Id</th>
        <th>Title</th>
        <th>Author</th>
        <th>Price</th>
        <th>Year</th>
    </tr>
    <xsl:for-each select="catalog/book">
        <tr>
            <td><xsl:value-of select = "@id"/></td>
            <td><xsl:value-of select = "title"/></td>
            <td><xsl:value-of select = "author"/></td>
            <td><xsl:value-of select = "price"/></td>
            <td><xsl:value-of select = "year"/></td>
        </tr>
    </xsl:for-each>
</table>
</body>
</html>
</xsl:template> 
</xsl:stylesheet>