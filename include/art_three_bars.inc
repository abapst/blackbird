[Variables]
art_three_bars_X=0
art_three_bars_Y=0

[ArtThreeBarsBackground]
Meter=IMAGE
SolidColor=0, 0, 0, 1
ImageName=#@#images\background.png
ScaleMargins=6,6,6,6
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=300
H=140
X=#art_three_bars_X#
Y=#art_three_bars_Y#

[ArtThreeBarsBottomLine]
Meter=IMAGE
X=(10+#art_three_bars_X#)
Y=(130+#art_three_bars_Y#)
W=280
H=1
SolidColor=255, 255, 255, 50

[MeterLine1]
Meter=IMAGE
X=(0+#art_three_bars_X#)
Y=(30+#art_three_bars_Y#)
W=300
H=25
SolidColor=#AccentColor4#

[MeterLine2]
Meter=IMAGE
X=(0+#art_three_bars_X#)
Y=(65+#art_three_bars_Y#)
W=300
H=25
SolidColor=255, 255, 255, 200

[MeterLine3]
Meter=IMAGE
X=(0+#art_three_bars_X#)
Y=(100+#art_three_bars_Y#)
W=300
H=25
SolidColor=255, 255, 255, 150
