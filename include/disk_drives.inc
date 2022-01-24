[Variables]
Drive1=C
Drive2=D
Drive3=E
Drive1Label=SYSTEM
Drive2Label=STORAGE
Drive3Label=BACKUP
logocolor=255,255,255,255
fillcolor=255,80,0,255
ASSETS=#@#images\
DiskDrives_X=0
DiskDrives_Y=0

[DiskDrivesBackground]
Meter=IMAGE
SolidColor=0, 0, 0, 1
ImageName=#@#images\background.png
ScaleMargins=6,6,6,6
ImageAlpha=1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 100][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 1][!UpdateMeter #CURRENTSECTION#][!Redraw]
W=300
H=140
X=#DiskDrives_X#
Y=#DiskDrives_Y#

[DiskDrivesBottomLine]
Meter=IMAGE
X=(10+#DiskDrives_X#)
Y=(130+#DiskDrives_Y#)
W=280
H=1
SolidColor=255, 255, 255, 50

Measures
------------------------------------
[MeasureCDISK]
Measure=FreeDiskSpace
Drive=#Drive1#:
InvertMeasure=1

[MeasureDDISK]
Measure=FreeDiskSpace
Drive=#Drive2#:
InvertMeasure=1

[MeasureEDISK]
Measure=FreeDiskSpace
Drive=#Drive3#:
InvertMeasure=1

[MeterCBar]
Meter=Bar
MeasureName=MeasureCDISK
X=(15+#DiskDrives_X#)
Y=(14+#DiskDrives_Y#)
W=6
H=80
BarColor=#fillcolor#
SolidColor=255,255,255,255

[MeterDBar]
Meter=Bar
MeasureName=MeasureDDISK
X=(115+#DiskDrives_X#)
Y=(14+#DiskDrives_Y#)
W=6
H=80
BarColor=#fillcolor#
SolidColor=255,255,255,255

[MeterEBar]
Meter=Bar
MeasureName=MeasureEDISK
X=(215+#DiskDrives_X#)
Y=(14+#DiskDrives_Y#)
W=6
H=80
BarColor=#fillcolor#
SolidColor=255,255,255,255

Buttons
-----------------------------------
[MeterbuttonCDISK]
Meter=BUTTON
X=(25+#DiskDrives_X#)
Y=(10+#DiskDrives_Y#)
SolidColor=0,0,0,1
ButtonImage=#ASSETS#C_DISK.png
LeftMouseDownAction=!Execute ["C:\"]

[MeterlabelCDISK]
Meter=STRING
X=(10+#DiskDrives_X#)
Y=(94+#DiskDrives_Y#)
FontColor=#logocolor#
StringStyle=BOLD
FontSize=12
StringAlign=LEFT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Prefix="#Drive1Label#"

[MeterbuttonDDISK]
Meter=BUTTON
X=(125+#DiskDrives_X#)
Y=(10+#DiskDrives_Y#)
SolidColor=0,0,0,1
ButtonImage=#ASSETS#D_DISK.png
LeftMouseDownAction=!Execute ["D:\"]

[MeterlabelDDISK]
Meter=STRING
X=(110+#DiskDrives_X#)
Y=(94+#DiskDrives_Y#)
FontColor=#logocolor#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Prefix="#Drive2Label#"

[MeterbuttonEDISK]
Meter=BUTTON
X=(225+#DiskDrives_X#)
Y=(10+#DiskDrives_Y#)
SolidColor=0,0,0,1
ButtonImage=#ASSETS#E_DISK.png
LeftMouseDownAction=!Execute ["E:\"]

[MeterlabelEDISK]
Meter=STRING
X=(210+#DiskDrives_X#)
Y=(94+#DiskDrives_Y#)
FontColor=#logocolor#
StringStyle=NORMAL
FontSize=12
StringAlign=LEFT
FontFace=Helvetica Neue LT Std
AntiAlias=1
Hidden=0
Prefix="#Drive3Label#"
