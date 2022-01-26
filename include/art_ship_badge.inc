[Variables]
HFlogo=#@#images\ship_badge.png
LaurelImg=#@#images\laurel.png
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
W=100
H=100
X=(100+#art_ship_badge_X#)
Y=(80+#art_ship_badge_Y#)
GreyScale=1
ImageTint=#AccentColor4#

[MeterBadgeRoundLine]
Meter=ROUNDLINE
X=(60+#art_ship_badge_X#)
Y=(40+#art_ship_badge_Y#)
W=180
H=180
LineWidth=7.0
LineLength=61
LineStart=56
StartAngle=47.55
RotationAngle=6.29
AntiAlias=1
LineColor=#AccentColor4#
Solid=1

[MeterBadgeLaurelLogo]
Meter=Image
ImageName=#LaurelImg#
W=190
H=166
X=(54+#art_ship_badge_X#)
Y=(50+#art_ship_badge_Y#)
GreyScale=1
ImageTint=#AccentColor4#
