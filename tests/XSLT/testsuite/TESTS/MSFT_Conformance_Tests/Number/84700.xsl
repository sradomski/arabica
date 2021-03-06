<?xml version="1.0"?> 
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output encoding="UTF-16"/>

<!-- XSLT: Number formatting - format= "&#x0031;" (Arabic)- & = "&#x0023;" (Arabic alphabetic) -->
<!-- "&#xff11;" (Arabic double byte) - letter-value="alphabetic" | "traditional" -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/05/2000 -->

<xsl:template match="/">  
	<TABLE>  
		<xsl:for-each select="//ضصثقفغ">  
			<TR><TD>  
				<TD>
					<!-- Arabic alphabetic|traditional -->
					<xsl:number format="&#x0623;" letter-value="alphabetic" /> -
					<xsl:number format="&#x0623;" letter-value="traditional" /> - 
					
					<!-- Arabic Double byte -->
					<xsl:number format="&#xff11;" letter-value="alphabetic" /> - 

					<!-- Arabic -->			
					<xsl:number format="&#x0031;" letter-value="traditional" /> - 
					<xsl:value-of select = "text()"/>										
				</TD>
			</TD></TR>  
		</xsl:for-each>  
	</TABLE>  
</xsl:template>  

</xsl:stylesheet>  
