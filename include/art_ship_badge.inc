[Variables]
HFlogo=#@#images\ship_badge.png
logocolor=255,255,255,255

[Background]
Meter=IMAGE
SolidColor=0, 0, 0, 1
ImageName=#@#images\background.png
ScaleMargins=6,6,6,6
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=300
H=280

[BottomLine]
Meter=IMAGE
X=10
Y=270
W=280
H=1
SolidColor=255, 255, 255, 50

[MeterBadgeLogo]
Meter=Image
ImageName=#HFlogo#
W=170
H=170
X=65
Y=55
GreyScale=1
ImageTint=#logocolor#

[MeterBadgeRoundLine]
Meter=ROUNDLINE
X=35
Y=25
W=230
H=230
LineWidth=7.0
LineLength=95
LineStart=90
StartAngle=47.55
RotationAngle=6.29
AntiAlias=1
LineColor=255, 255, 255, 255
Solid=1