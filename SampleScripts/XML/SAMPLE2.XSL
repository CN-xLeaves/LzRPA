<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="html"/>
    <xsl:param name="param1"/>
  <xsl:template match="/">
        Hello
  </xsl:template>
  <xsl:template match="/" mode="edit">
        In Edit Mode
  </xsl:template>
  <xsl:template match="/" mode="view">
        In View Mode
  </xsl:template>
</xsl:stylesheet>
