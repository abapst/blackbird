[Background]
Meter=IMAGE
SolidColor=0, 0, 0, 1
ImageName=#@#images\background.png
ScaleMargins=6,6,6,6
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=300
H=140

[BottomLine]
Meter=IMAGE
X=10
Y=130
W=280
H=1
SolidColor=255, 255, 255, 50

[MeterLine1]
Meter=IMAGE
X=0
Y=30
W=300
H=25
SolidColor=255, 255, 255, 255

[MeterLine2]
Meter=IMAGE
X=0
Y=65
W=300
H=25
SolidColor=255, 255, 255, 200

[MeterLine3]
Meter=IMAGE
X=0
Y=100
W=300
H=25
SolidColor=255, 255, 255, 150
