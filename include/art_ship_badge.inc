[Variables]
HFlogo=#@#images\ship_badge.png
art_ship_badge_X=0
art_ship_badge_Y=0

[ArtShipBadgeBackground]
Meter=IMAGE
SolidColor=0, 0, 0, 1
ImageName=#@#images\background.png
ScaleMargins=6,6,6,6
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=300
H=280
X=#art_ship_badge_X#
Y=#art_ship_badge_Y#

[ArtShipBadgeBottomLine]
Meter=IMAGE
X=(10+#art_ship_badge_X#)
Y=(270+#art_ship_badge_Y#)
W=280
H=1
SolidColor=255, 255, 255, 50

[MeterBadgeLogo]
Meter=Image
ImageName=#HFlogo#
W=170
H=170
X=(65+#art_ship_badge_X#)
Y=(55+#art_ship_badge_Y#)
GreyScale=1
ImageTint=#AccentColor4#

[MeterBadgeRoundLine]
Meter=ROUNDLINE
X=(35+#art_ship_badge_X#)
Y=(25+#art_ship_badge_Y#)
W=230
H=230
LineWidth=7.0
LineLength=95
LineStart=90
StartAngle=47.55
RotationAngle=6.29
AntiAlias=1
LineColor=#AccentColor4#
Solid=1