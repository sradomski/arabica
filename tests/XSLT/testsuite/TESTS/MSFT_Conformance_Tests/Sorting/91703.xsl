<?xml version="1.0" encoding="iso-8859-1"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:output method="xml" encoding="iso-8859-1" indent="yes" omit-xml-declaration="yes"/>


	<xsl:template match="/">
            <xsl:for-each select="sorting/data">
                <xsl:sort case-order="something"/>
                <xsl:value-of select="."/><xsl:text>, </xsl:text>
            </xsl:for-each>
	</xsl:template>

</xsl:stylesheet>