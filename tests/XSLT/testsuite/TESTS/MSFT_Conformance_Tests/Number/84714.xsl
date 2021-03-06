<?xml version="1.0"?> 
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output encoding="UTF-16"/>

<!-- XSLT - Numbering - format="&#x05d0;" (Hindi Consonants: &#x0905; - Vowels: &#x0905; - Numbers: &#x0905;) - letter-value="alphabetic" | "traditional" -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/11/2000 -->

<xsl:template match="/">  
	<TABLE>  
		<xsl:for-each select="//रळफओइ">
			<TR><TD>  
				<TD>
					<!-- Hindi Consonants -->
					<xsl:number format="&#x0915;" letter-value="alphabetic" /> -
					<xsl:value-of select = "text()"/>							
				</TD>

				<TD>
					<!-- Hindi Vowels -->
					<xsl:number format="&#x0905;" letter-value="traditional" /> -
					<xsl:value-of select = "text()"/>							
				</TD>

				<TD>
					<!-- Hindi Numbers -->
					<xsl:number format="&#x0967;" letter-value="alphabetic" /> -
					<xsl:value-of select = "text()"/>							
				</TD>

			</TD></TR>  
		</xsl:for-each>  
	</TABLE>  
</xsl:template>  

</xsl:stylesheet>  
