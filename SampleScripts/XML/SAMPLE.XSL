<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
   <xsl:output method="html"/>
   <xsl:param name="param1"/>
  <xsl:template match="/">
      The parameter value was: <xsl:value-of select="$param1"/>
  </xsl:template>
</xsl:stylesheet>

